// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "gui/mainwindow.h"
#include <QApplication>

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "core/board.h"
#include "gui/qgameboard.h"

#include "gui/qgameoverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));
    QGameBoard board;
    board.show();

    return a.exec();
}
