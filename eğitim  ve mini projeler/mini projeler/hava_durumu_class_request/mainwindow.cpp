#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);
 man = new QNetworkAccessManager(this);
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
    man = new QNetworkAccessManager(this);
    httpVerisiAl deneme;
    QString url="http://api.apixu.com/v1/current.json?key=7d01bbfa3fca46268ca62722190703&q=Paris";
    deneme.veriAl(url,man);
    qDebug() <<deneme.getVeri();
}
