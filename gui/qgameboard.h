#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include "core/observer.h"
#include "qgameoverwindow.h"
#include "qwinwindow.h"

#include <QVector>
#include <QWidget>

class QResetButton;
class Game;
class QKeyEvent;
class QTile;
class QGridLayout;
class QVBoxLayout;
class QLabel;

class QGameBoard : public QWidget, public Observer
{
    Q_OBJECT
public:
    explicit QGameBoard(QWidget *parent = nullptr);
    ~QGameBoard();
    QResetButton* getResetBtn() const;

    void notify();

private:

    Game* game;
    // gui representation of board
    QVector<QVector<QTile*> > gui_board;
    // main layout
    QVBoxLayout *mainLayout;
    // grid layout of board
    QGridLayout *boardLayout;
    // score widget
    QLabel *score;
    // game over widget
    QGameOverWindow gameOverWindow;
    QWinWindow winWindow;
    // winner widget
    QLabel *youwin;
    QResetButton* reset;
    QScoreButton* scorebutton;


    void drawBoard();

protected:
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:
    void resetGame();

};

#endif // QGAMEBOARD_H
