#include "mythread.h"
#include <QDebug>
MyThread::MyThread(QString str)
{
 this->name= str;
}

void MyThread::run(){
 for (int i=0;i<1000;i++)
  qDebug()<< name <<"is running "<<i;
}
