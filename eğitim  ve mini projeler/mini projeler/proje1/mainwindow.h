#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
  void butona_basildi_1();
  void butona_basildi_2();
  void butona_basildi_3();

private slots:
  void on_pushButton_pressed();
  void on_pushButton_released();

  void label_1_slot();
  void label_2_slot();
  void label_3_slot();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
