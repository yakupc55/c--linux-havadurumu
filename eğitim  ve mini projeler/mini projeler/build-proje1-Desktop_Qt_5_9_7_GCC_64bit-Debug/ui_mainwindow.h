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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionekleme_yap;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menumenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(953, 360);
        actionekleme_yap = new QAction(MainWindow);
        actionekleme_yap->setObjectName(QStringLiteral("actionekleme_yap"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 180, 101, 61));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(790, 70, 121, 81));
        label->setFrameShape(QFrame::Box);
        label->setLineWidth(2);
        label->setMidLineWidth(1);
        label->setTextFormat(Qt::RichText);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(780, 180, 160, 41));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 60, 111, 81));
        label_2->setFrameShape(QFrame::Box);
        label_2->setLineWidth(2);
        label_2->setMidLineWidth(1);
        label_2->setTextFormat(Qt::RichText);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 60, 111, 81));
        label_3->setFrameShape(QFrame::Box);
        label_3->setLineWidth(2);
        label_3->setMidLineWidth(1);
        label_3->setTextFormat(Qt::RichText);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(490, 60, 111, 81));
        label_4->setFrameShape(QFrame::Box);
        label_4->setLineWidth(2);
        label_4->setMidLineWidth(1);
        label_4->setTextFormat(Qt::RichText);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 22));
        menumenu = new QMenu(menuBar);
        menumenu->setObjectName(QStringLiteral("menumenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menumenu->menuAction());
        menumenu->addAction(actionekleme_yap);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(set_value()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionekleme_yap->setText(QApplication::translate("MainWindow", "ekleme yap", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        menumenu->setTitle(QApplication::translate("MainWindow", "menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
