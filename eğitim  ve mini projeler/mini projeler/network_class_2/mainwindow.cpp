#include "mainwindow.h"

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

//    qDebug() <<veri;
    ui->textBrowser->setText(veri);
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
