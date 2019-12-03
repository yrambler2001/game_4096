#ifndef QWinWindow_H
#define QWinWindow_H

#include <QWidget>
#include "scorewindow.h"
class QResetButton;
class QScoreButton;

class QWinWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QWinWindow(QWidget *parent = nullptr);
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
