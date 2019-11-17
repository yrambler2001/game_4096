#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QWidget>
#include <QNetworkAccessManager>

namespace Ui {
class ScoreWindow;
}

class ScoreWindow : public QWidget {
    Q_OBJECT

public:
    explicit ScoreWindow( QWidget* parent = nullptr );
    void load();
    ~ScoreWindow();
    void uploadScore(long long int score);

private slots:
    void onGo();
    void onFinished( QNetworkReply* reply );

private:
    Ui::ScoreWindow* ui;

    QNetworkAccessManager m_manager;
    long long int prevscore=0;

};

#endif
