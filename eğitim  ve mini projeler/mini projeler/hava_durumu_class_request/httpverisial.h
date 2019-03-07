#ifndef HTTPVERISIAL_H
#define HTTPVERISIAL_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include <QNetworkAccessManager>
// istek yapmak(to make request) için kullanacağımız kütüphane
#include <QNetworkReply>
// yanıtları işlemek (to handle replies) için kullanacağımız kütüphane

class httpVerisiAl : public QObject
{
  Q_OBJECT
public:
  explicit httpVerisiAl(QObject *parent = nullptr);
  void veriAl(QString veri);
  void veriAl(QString veri,QNetworkAccessManager man);
  QString getVeri();
signals:

public slots:
    void downloadFinished(QNetworkReply*);
private:
    QString myData;
    QNetworkRequest request;
};

#endif // HTTPVERISIAL_H
