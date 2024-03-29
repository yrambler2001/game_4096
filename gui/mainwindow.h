#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gui/qgameboard.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
//    Ui::MainWindow *ui;
    QGameBoard *gameBoard;

};

#endif // MAINWINDOW_H
