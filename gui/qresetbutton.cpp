// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "gui/qresetbutton.h"




QResetButton::QResetButton( QWidget* parent, bool mainBoard) : QLabel(parent)
{
    setText("Try again!");
    setAlignment(Qt::AlignCenter);
    if (mainBoard)
    setStyleSheet("QResetButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; }");
    else
    setStyleSheet("QResetButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; border-top: 4px solid transparent; }");

}

void QResetButton::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
