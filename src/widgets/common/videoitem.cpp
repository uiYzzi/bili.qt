#include "videoitem.h"
#include "ui_videoitem.h"

VideoItem::VideoItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_Hover,true);
    this->installEventFilter(this);
    auto *defaultShadow = new QGraphicsDropShadowEffect(this);
    defaultShadow->setBlurRadius(14.0);
    defaultShadow->setColor(QColor(0, 0, 0, 30));
    defaultShadow->setOffset(0, 0);
    ui->widget->setGraphicsEffect(defaultShadow);
    delete defaultShadow;
    ui->widget->setStyleSheet("#widget{background-color: rgba(255,255,255,0.8);border-radius:14px;}");
}
void VideoItem::setTitle(QString title)
{
    ui->cardtitle->setText(title);
}
void VideoItem::setBvid(QString bvid)
{
    VideoItem::bvid=bvid;
}
void VideoItem::setCover(QUrl cover)
{
    QNetworkRequest request;
    naManager=new QNetworkAccessManager(this);
    request.setUrl(cover);
    //使用 Referer 和 UA 请求头以绕过反爬虫机制
    request.setRawHeader("Referer", "https://www.bilibili.com");
    request.setRawHeader("User-Agent", "Mozilla/5.0");

    request.setRawHeader("Content-Type", "charset='utf-8'");
    request.setRawHeader("Content-Type", "application/json");

    naManager->get(request);
    QObject::connect(naManager,&QNetworkAccessManager::finished,this,&VideoItem::setPic);
}
void VideoItem::setPic(QNetworkReply *reply)
{
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    pixmap.scaled(100, 70, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // 画成圆形图片
    int width = ui->pic->width();
    int height = ui->pic->height();
    QSize size(width, height);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 14, 14);//修改这个值，可以改弧度，和直径相等就是圆形
    QPixmap image = pixmap.scaled(size);
    image.setMask(mask);


    ui->pic->setPixmap(image);
    ui->pic->setScaledContents(true);
}
void VideoItem::setPlay(int play)
{
    double tmp;
    tmp=play;
    tmp=tmp/10000;

    ui->label_4->setText(QString::number(tmp, 'f', 2)+tr("万"));
}
void VideoItem::setAuthor(QString author)
{
    ui->author->setText(author);
}
void VideoItem::setDanmaku(QString danmaku)
{
    ui->label_5->setText(danmaku);
}
void VideoItem::resizeEvent(QResizeEvent *event)
{
    int x = this->frameGeometry().width();
    int y = this->frameGeometry().height();
    ui->widget->setGeometry(5,10,x-5,y-15);
}
void VideoItem::mousePressEvent(QMouseEvent *ev)
{
    QDesktopServices::openUrl(QUrl("https://www.bilibili.com/video/"+bvid));
    emit clicked();
}
bool VideoItem::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this) {
        if(event->type() == QEvent::HoverEnter) {
            QPropertyAnimation *a1 = new QPropertyAnimation(ui->widget, "pos");
            a1->setDuration(500);
            a1->setStartValue(QPoint(5, 10));
            a1->setEndValue(QPoint(5, 3));
            a1->setEasingCurve(QEasingCurve::OutBack);
            a1->start();
            return true;
        }else if(event->type()== QEvent::HoverLeave){
            QPropertyAnimation *a1 = new QPropertyAnimation(ui->widget, "pos");
            a1->setDuration(500);
            a1->setStartValue(QPoint(5, 3));
            a1->setEndValue(QPoint(5, 10));
            a1->setEasingCurve(QEasingCurve::OutBack);
            a1->start();
        }
    }
    return QWidget::eventFilter(obj,event);
}
VideoItem::~VideoItem()
{
    QPixmapCache::clear();
    delete naManager;
    delete ui;
    naManager = NULL;
    ui = NULL;
}
