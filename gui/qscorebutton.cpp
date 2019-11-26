#include "gui/qscorebutton.h"
#include "gui/scorewindow.h"

QScoreButton::QScoreButton( QWidget* parent) : QLabel(parent)
{
    setText("Scores");
    setAlignment(Qt::AlignCenter);
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
