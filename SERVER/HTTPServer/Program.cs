// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
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
	class ResponseProcessor
	{
		string Data;
		public ResponseProcessor()
		{
			Data = "";
		}
		public void add(string s)
		{
			Data += s;
		}
		public void set(string s)
		{
			Data = s;
		}
		public byte[] toBuffer()
		{
			byte[] Buffer = Encoding.ASCII.GetBytes(Data);
			return Buffer;
		}
	}
	class ClientResponseProcessor : ResponseProcessor
	{
		public ClientResponseProcessor()
		{
		}
		public void generateError(int Code)
		{
			string CodeStr = Code.ToString() + " " + ((HttpStatusCode)Code).ToString();
			string Html = "<html><body><h1>" + CodeStr + "</h1></body></html>";
			string Str = "HTTP/1.1 " + CodeStr + "\nContent-type: text/html\nContent-Length:" + Html.Length.ToString() + "\n\n" + Html;
			set(Html + Str);
		}
		public void addHeader()
		{
		}
	}
	class FileReader : TextReader
	{
		string fileName = "";
		public FileReader(string s)
		{
			fileName = s;
		}
		public override void Close()
		{
			base.Close();
		}

		public override bool Equals(object obj)
		{
			return base.Equals(obj);
		}

		public override int GetHashCode()
		{
			return base.GetHashCode();
		}

		public override string ReadToEnd()
		{
			return File.ReadAllText(fileName);
		}

		public override string ToString()
		{
			return base.ToString();
		}
	}

	class DataBaseReader : FileReader
	{
		public DataBaseReader(string s) : base(s)
		{ }

		public List<long> GetDataFromDB()
		{
			List<long> l = ReadToEnd().Split(',').Select((stringValue) =>
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
			return l;
		}
	}
	class Client
	{
		static long prev = 0;
		private void SendError(TcpClient Client, int Code)
		{
			ClientResponseProcessor CRP = new ClientResponseProcessor();
			CRP.generateError(Code);
			closeClientWithBuffer(Client, CRP.toBuffer());
		}
		private void closeClientWithBuffer(TcpClient Client, byte[] Buffer)
		{
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
				ClientResponseProcessor CRP = new ClientResponseProcessor();

				try
				{
					string data = "";
					if (File.Exists(filename))
					{
						data += "<!DOCTYPE html>";
						data += "<html>";
						DataBaseReader DBReader = new DataBaseReader(filename);
						List<long> dataFromDB = DBReader.GetDataFromDB();
						int i = 0;

						data += dataFromDB.Select(x =>
						{
							string Div = (((++i) > 3) ? "<div>" : "<div><b>");
							string DivClose = ((i > 3) ? "</div>" : "</b></div>");
							string H = ((i < 4) ? "<h" + i + ">" : "");
							string HClose = ((i < 4) ? "<h" + i + ">" : "");
							string BestScore = ((i == 1) ? "&#128077;" : "");
							return Div + H + x + BestScore + HClose + DivClose;
						}).Aggregate("", (prev, curr) => prev + curr);
						data += "</html>";
					}
					CRP.add(data);
					byte[] ResponseBuffer = CRP.toBuffer();

					string Headers = "HTTP/1.1 200 OK\nContent-Type: " + "text/html" + "\nContent-Length: " + ResponseBuffer.Length + "\n\n";
					byte[] HeadersBuffer = Encoding.ASCII.GetBytes(Headers);
					Client.GetStream().Write(HeadersBuffer, 0, HeadersBuffer.Length);
					closeClientWithBuffer(Client, ResponseBuffer);
					Console.WriteLine("sent");
				}
				catch (Exception e) { Console.WriteLine("error " + e.ToString()); }
				Client.Close();
			}
			else
			{
				try
				{
					string newValue = RequestUri.Replace("/", "");
					if (newValue == "favicon.ico") { return; }
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
