/********************************************************************************
** Form generated from reading UI file 'scorewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREWINDOW_H
#define UI_SCOREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QLabel *lbStatus;
    QHBoxLayout *horizontalLayout;
    QPushButton *bnGo;

    void setupUi(QWidget *ScoreWindow)
    {
        if (ScoreWindow->objectName().isEmpty())
            ScoreWindow->setObjectName(QString::fromUtf8("ScoreWindow"));
        ScoreWindow->resize(115, 294);
        verticalLayout = new QVBoxLayout(ScoreWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(ScoreWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        lbStatus = new QLabel(ScoreWindow);
        lbStatus->setObjectName(QString::fromUtf8("lbStatus"));

        verticalLayout->addWidget(lbStatus);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bnGo = new QPushButton(ScoreWindow);
        bnGo->setObjectName(QString::fromUtf8("bnGo"));

        horizontalLayout->addWidget(bnGo);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(bnGo, textEdit);

        retranslateUi(ScoreWindow);

        QMetaObject::connectSlotsByName(ScoreWindow);
    } // setupUi

    void retranslateUi(QWidget *ScoreWindow)
    {
        ScoreWindow->setWindowTitle(QApplication::translate("ScoreWindow", "Score Window", nullptr));
        lbStatus->setText(QString());
        bnGo->setText(QApplication::translate("ScoreWindow", "Refesh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreWindow: public Ui_ScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWINDOW_H
