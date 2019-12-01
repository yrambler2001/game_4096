// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "gui/mainwindow.h"
//#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) /*,
    ui(new Ui::MainWindow)*/
{
 //   ui->setupUi(this);
    gameBoard = new QGameBoard(this);
    setCentralWidget(gameBoard);
}

MainWindow::~MainWindow()
{
  //  delete ui;
}
