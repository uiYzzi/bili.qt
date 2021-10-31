#ifndef VIDEOITEM_H
#define VIDEOITEM_H
#include <QObject>
#include <QWidget>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QBitmap>
#include <QPainter>
#include <QPainterPath>
#include <QDesktopServices>
#include <QPixmapCache>
namespace Ui {
class VideoItem;
}

class VideoItem : public QWidget
{
    Q_OBJECT

public:
    void setTitle(QString title);
    void setAuthor(QString author);
    void setBvid(QString bvid);
    void setCover(QUrl cover);
    void setPlay(int play);
    void setDanmaku(QString danmaku);
    explicit VideoItem(QWidget *parent = nullptr);
    ~VideoItem();
private slots:
    void setPic(QNetworkReply *reply);

private:
    QNetworkAccessManager *naManager;
    QString bvid;
    Ui::VideoItem *ui;
signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);
    bool eventFilter(QObject *obj, QEvent *event);
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // VIDEOITEM_H
