#ifndef QGAMEOVERWINDOW_H
#define QGAMEOVERWINDOW_H

#include <QWidget>
#include "scorewindow.h"
class QResetButton;
class QScoreButton;

class QGameOverWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QGameOverWindow(QWidget *parent = nullptr);
    void setScore(long long int score);
    QResetButton* getResetBtn() const;

signals:

public slots:


private:
    QResetButton* reset;
    QScoreButton* scorebutton;
//    ScoreWindow scorewindow;


};

#endif // QGAMEOVERWINDOW_H
