/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_guncelle;
    QTableView *tableView;
    QPushButton *btn_goster;
    QLabel *label_bilgi;
    QLabel *label_resim;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(551, 382);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_guncelle = new QPushButton(centralWidget);
        btn_guncelle->setObjectName(QStringLiteral("btn_guncelle"));

        gridLayout->addWidget(btn_guncelle, 0, 1, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 2, 0, 1, 2);

        btn_goster = new QPushButton(centralWidget);
        btn_goster->setObjectName(QStringLiteral("btn_goster"));

        gridLayout->addWidget(btn_goster, 0, 0, 1, 1);

        label_bilgi = new QLabel(centralWidget);
        label_bilgi->setObjectName(QStringLiteral("label_bilgi"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_bilgi->setFont(font);
        label_bilgi->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(label_bilgi, 1, 0, 1, 2);

        label_resim = new QLabel(centralWidget);
        label_resim->setObjectName(QStringLiteral("label_resim"));

        gridLayout->addWidget(label_resim, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_guncelle->setText(QApplication::translate("MainWindow", "Veritaban\304\261n\304\261 g\303\274ncelle", Q_NULLPTR));
        btn_goster->setText(QApplication::translate("MainWindow", "Hava durumunu g\303\266ster", Q_NULLPTR));
        label_bilgi->setText(QString());
        label_resim->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
