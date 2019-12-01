#ifndef QSCOREBUTTON_H
#define QSCOREBUTTON_H

#include <QLabel>
#include <gui/scorewindow.h>

class QScoreButton : public QLabel
{
    Q_OBJECT
public:
    QScoreButton( QWidget* parent = nullptr, bool isMainBoard = false);
    void setScore(long long int score);

private:
    ScoreWindow scorewindow;

signals:
    void clicked();

public slots:

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // QSCOREBUTTON_H
