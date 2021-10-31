#ifndef APPAPI_H
#define APPAPI_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include "src/backend/utils/httprequest.h"

class AppAPI : public QObject
{
    Q_OBJECT
public:
    void getSearchVideo(QString type,QString keyword,int page);
    void getSearchDefaultWords();
    void getRecommendVideo();
    void getPopularVideo();
    explicit AppAPI(QObject *parent = nullptr);
signals:
    void finished(QJsonArray);

public slots:
};

#endif // APPAPI_H
