#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QtCore/qglobal.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);

signals:
    void onReady(QString veri); // gelen json verisini gönderdiğimiz sınıfımız.

public slots:
    void getData();     // datayı alma kararırı verdiğimiz slotumuz
    void onResult(QNetworkReply *reply);    // sonuçların ulaştığı slotumuz

private:
    QNetworkAccessManager *manager; // Network işlerini yapacak nesneyi oluşturduk
};


#endif // DOWNLOADER_H
