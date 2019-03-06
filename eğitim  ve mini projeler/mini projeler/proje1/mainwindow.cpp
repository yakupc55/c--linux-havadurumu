#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(butona_basildi_1()),this,SLOT(label_1_slot()));
    connect(this,SIGNAL(butona_basildi_1()),this,SLOT(label_2_slot()));
    connect(this,SIGNAL(butona_basildi_1()),this,SLOT(label_3_slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
   emit butona_basildi_1();

}

void MainWindow::on_pushButton_released()
{
      ui->label_2->setText("");
      ui->label_3->setText("");
      ui->label_4->setText("");
}

void MainWindow::label_1_slot(){
  ui->label_2->setText("slot-1");
}
void MainWindow::label_2_slot(){
  ui->label_3->setText("slot-2");
}
void MainWindow::label_3_slot(){
  ui->label_4->setText("slot-3");
}
