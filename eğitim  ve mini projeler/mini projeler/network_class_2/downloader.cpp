
#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    // Инициализируем менеджер ...
    manager = new QNetworkAccessManager();
    // ... и подключаем сигнал о завершении получения данных к обработчику полученного ответа
    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
}

void Downloader::getData()
{
    qDebug() << "Start";
    QUrl url("http://api.apixu.com/v1/current.json?key=7d01bbfa3fca46268ca62722190703&q=Paris"); // URL, к которому будем получать данные
    QNetworkRequest request;    // Отправляемый запрос
    request.setUrl(url);        // Устанавлвиваем URL в запрос
    manager->get(request);      // Выполняем запрос
}

void Downloader::onResult(QNetworkReply *reply)
{
  qDebug() << "On result";
    // Если в процесе получения данных произошла ошибка
  // qDebug() << reply->readAll();
    if(reply->error()){
        // Сообщаем об этом и показываем информацию об ошибках
        qDebug() << "ERROR";
        qDebug() << reply->errorString();
    } else {
      QString veri= reply->readAll();
      qDebug()<<"gondermeden önce alinan veri" <<veri;
        emit onReady(veri); // Посылаем сигнал о завершении получения файла
        }

}
