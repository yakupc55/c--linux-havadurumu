#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QThread>
class MyThread : public QThread
{
  Q_OBJECT
public:
  explicit MyThread(QString str);
  void run();
signals:

public slots:

public:
  QString name;
};

#endif // MYTHREAD_H
