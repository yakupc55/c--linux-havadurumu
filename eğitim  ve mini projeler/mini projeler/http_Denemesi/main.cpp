#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>
#include "downloader.h"
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  downloader cDown;
  cDown.Do_Download();
  return a.exec();
}
