#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QDebug>
#include "myjob.h"
class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
~MainWindow();
protected:
  void changeEvent(QEvent *e);
signals:
  void on_stop();
private slots:
  void on_btnStart_clicked();
  void on_btnStop_clicked();

public slots:
  void newNumber(QString name,int number);
public:
  MyJob mJob;
};

#endif // MAINWINDOW_H
