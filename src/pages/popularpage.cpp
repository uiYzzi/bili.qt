#include "popularpage.h"
#include "ui_popularpage.h"

PopularPage::PopularPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopularPage)
    {
        ui->setupUi(this);
        ui->listWidget->setViewMode(QListView::IconMode);
        ui->listWidget->setFlow(QListView::LeftToRight);
        ui->listWidget->setResizeMode(QListView::Adjust);
    }
    void PopularPage::addItem(QString author,QString title,QUrl cover,QString bvid,int play)
    {
        if(!bvids.contains(bvid))
        {
            VideoItem *vi=new VideoItem(this);
            vi->setAuthor(author);
            vi->setTitle(title);
            vi->setPlay(play);
            vi->setBvid(bvid);
            vi->setCover(cover);
            QListWidgetItem* pItem = new QListWidgetItem();
            pItem->setSizeHint(QSize(240, 250));
            ui->listWidget->addItem(pItem);
            ui->listWidget->setItemWidget(pItem, vi);
            bvids<<bvid;
        }

    }

    void PopularPage::updateUI()
    {
        first=false;
        AppAPI *api=new AppAPI;
        connect(api,&AppAPI::finished,[=](QJsonArray Videos){
            for(int i=0;i < Videos.size();i++)
            {
               QJsonObject info = Videos.at(i).toObject();
               addItem(info["author"].toString(),info["title"].toString(),QUrl(info["pic"].toString()),info["bvid"].toString(),info["play"].toInt());
            }
            disconnect(api,&AppAPI::finished,nullptr,nullptr);
            api->deleteLater();
        });
        api->getPopularVideo();
    }
PopularPage::~PopularPage()
{
    delete ui;
}
