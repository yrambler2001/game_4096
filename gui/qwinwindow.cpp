// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "qwinwindow.h"
#include "qresetbutton.h"
#include "qscorebutton.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>

QWinWindow::QWinWindow(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("QWinWindow { background: rgb(237,224,200); }");
    setFixedSize(625,285);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QHBoxLayout *hlayout = new QHBoxLayout(this);

    QLabel* gameover = new QLabel("You Win!", this);
    QLabel* creators = new QLabel("Created by Y. Synyshyn and A. Sowa", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40px; font: bold;} ");
    creators->setStyleSheet("QLabel { color: rgb(0,0,0); font: 20px; font: bold;} ");
    // reset button
    reset = new QResetButton(this);
    reset->setFixedHeight(50);
    reset->setFixedWidth(100);    
    scorebutton = new QScoreButton(this);
    scorebutton->setFixedHeight(50);
    scorebutton->setFixedWidth(100);
    // add game over label to window
    layout->insertWidget(0,creators,0,Qt::AlignCenter);
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
    // add reset button to window
    hlayout->insertWidget(1,reset,0,Qt::AlignCenter);
    hlayout->insertWidget(1,scorebutton,0,Qt::AlignCenter);
    layout->insertLayout(1,hlayout);
}
void  QWinWindow::setScore(long long int score){
    scorebutton->setScore(score);
}


QResetButton* QWinWindow::getResetBtn() const
{
    return reset;
}
