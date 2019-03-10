#include "mainwindow.h"
#include <QThread>
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

void MainWindow::on_btn_goster_clicked()
{
  bilgiGoster(3,"işlem yapılıyor");

    baglanti bag;
    if(bag.connOpen()){
        QSqlQueryModel *modal= new QSqlQueryModel();
        QSqlQuery *query= new QSqlQuery(bag.db);
        query->prepare("Select * from hava");
        query->exec();
        modal->setQuery(*query);
        modal->setHeaderData(1, Qt::Horizontal, tr("Şehirler"));
        modal->setHeaderData(2, Qt::Horizontal, tr("güncelleme tarihi"));
        qDebug() <<modal->rowCount();

        ui->tableView->setModel(modal);
        ui->tableView->setColumnHidden(0,true);
        bag.connClose();
       bilgiGoster(2,"işlem başarılı bir şekilde gerçekleşti");
      }
    else{
        //"color: rgb(45,239,45);"
      bilgiGoster(1,"veri tabanına ulaşılamıyor");
      }

}

void MainWindow::bilgiGoster(int no,QString yazi){
  QString gecerliRenk;

  switch(no){
    case 1: gecerliRenk="color: rgb(239, 41, 41);"; break;  // red
    case 2: gecerliRenk="color: rgb(41, 239, 41);"; break;  //green
    case 3: gecerliRenk="color: rgb(41, 41, 239);"; break; //blue
    }
ui->label_bilgi->setStyleSheet(gecerliRenk);
ui->label_bilgi->setText(yazi);
}

void MainWindow::readJson(QString veri)
{

  QJsonDocument doc = QJsonDocument::fromJson(veri.toUtf8());
  QJsonObject jObject = doc.object();

  QJsonObject current=jObject["current"].toObject();
  QJsonObject location=jObject["location"].toObject();
  QJsonValue name=location["name"];
  QJsonValue  temp=current["temp_c"];
  QJsonValue  last_updated=current["last_updated"];
  double derece=temp.toDouble();
  QString time=last_updated.toString();
  QString city=name.toString();

  qDebug() <<derece;
  qDebug() <<"last"<<time;
  qDebug()<<"city"<<city;

  bilgiGoster(3,"işlem yapılıyor");

    baglanti bag;
    if(bag.connOpen()){
        QSqlQuery *query= new QSqlQuery(bag.db);
        query->prepare("UPDATE hava SET derece="+ QString::number(derece)+", tarih='"+time+"' WHERE isim ='"+city+"'");
        qDebug() <<"UPDATE hava SET derece="+ QString::number(derece)+", tarih='"+time+"' WHERE isim ='"+city+"'";
        query->exec();
        sayac++;
      }
    else{
        //"color: rgb(45,239,45);"
      bilgiGoster(1,"veri tabanına ulaşılamıyor");
      }
    if(sayac==max_sayac){
        bilgiGoster(2,"tüm veri tabanı güncellendi");
        sayac=0;
     //  on_btn_goster_clicked();
      }

 //  qDebug() <<veri;

}

void MainWindow::on_btn_guncelle_clicked()
{
  downloader = new Downloader();

  downloader->getVeri("ankara");
  downloader->getVeri("istanbul");
  downloader->getVeri("konya");
  downloader->getVeri("izmir");
  // bir sinyal slot daha oluşturduk buda verinin downloader nesnesinde bize geri gelmesini sağlıyor.
  connect(downloader, &Downloader::onReady, this, &MainWindow::readJson);
}
