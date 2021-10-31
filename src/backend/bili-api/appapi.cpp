#include "appapi.h"
#include <QDebug>
AppAPI::AppAPI(QObject *parent) : QObject(parent)
{

}
void AppAPI::getSearchDefaultWords()
{
    QNetworkRequest request;
    HttpRequest *httprequest=new HttpRequest;
    request.setUrl(QUrl("http://api.bilibili.cn/x/web-interface/search/default"));
    connect(httprequest,&HttpRequest::finished,[=](QString data){
        QByteArray arr = data.toUtf8();
            //解析Json
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(arr,&error);
            QJsonObject obj = doc.object();
            QJsonArray array;
            array.append(obj);
            emit finished(array);
            httprequest->deleteLater();
    });
    httprequest->getRequest(request);

}
void AppAPI::getRecommendVideo()
{ 
    QNetworkRequest request;
    HttpRequest *httprequest=new HttpRequest;
    request.setUrl(QUrl("https://app.bilibili.com/x/feed/index?build=1&mobi_app=android"));
    connect(httprequest,&HttpRequest::finished,[=](QString data){
        QByteArray arr = data.toUtf8();
            //解析Json
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(arr,&error);
            QJsonObject obj = doc.object();
            emit finished(obj.value("data").toArray());
            httprequest->deleteLater();
    });
    httprequest->getRequest(request);
}
void AppAPI::getSearchVideo(QString type,QString keyword,int page)
{
    QNetworkRequest request;
    HttpRequest *httprequest=new HttpRequest;
    request.setUrl(QUrl("http://api.bilibili.com/x/web-interface/search/type?&search_type="+type+"&keyword="+keyword+"&page="+QString::number(page)));
    connect(httprequest,&HttpRequest::finished,[=](QString data){
        QByteArray arr = data.toUtf8();

            //解析Json
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(arr,&error);
            QJsonObject obj = doc.object();
            emit finished(obj.value("data").toObject().value("result").toArray());
            httprequest->deleteLater();
    });
    httprequest->getRequest(request);
}
void AppAPI::getPopularVideo()
{
    QNetworkRequest request;
    HttpRequest *httprequest=new HttpRequest;
    request.setUrl(QUrl("https://api.bilibili.com/x/web-interface/ranking"));
    connect(httprequest,&HttpRequest::finished,[=](QString data){
        QByteArray arr = data.toUtf8();
            //解析Json
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(arr,&error);
            QJsonObject obj = doc.object();
            emit finished(obj.value("data").toObject().value("list").toArray());
            httprequest->deleteLater();
    });
    httprequest->getRequest(request);
}
