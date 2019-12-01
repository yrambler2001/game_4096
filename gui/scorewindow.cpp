// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "scorewindow.h"
#include "ui_scorewindow.h"

#include <QNetworkReply>

ScoreWindow::ScoreWindow( QWidget* parent ) :
    QWidget( parent ),
    ui( new Ui::ScoreWindow ) {
    ui->setupUi( this );

    connect( ui->bnGo, SIGNAL( clicked( bool ) ), SLOT( onGo() ) );

    connect( &m_manager, SIGNAL( finished( QNetworkReply* ) ), SLOT( onFinished( QNetworkReply* ) ) );
}

ScoreWindow::~ScoreWindow() {
    delete ui;
}
void ScoreWindow::load() {
    m_manager.get( QNetworkRequest( QUrl( "http://localhost" ) ) );
}

void ScoreWindow::uploadScore(long long int score){
    if (this->prevscore!=score){
        this->prevscore=score;
    m_manager.get( QNetworkRequest( QUrl(  QString("http://localhost/%1").arg(score)    ) ) );
    }
}
void ScoreWindow::onGo() {
    ui->lbStatus->setText( "Working..." );
    load();
}

void ScoreWindow::onFinished( QNetworkReply* reply ) {
    if( reply->error() == QNetworkReply::NoError ) {
        QString data = QString::fromUtf8( reply->readAll() );
        ui->textEdit->setText( data );

        ui->lbStatus->setText( "Ready!" );
    } else {
        ui->lbStatus->setText( reply->errorString() );
    }

    reply->deleteLater();
}
