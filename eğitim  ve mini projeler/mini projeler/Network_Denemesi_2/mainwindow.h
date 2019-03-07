#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QNetworkAccessManager>  // istek yapmak(to make request) için kullanacağımız kütüphane
#include <QNetworkReply> // yanıtları işlemek (to handle replies) için kullanacağımız kütüphane
#include <QPixmap>  // resimlerle çalışmak (to work with images) için kullanacağımız kütüphane

class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

protected:
  void changeEvent(QEvent *e);
private:
 Ui::MainWindow *ui;
 QString myUrl2  ="https://asset.tureng.co/images/tureng-logo-top-mini-new.png";
 QString myUrl = "http://api.apixu.com/v1/current.json?key=7d01bbfa3fca46268ca62722190703&q=Paris";
   /*
  QString myUrl = "http://samples.openweathermap.org/data/2.5/forecast?q=istanbul&appid=7a3dd67365e103ea25683db411ac2495";*/
private slots:
  void downloadFinished(QNetworkReply*);
  void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
