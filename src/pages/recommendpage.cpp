#include "recommendpage.h"
#include "ui_recommendpage.h"

RecommendPage::RecommendPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecommendPage)
{
    ui->setupUi(this);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setFlow(QListView::LeftToRight);
    ui->listWidget->setResizeMode(QListView::Adjust);
    connect(ui->listWidget, SIGNAL(reachedBottom()), this, SLOT(onReachedBottom()));
    ui->pushButton->setIcon(QIcon::fromTheme(":/icon/light/refresh.svg"));
}
void RecommendPage::addItem(QString author,QString title,QUrl cover,QString bvid,int play,QString danmaku)
{
    if(!bvids.contains(bvid))
    {
        VideoItem *vi=new VideoItem(this);
        vi->setAuthor(author);
        vi->setTitle(title);
        vi->setPlay(play);
        vi->setBvid(bvid);
        vi->setCover(cover);
        vi->setDanmaku(danmaku);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240, 250));
        ui->listWidget->addItem(pItem);
        ui->listWidget->setItemWidget(pItem, vi);
        bvids<<bvid;
    }

}

void RecommendPage::updateUI()
{
    AppAPI *api=new AppAPI(this);
    connect(api,&AppAPI::finished,[=](QJsonArray Videos){
        for(int i=0;i < Videos.size();i++)
        {
           QJsonObject info = Videos.at(i).toObject();
           addItem(info["name"].toString(),info["title"].toString(),QUrl(info["cover"].toString()),"av"+info["param"].toString(),info["play"].toInt(),info["desc"].toString());
        }
        disconnect(api,&AppAPI::finished,nullptr,nullptr);
        api->deleteLater();
    });
    api->getRecommendVideo();
}
void RecommendPage::onReachedBottom()
{
    updateUI();
}
RecommendPage::~RecommendPage()
{
    delete ui;
}

void RecommendPage::on_pushButton_clicked()
{
    ui->listWidget->vScrollBar->scrollTop();
    bvids.clear();
    int n=ui->listWidget->count();
    for(int i=0;i<n;i++)
    {
        QListWidgetItem *item = ui->listWidget->takeItem(0);
        QWidget *card = ui->listWidget->itemWidget(item);
        delete card;
        card  = NULL;
        delete item;
        item  = NULL;
    }
    ui->listWidget->clear();
    updateUI();
}
