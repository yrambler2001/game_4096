#include "qgameoverwindow.h"
#include "qresetbutton.h"
#include "qscorebutton.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>

QGameOverWindow::QGameOverWindow(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("QGameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(625,205);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QLabel* gameover = new QLabel("Game Over!", this);
    QLabel* creators = new QLabel("Created by Y. Synyshyn and A. Sowa", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold;} ");
    creators->setStyleSheet("QLabel { color: rgb(0,0,0); font: 20pt; font: bold;} ");
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
    layout->insertWidget(1,reset,0,Qt::AlignCenter);    
    layout->insertWidget(1,scorebutton,0,Qt::AlignCenter);    
}
void  QGameOverWindow::setScore(long long int score){
    scorebutton->setScore(score);
}


QResetButton* QGameOverWindow::getResetBtn() const
{
    return reset;
}
