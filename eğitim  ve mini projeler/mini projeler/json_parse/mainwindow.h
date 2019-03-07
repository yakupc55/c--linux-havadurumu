#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
class QByteArray;
class QNetworkAccessManager;
class QNetworkReply;
class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

private:
	void BuildWindow();
	void ReadStory();
	void NetworkCleanup();
	QNetworkAccessManager * mNetMan;
	QNetworkReply * mNetReply;
	QByteArray * mDataBuffer;
protected:
  void changeEvent(QEvent *e);
private slots:
  void on_json_getir_clicked();
  void dataHazirDurumda();
  void okumaSonaErdi();
//  void OnRefreshClicked();
//  void OnDataReadyToRead();
//  void OnListReadFinished();
//  void OnStoryReadFinished();
private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
