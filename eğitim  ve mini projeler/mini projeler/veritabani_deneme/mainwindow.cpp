#include "mainwindow.h"
#include <QtSql>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);/*
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // bu sqllite ile ilgili işlem yapmasını sağlıyor
  db.setDatabaseName("/home/yakup/Masaüstü/projeler/c--linux-havadurumu/veritabanları/deneme1.sqlite");
  db.open();
  QSqlQuery query;
  query.exec("INSERT INTO Buffer (Size,Variable , Offset,Type,lololol) "
             "VALUES (30, 'mahmut','0x6035','Double','hadi ordan')");
  if(db.isOpen()){
      qDebug()<< "DB Opened";
    }
  else{
      qDebug() << "DB not opened"<<db.lastError(); // burda hatayı consola bas diyoruz
    }*/
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
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // bu sqllite ile ilgili işlem yapmasını sağlıyor
  QString baglanti="/home/yakup/Masaüstü/projeler/c--linux-havadurumu/veritabanları/deneme1.sqlite";
  db.setDatabaseName(baglanti);
  db.open();
  QString connName=db.connectionName();
  QSqlQueryModel *modal= new QSqlQueryModel();
  QSqlQuery query;
  query.exec("Select * from Buffer");
  modal->setQuery(query);
  qDebug() <<modal->rowCount();
  ui->tableView->setModel(modal);
  db.close();
 QSqlDatabase::removeDatabase(connName);
}
