// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "gui/mainwindow.h"
#include <QApplication>

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "core/board.h"
#include "core/game.h"
#include "gui/qgameboard.h"
#include <fstream>

#include "gui/qgameoverwindow.h"
static int test = false;
int main(int argc, char *argv[])
{
	if (test) {
        ofstream tests_log;
        tests_log.open("tests.log");
        tests_log <<"********* Start testing of 4096 *********\n";
        tests_log << "Config: Using QTest library 5.13.2, Qt 5.13.2\n";
//        Board* board=new Board(4);
        int passed=0;
        Game *g=new Game(4);
        tests_log <<  ++passed<<"PASS : new Game\n";
        Board *board=g->getGameBoard();
         tests_log <<  ++passed<<"PASS : get Board\n";
         if (g->won()==false)  tests_log << ++passed<<"PASS : Game::won()\n";
         if (board->full()==false)  tests_log << ++passed<<"PASS : Board::full()\n";
         for (int i=0;i<4;i++)
             for (int j=0;j<4;j++)
                 if (board->getTile(i,j)!=NULL)  tests_log << ++passed<<"PASS : Tile Found! "<<i<<" "<<j<<"\n";
         board=new Board(4);
         for (int i=0;i<4;i++)
             for (int j=0;j<4;j++)
                 if (board->getTile(i,j)==NULL)  tests_log << ++passed<<"PASS : Empty Tile "<<i<<" "<<j<<"\n";
         tests_log << ++passed<<"PASS : Reset Board\n";
         board->reset();
         for (int i=0;i<4;i++)
             for (int j=0;j<4;j++)
                 if (board->getTile(i,j)!=NULL)  tests_log << ++passed<<"PASS : New Tile "<<i<<" "<<j<<"\n";
         board->move(LEFT);
         for (int i=0;i<4;i++)
             for (int j=0;j<4;j++)
                 if (board->getTile(i,j)!=NULL)  tests_log << ++passed<<"PASS : Tiles after move LEFT: "<<i<<" "<<j<<"\n";
         board->move(DOWN);
         for (int i=0;i<4;i++)
             for (int j=0;j<4;j++)
                 if (board->getTile(i,j)!=NULL)
                     tests_log << ++passed<<"PASS : Tiles after move DOWN: "<<i<<" "<<j<<"\n";
        if (board->movePossible()) tests_log <<++passed<<"PASS : move is possible\n";
        tests_log << "Totals : "<<passed<<" passed, "<<32-passed<<" failed, 0 skipped\n";
        tests_log << "********* Finished testing of 4096 *********\n";
        tests_log.close();
    }
	else {
		QApplication a(argc, argv);

		srand(time(NULL));
		QGameBoard board;
		board.show();

		return a.exec();
	}
}
