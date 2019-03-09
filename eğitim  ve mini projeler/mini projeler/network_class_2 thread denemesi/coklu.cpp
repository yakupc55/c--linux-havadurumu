
#include "coklu.h"

coklu::coklu()
{
    // manager sınıfımızı oluşturuyoruz
    manager = new QNetworkAccessManager();
    // gerekli sinyal-slot bağlantımızı yapıyoruz. burda eğer networkten veri okuma işlemi bitti diye bir sinyal alırsak
    //onresult adlı slotumuzu çalıştır diyoruz
    connect(manager, &QNetworkAccessManager::finished, this, &coklu::onResult);
}

void coklu::getDatam()
{
  //  qDebug() << "Start";
    QUrl url("http://api.apixu.com/v1/current.json?key=7d01bbfa3fca46268ca62722190703&q=Yozgat"); // URL, к которому будем получать данные
    QNetworkRequest request;    // Ağ Erişimi API'sinin bir parçasıdır ve ağ üzerinden bir istek göndermek için gereken bilgileri içeren sınıftır. Bir URL ve isteği değiştirmek için kullanılabilecek bazı yardımcı bilgiler içerir.
    request.setUrl(url);        // istenen url ye yönelik bir request nesnesi oluşturduk
    manager->get(request);      // request nesnemizi managerde işleme aldık
}

void coklu::onResult(QNetworkReply *reply)
{
  //qDebug() << "On result";
  // qDebug() << reply->readAll();
    if(reply->error()){
        // eğer herhangi bir hata dönerse
        qDebug() << "ERROR";
        // qnetworkReply da hata değerlerini tutan errorStringden verilerimizi okuyoruz
        qDebug() << reply->errorString();
    } else {
        // verimizi ana sııfaa tekrar gönderimek için bir string nesnesine aktarıyoruz
      QString veri= reply->readAll();
//      qDebug()<<"gondermeden önce alinan veri" <<veri;
        emit onReady(veri); // veriyi ana nesneye göndermek için sinyalimizi oluşturuyoruz.
        }

}

