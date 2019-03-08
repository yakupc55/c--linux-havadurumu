#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include <mythread.h>
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  MyThread *thread1= new MyThread("1");
  MyThread *thread2= new MyThread("2");
  MyThread *thread3= new MyThread("3");
  thread1->start();
  thread2->start();
  thread3->start();

  thread1->setPriority(QThread::HighPriority);
  thread2->setPriority(QThread::HighPriority);
  thread3->setPriority(QThread::LowPriority);
  qDebug("QThread Application");
  return a.exec();
}
