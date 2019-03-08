#include "mainwindow.h"
#include <QFuture>
#include <QtConcurrent>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);
}
MainWindow::~MainWindow(){
  emit on_stop();

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

void MainWindow::on_btnStart_clicked()
{
  //QT 4+ connect(obj,SIGNAL(),obj2,SLOT())

  //QT 5+
  connect(&mJob,&MyJob::on_number,this,&MainWindow::newNumber);
  connect(this,&MainWindow::on_stop,&mJob,&MyJob::stop);

  QFuture<void> test = QtConcurrent::run(&this->mJob,&MyJob::start,QString("kitten"));
}

void MainWindow::on_btnStop_clicked()
{
  emit on_stop();
}

void MainWindow::newNumber(QString name, int number)
{
  qDebug()<< "from dialog: "<< name << " "<<number;
}
