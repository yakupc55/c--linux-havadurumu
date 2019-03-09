#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    downloader = new Downloader(); // downloader nesnesini ana sınıfta oluşturuyoruz

    // bir sinyal slot bağlantısı oluşturduk
    // bu bağlantı pushbutona tıklandığında dowloaderdaki yapının faaliyete girmesini sağlıyor
    connect(ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);
    // bir sinyal slot daha oluşturduk buda verinin downloader nesnesinde bize geri gelmesini sağlıyor.
    connect(downloader, &Downloader::onReady, this, &MainWindow::readJson);

}


void MainWindow::readJson(QString veri)
{
  QJsonDocument doc = QJsonDocument::fromJson(veri.toUtf8());
  QJsonObject jObject = doc.object();
  QJsonObject current=jObject["current"].toObject();
  QJsonValue  temp=current["temp_c"];
  qDebug() <<temp.toDouble();
      //convert the json object to variantmap
      QVariantMap mainMap = jObject.toVariantMap();

      //convert the json object to variantmap

 //  qDebug() <<veri;
  //  ui->textBrowser->setText(veri);
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

void MainWindow::on_cokluistek_clicked()
{
  downloader = new Downloader(); // downloader nesnesini ana sınıfta oluşturuyoruz

  // bir sinyal slot bağlantısı oluşturduk
  // bu bağlantı pushbutona tıklandığında dowloaderdaki yapının faaliyete girmesini sağlıyor
  downloader->getVeri("ankara");
  downloader->getVeri("istanbul");
  downloader->getVeri("bursa");
  downloader->getVeri("yozgat");
  downloader->getVeri("trabzon");
  downloader->getVeri("paris");
  downloader->getVeri("paris");
  downloader->getVeri("konya");
  downloader->getVeri("izmir");
  downloader->getVeri("samsun");
  downloader->getVeri("madrid");
  downloader->getVeri("singapur");
  downloader->getVeri("diyarbakır");
  // bir sinyal slot daha oluşturduk buda verinin downloader nesnesinde bize geri gelmesini sağlıyor.
  connect(downloader, &Downloader::onReady, this, &MainWindow::readJson);

}
