#ifndef QRESETBUTTON_H
#define QRESETBUTTON_H

#include <QLabel>

class QResetButton : public QLabel
{
    Q_OBJECT
public:
    QResetButton( QWidget* parent = nullptr, bool isMainBoard = false);

signals:
    void clicked();

public slots:

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // QRESETBUTTON_H
