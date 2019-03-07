#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
class QNetworkAccessManager;
class QNetworkReply;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

protected:
  void changeEvent(QEvent *e);
private slots:
  void on_pushButton_clicked();
  void managerFinished(QNetworkReply *reply);
private:
  QNetworkAccessManager *manager;
  QNetworkReply *reply;
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
