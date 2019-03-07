#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QHttpMultiPart>
#include <QHttpResponseHeader>
#include <QtNetwork>
#include <QFile>
#include <QDebug>

class downloader : public QObject
{
  Q_OBJECT
public:
  explicit downloader(QObject *parent = nullptr);
  void Do_Download();
signals:

public slots:
  void stateChanged(int state);
  void responseHeaderRecived (const QHttpResponseHeader & resp);
//  void readyRead(const QHttpResponseHeader & resp);
  void requestFinished(int id,bool error);
private:
QHttpMultiPart *http;
};

#endif // DOWNLOADER_H
