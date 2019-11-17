using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.Threading;
using System.Text.RegularExpressions;
using System.IO;
using System.Linq;

namespace HTTPServer
{
	class Client
	{
		static long prev = 0;
		private void SendError(TcpClient Client, int Code)
		{
			string CodeStr = Code.ToString() + " " + ((HttpStatusCode)Code).ToString();
			string Html = "<html><body><h1>" + CodeStr + "</h1></body></html>";
			string Str = "HTTP/1.1 " + CodeStr + "\nContent-type: text/html\nContent-Length:" + Html.Length.ToString() + "\n\n" + Html;
			byte[] Buffer = Encoding.ASCII.GetBytes(Str);
			Client.GetStream().Write(Buffer, 0, Buffer.Length);
			Client.Close();
		}

		public Client(TcpClient Client)
		{
			string Request = "";
			byte[] Buffer = new byte[1024];
			int Count;
			while ((Count = Client.GetStream().Read(Buffer, 0, Buffer.Length)) > 0)
			{
				Request += Encoding.ASCII.GetString(Buffer, 0, Count);
				// запит має закінчуватись на \r\n\r\n
				if (Request.IndexOf("\r\n\r\n") >= 0 || Request.Length > 4096)
				{
					break;
				}
			}
			// шукаємо в стрічці запит користувача
			Match ReqMatch = Regex.Match(Request, @"^\w+\s+([^\s\?]+)[^\s]*\s+HTTP/.*|");

			if (ReqMatch == Match.Empty)
			{
				SendError(Client, 400);
				return;
			}

			string RequestUri = ReqMatch.Groups[1].Value;

			RequestUri = Uri.UnescapeDataString(RequestUri);

			// захист від хакерських атак
			if (RequestUri.IndexOf("..") >= 0)
			{
				SendError(Client, 400);
				return;
			}
			string filename = Directory.GetCurrentDirectory() + "\\" + "data.csv";

			if (RequestUri.EndsWith("/") || RequestUri == "")
			{
				var stream = new MemoryStream();
				try
				{
					string data = "";
					if (File.Exists(filename))
					{
						data += "<!DOCTYPE html>";
						data += "<html>";
						List<long> l = File.ReadAllText(filename).Split(',').Select((stringValue) =>
						{
							try
							{
								long parsed = int.Parse(stringValue);
								return parsed;
							}
							catch (Exception) { return 0; }
						}).Where(x => (x + "").Length > 0 && x != 0).ToList();
						l.Sort();
						l.Reverse();
						int i = 0;
						data += l.Select(x => (((++i) > 3) ? "<div>" : "<div><b>") + x + ((i > 3) ? "</div>" : "</b></div>")).Aggregate("", (prev, curr) => prev + curr);
						data += "</html>";
					}
					var writer = new StreamWriter(stream);
					writer.Write(data);
					writer.Flush();
					stream.Position = 0;

					string Headers = "HTTP/1.1 200 OK\nContent-Type: " + "text/html" + "\nContent-Length: " + stream.Length + "\n\n";
					byte[] HeadersBuffer = Encoding.ASCII.GetBytes(Headers);
					Client.GetStream().Write(HeadersBuffer, 0, HeadersBuffer.Length);

					while (stream.Position < stream.Length)
					{
						Count = stream.Read(Buffer, 0, Buffer.Length);
						Client.GetStream().Write(Buffer, 0, Count);
					}
					Console.WriteLine("sent");
				}
				catch (Exception e) { Console.WriteLine("error " + e.ToString()); }
				stream.Close();
				Client.Close();
			}
			else
			{
				try
				{
					string newValue = RequestUri.Replace("/", "");
					long newIntValue = Int32.Parse(newValue);
					if (newIntValue != prev)
					{
						prev = newIntValue;
						File.AppendAllText((filename), newIntValue + ",");
						Console.WriteLine("added new " + RequestUri.Replace("/", ""));
					}
				}
				catch (Exception e) { Console.WriteLine("error " + e.ToString()); }
				Client.Close();
				return;
			}

		}
	}

	class Server
	{
		TcpListener Listener;
		public Server(int Port)
		{
			Listener = new TcpListener(IPAddress.Any, Port);
			Listener.Start();
			while (true)
			{
				ThreadPool.QueueUserWorkItem(new WaitCallback(ClientThread), Listener.AcceptTcpClient());
			}
		}

		static void ClientThread(Object StateInfo)
		{
			new Client((TcpClient)StateInfo);
		}

		~Server()
		{
			if (Listener != null)
			{
				Listener.Stop();
			}
		}

		static void Main(string[] args)
		{
			ThreadPool.SetMaxThreads(1, 1);
			ThreadPool.SetMinThreads(1, 1);
			new Server(80);
		}
	}
}
