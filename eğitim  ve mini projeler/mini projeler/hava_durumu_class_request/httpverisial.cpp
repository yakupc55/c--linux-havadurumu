#include "httpverisial.h"
#include <QCoreApplication>
#include <QDebug>
#include <thread>
#include <QThread>
#include <QPointer>
#include <QtConcurrent/qtconcurrentrun.h>
static QPointer<QNetworkAccessManager> globalManager;

// The global accessor method
QNetworkAccessManager *nMgr() {
  Q_ASSERT(!qApp || QThread::currentThread() == qApp->thread());
  return globalManager;
}
httpVerisiAl::httpVerisiAl(QObject *parent) : QObject(parent)
{

}

void httpVerisiAl::veriAl(QString veri){
        QNetworkAccessManager *man = new QNetworkAccessManager(this);
  bool success =  connect(man,SIGNAL(finished(QNetworkReply*)),this,SLOT(downloadFinished(QNetworkReply*))); Q_ASSERT(success);
  qDebug()<<" durum : "<< success <<" ";
//     connect(man,SIGNAL(finished(QNetworkReply*)),this,SLOT(downloadFinished(QNetworkReply*)));
//     const QUrl url=QUrl(veri);
//     QNetworkRequest request(url);
man->moveToThread(QThread::currentThread());
replym =   man->get(QNetworkRequest(QUrl(veri)));

}
 void httpVerisiAl::veriAl(QString veri,QNetworkAccessManager man)   {

      connect(man,&QNetworkAccessManager::finished,this,&httpVerisiAl::downloadFinished);
      const QUrl url=QUrl(myUrl);
      QNetworkRequest request(url);
      man->get(request);
   }
/*
void httpVerisiAl::downloadFinished(QNetworkReply* reply){
  myData=reply->readAll();
  qDebug() <<reply->readAll();
}
*/
void httpVerisiAl::downloadFinished(QNetworkReply* reply){
  qDebug() << reply->readAll();
if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();


    }

    reply->deleteLater();
}
QString httpVerisiAl::getVeri(){
  return myData;
}
