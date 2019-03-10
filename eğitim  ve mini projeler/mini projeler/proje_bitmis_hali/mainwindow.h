#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "baglanti.h"
#include "downloader.h"
class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  Ui::MainWindow *ui;

protected:
  void changeEvent(QEvent *e);
private slots:
  void on_btn_goster_clicked();
  void readJson(QString veri);
  void on_btn_guncelle_clicked();

private:
  void bilgiGoster(int renk,QString yazi);
  int sayac=0;
  int max_sayac=4;
  Downloader *downloader;
};

#endif // MAINWINDOW_H
