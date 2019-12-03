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
        ScoreWindow->resize(173, 294);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScoreWindow->sizePolicy().hasHeightForWidth());
        ScoreWindow->setSizePolicy(sizePolicy);
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
        textEdit->setHtml(QApplication::translate("ScoreWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">1</span></p></body></html>", nullptr));
        lbStatus->setText(QString());
        bnGo->setText(QApplication::translate("ScoreWindow", "Refesh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreWindow: public Ui_ScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWINDOW_H
