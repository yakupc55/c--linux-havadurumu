#include "mynetworkclass.h"
#include <QDebug>
myNetworkClass::myNetworkClass(QObject *parent) : QObject(parent)
{
  connect(qnam,&QNetworkAccessManager::finished,this,&myNetworkClass::readRead);
}

void myNetworkClass::makeRequest(QString endPointRequest)
{
  qnam->get(QNetworkRequest(QUrl(endPointRequest)));
}

void myNetworkClass::readRead(QNetworkReply *reply){
  QByteArray myData;
  myData = reply->readAll();
  qDebug() << myData;
  emit(dataReadyRead(myData));
}
