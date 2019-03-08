#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "mynetworkclass.h"
class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

protected:
  void changeEvent(QEvent *e);
private slots:
  void datalnDaHouse(QByteArray data);
  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  myNetworkClass theDon;
};

#endif // MAINWINDOW_H
