#ifndef BAGLANTI_H
#define BAGLANTI_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QtSql>
#include <QDebug>
class baglanti : public QObject
{
  Q_OBJECT
public:
  explicit baglanti(QObject *parent = nullptr);
  QSqlDatabase db;
  void connClose(){
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
  }
  bool connOpen(){
    db = QSqlDatabase::addDatabase("QSQLITE"); // bu sqllite ile ilgili işlem yapmasını sağlıyor
    db.setDatabaseName("/home/yakup/Masaüstü/projeler/c--linux-havadurumu/veritabanları/havadurumu.sqlite");
    db.open();
    if(db.isOpen()){
        qDebug()<< "Veri tabanı bağlantısı başarılı";
        return true;
      }
    else{
        qDebug() << "Veri tabanı bağlantısı başarısız"<<db.lastError(); // burda hatayı consola bas diyoruz
        return false;
      }
  }
signals:

public slots:
};

#endif // BAGLANTI_H
