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
    void onReady(QString veri);

public slots:
    void getData();     // Метод инициализации запроса на получение данных
    void onResult(QNetworkReply *reply);    // Слот обработки ответа о полученных данных

private:
    QNetworkAccessManager *manager; // менеджер сетевого доступа
};


#endif // DOWNLOADER_H
