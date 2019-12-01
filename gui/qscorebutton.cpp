// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "gui/qscorebutton.h"
#include "gui/scorewindow.h"

QScoreButton::QScoreButton( QWidget* parent, bool mainBoard) : QLabel(parent)
{
    setText("Scores");
    setAlignment(Qt::AlignCenter);
    if (mainBoard)
        setStyleSheet("QScoreButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; padding: 2px; }");
    else
        setStyleSheet("QScoreButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; padding: 2px; border-bottom: 4px solid transparent; }");
    ScoreWindow scorewindow;
}

void QScoreButton::mousePressEvent(QMouseEvent* event)
{
    this->scorewindow.show();
    this->scorewindow.load();
    emit clicked();
}

void QScoreButton::setScore (long long int score) {
    this->scorewindow.uploadScore(score);
}
