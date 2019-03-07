#include "mynetworkclass.h"

myNetworkClass::myNetworkClass(QObject *parent) : QObject(parent)
{
  connect(qnam,SIGNAL(finished(QNetworkReply*)),this,SLOT(readRead(QNetworkReply*)));
}

void myNetworkClass::makeRequest(QString endPointRequest)
{
  qnam->get(QNetworkRequest(QUrl(endPointRequest)));
}

void myNetworkClass::readRead(QNetworkReply *reply){
  QByteArray myData;
  myData = reply->readAll();
}
