#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

void MainWindow::changeEvent(QEvent *e)
{
  QMainWindow::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      retranslateUi(this);
      break;
    default:
      break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man,&QNetworkAccessManager::finished,this,&MainWindow::downloadFinished);
    const QUrl url=QUrl(myUrl);
    QNetworkRequest request(url);
    man->get(request);
}
void MainWindow::downloadFinished(QNetworkReply* reply){
  qDebug () << reply->readAll();
  ui->textBrowser->setText(reply->readAll());
}
