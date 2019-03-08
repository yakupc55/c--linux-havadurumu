#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
 ui(new Ui::MainWindow)
{
  setupUi(this);
  connect(&theDon,SIGNAL(dataReadyRead(QByteArray)),this,SLOT(datalnDaHouse(QByteArray)));
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

void MainWindow::datalnDaHouse(QByteArray data)
{
  QString dataString;
    qDebug() <<data.size();
  dataString = data;
  qDebug() <<dataString;
 // ui->apiResponseDisplay->setText(dataString);
}

void MainWindow::on_pushButton_clicked()
{
    theDon.makeRequest("http://paste2.org");
}
