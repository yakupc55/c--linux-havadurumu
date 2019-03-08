#ifndef MYJOB_H
#define MYJOB_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QDebug>
#include <QThread>
class MyJob : public QObject
{
  Q_OBJECT
public:
  explicit MyJob(QObject *parent = nullptr);
    ~MyJob();
  void start(QString name);
signals:
  void on_number(QString name,int number);
public slots:
  void stop();
private:
  bool mStop;
};

#endif // MYJOB_H
