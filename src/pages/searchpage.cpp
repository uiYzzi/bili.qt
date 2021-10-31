#include "searchpage.h"
#include "ui_searchpage.h"

SearchPage::SearchPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchPage)
{
    ui->setupUi(this);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setFlow(QListView::LeftToRight);
    ui->listWidget->setResizeMode(QListView::Adjust);
}
void SearchPage::addItem(QString author,QString title,QUrl cover,QString bvid,int play,QString danmaku)
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

}
void SearchPage::updateUI(QString type,QString keyword,int page)
{
    int n=ui->listWidget->count();
    for(int i=0;i<n;i++)
    {
        QListWidgetItem *item = ui->listWidget->takeItem(0);
        QWidget *card = ui->listWidget->itemWidget(item);
        delete card;
        delete item;
    }
    AppAPI *api=new AppAPI;
    connect(api,&AppAPI::finished,[=](QJsonArray Videos){
        for(int i=0;i < Videos.size();i++)
        {

           QJsonObject info = Videos.at(i).toObject();
           addItem(info["author"].toString(),info["title"].toString(),QUrl("https:"+info["pic"].toString()),info["bvid"].toString(),info["play"].toInt(),info["danmaku"].toString());
        }
        disconnect(api,&AppAPI::finished,nullptr,nullptr);
        api->deleteLater();
    });
    api->getSearchVideo(type,keyword,page);
    ui->title->setText(tr("搜索")+"  "+keyword);
}
SearchPage::~SearchPage()
{
    delete ui;
}
