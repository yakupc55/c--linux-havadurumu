#ifndef COKLU_H
#define COKLU_H

#include <QtCore/qglobal.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>
#include <QThread>
class coklu : public QThread
{
    Q_OBJECT
public:
    explicit coklu();

signals:
    void onReady(QString veri); // gelen json verisini gönderdiğimiz sınıfımız.
    void on_number(QString name,int number);
public slots:
    void getDatam();     // datayı alma kararırı verdiğimiz slotumuz
    void onResult(QNetworkReply *reply);    // sonuçların ulaştığı slotumuz

private:
    QNetworkAccessManager *manager; // Network işlerini yapacak nesneyi oluşturduk
};


#endif // COKLU_H
