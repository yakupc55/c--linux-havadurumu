#include "mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QtDebug>
#include <QtSerialPort/QSerialPort>
#include <QCoreApplication>
QNetworkRequest request;
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

      manager = new QNetworkAccessManager();
      QObject::connect(manager, &QNetworkAccessManager::finished,
          this, [=](QNetworkReply *reply) {
              if (reply->error()) {
                  qDebug() << reply->errorString();
                  return;
              }

              QString answer = reply->readAll();

              qDebug() << answer;
          }
      );
      QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
          this, SLOT(managerFinished(QNetworkReply*)));
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
  QString urlemiz= "http://samples.openweathermap.org/data/2.5/forecast?q=istanbul&appid=7a3dd67365e103ea25683db411ac2495";
  QNetworkRequest request;
  request.setUrl(QUrl(urlemiz));
  request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

  QNetworkReply *reply = manager->get(request);
  QObject::connect(reply, &QIODevice::readyRead, this, &MainWindow::slotReadyRead);
  QObject::connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
          this, &MainWindow::slotError);
  QObject::connect(reply, &QNetworkReply::sslErrors,
          this, &MainWindow::slotSslErrors
//  request.setUrl(QUrl("http://samples.openweathermap.org/data/2.5/forecast?q=istanbul&appid=7a3dd67365e103ea25683db411ac2495"));
//      manager->get(request);
}



void MainWindow::managerFinished(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();

    qDebug() << answer;
}
