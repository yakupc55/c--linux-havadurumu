#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QtCore/qglobal.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>
#include <QThread>
class Downloader : public QThread
{
    Q_OBJECT
public:
    explicit Downloader();
signals:
    void onReady(QString veri); // gelen json verisini gönderdiğimiz sınıfımız.
public slots:
    void getVeri(QString veri);     // datayı alma kararırı verdiğimiz slotumuz
    void onResult(QNetworkReply *reply);    // sonuçların ulaştığı slotumuz

private:
    QNetworkAccessManager *manager; // Network işlerini yapacak nesneyi oluşturduk

};


#endif // DOWNLOADER_H
