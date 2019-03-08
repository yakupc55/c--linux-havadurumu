#ifndef MYNETWORKCLASS_H
#define MYNETWORKCLASS_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QNetworkAccessManager>
#include <QNetworkReply>
class myNetworkClass : public QObject
{
  Q_OBJECT
public:
  explicit myNetworkClass(QObject *parent = nullptr);
  void makeRequest(QString endPointRequest);
signals:
void dataReadyRead(QByteArray);
public slots:
void readRead(QNetworkReply *reply);
private:
QNetworkAccessManager *qnam= new   QNetworkAccessManager(this);
};

#endif // MYNETWORKCLASS_H
