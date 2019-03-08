#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "downloader.h"
class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

protected:
  void changeEvent(QEvent *e);
private slots:
    void readJson(QString veri);
private:
    Ui::MainWindow *ui;
    Downloader *downloader; // Объявляем объект класса для скачивания данных по http
};

#endif // MAINWINDOW_H
