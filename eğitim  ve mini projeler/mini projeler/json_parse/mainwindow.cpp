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
MainWindow::MainWindow(QWidget * parent)
  : QMainWindow(parent)
  , mNetMan(new QNetworkAccessManager(this))
  , mNetReply(nullptr)
  , mDataBuffer(new QByteArray)
  ,ui(new Ui::MainWindow)
{
  setupUi(this);/*
  connect(mNetReply, &QIODevice::readyRead, this, &MainWindow::dataHazirDurumda);
  // okuma bitti sinyali geldiğinde  gerekli fonkisyonumuzu çalıştır diyoruz(slot işlemi)
  connect(mNetReply, &QNetworkReply::finished, this, &MainWindow::okumaSonaErdi);*/
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

void MainWindow::on_json_getir_clicked()
{
// öncelikle çoklu istekleri engellemek için butonu devre dışı bırakıyoruz
 // ui->json_getir->setEnabled(false);
  // deneme amacıyla bir adet json çekiyoruz.
  const QUrl json_verimiz ("http://samples.openweathermap.org/data/2.5/forecast?q=istanbul&appid=7a3dd67365e103ea25683db411ac2495");
  mNetReply = mNetMan->get(QNetworkRequest(json_verimiz));

  // qt nin ana yapılarında biri olan signal- slot yapılarını bu işlem için tabikide kullanıyoruz :)
  //okuma durumu sinyali geldiğinde gerekli fonkisyonumuzu çalıştır diyoruz(slot işlemi)
 mDataBuffer->append(mNetReply->readAll());
 QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
 QJsonArray array = doc.array();
 qDebug() << array.size();
 QString dataToString=doc.toJson();
 qDebug() << dataToString;
 mNetReply->deleteLater();
 mNetReply = nullptr;
 mDataBuffer->clear();
}

void MainWindow::dataHazirDurumda()
{
  mDataBuffer->append(mNetReply->readAll());
}

void MainWindow::okumaSonaErdi()
{
  QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
  QJsonArray array = doc.array();
  qDebug() << array.size();
  QString dataToString=doc.toJson();
  qDebug() << dataToString;
    //
    NetworkCleanup();
     // -- SET UP PANEL STORIES --
}

void MainWindow::NetworkCleanup()
{
  mNetReply->deleteLater();
  mNetReply = nullptr;
  mDataBuffer->clear();
}
