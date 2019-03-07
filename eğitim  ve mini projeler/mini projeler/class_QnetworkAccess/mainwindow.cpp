#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);
}

void MainWindow::changeEvent(QEvent *e)
{
  QMainWindow::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      retranslateUi(this);
      break;
    default:
      break;
    }
}
