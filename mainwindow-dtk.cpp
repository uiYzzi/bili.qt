#include "mainwindow-dtk.h"
#include "ui_mainwindow-dtk.h"

MainWindow::MainWindow(QWidget *parent) :
    DBlurEffectWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->titlebar->setBackgroundTransparent(true);
    ui->titlebar->setMenuVisible(false);//去除dtk标题栏菜单
    setMaskAlpha(220);
    setMaskColor(QColor("#F3F3F3"));
    auto *defaultShadow = new QGraphicsDropShadowEffect();
    defaultShadow->setBlurRadius(14.0);
    defaultShadow->setColor(QColor(0, 0, 0, 30));
    defaultShadow->setOffset(0, 0);
    ui->mainpage->setGraphicsEffect(defaultShadow);
    this->setStyleSheet("#mainpage{background-color: rgba(249,249,249,0.8);border-radius:14px;}\
                        QWidget#leftbar QPushButton{text-align: left;padding-left: 10px;background-color:transparent;}\
                        QWidget#leftbar QPushButton:hover{text-align: left;padding-left: 10px;background-color:#eAeAeA;border:0px;border-radius:8px;}\
                        QWidget#leftbar QPushButton:checked{text-align: left;padding-left: 10px;background-color:#e2e2e2;border:0px;border-radius:8px;}\
                        QLabel#cardtitle,QLabel#title {color:#000000}\
                        ");

    //初始化标题栏控件
    ui->titlebar->setIcon(QIcon::fromTheme(":/icon/logo.png"));
    QWidget *w_titlebar = new QWidget(this);
    QHBoxLayout *ly_titlebar = new QHBoxLayout(this);
    w_titlebar->setLayout(ly_titlebar);
    QLabel *title=new QLabel(this);
    title->setText(tr("哔哩"));
    ly_titlebar->addWidget(title);
    ly_titlebar->addSpacing(10);
    ly_titlebar->addStretch();
    ly_titlebar->addWidget(searchEdit);
    ly_titlebar->addStretch();

    AppAPI *api=new AppAPI;
    QObject::connect(api,&AppAPI::finished,[=](QJsonArray searchDefaultWords){
        if(searchDefaultWords.size()>0)
        {
            searchEdit->setPlaceHolder(searchDefaultWords.at(0).toObject().value("data").toObject().value("show_name").toString());
            searchEdit->setPlaceholderText(searchDefaultWords.at(0).toObject().value("data").toObject().value("show_name").toString());
        }
        disconnect(api,&AppAPI::finished,nullptr,nullptr);
        api->deleteLater();
    });

    api->getSearchDefaultWords();


    ui->titlebar->setCustomWidget(w_titlebar);

    //侧边栏按钮
    int i=0;
    while (i<ui->buttonGroup->buttons().size()) {
        ui->buttonGroup->buttons()[i]->setIcon(QIcon::fromTheme(":/icon/light/"+QString::number(i)+".svg"));
        connect(ui->buttonGroup->buttons()[i],&QPushButton::toggled,[=](){
            updateUi(i);
        });
        i++;
    }
    //搜索事件
     connect(searchEdit, &DSearchEdit::returnPressed, this, [=]()
     {
         QString searchtext = searchEdit->text();
         if(!searchtext.isEmpty())
         {
             qDebug() << searchEdit->text();
             ui->searchpage->updateUI("video",searchtext,1);
             ui->stackedWidget->setCurrentIndex(2);

         }else {

         }
         this->setFocus();
     });

    //推荐界面
    ui->recommendpage->updateUI();
}
void MainWindow::initPage(int now)
{
    switch (now) {
        case 1:
               if(ui->popularpage->first==true)
               {
                   ui->popularpage->updateUI();
               }
               break;
    }
}
//刷新界面
void MainWindow::updateUi(int now)
{
    initPage(now);
    ui->stackedWidget->setCurrentIndex(now);
}
MainWindow::~MainWindow()
{
    delete searchEdit;
    delete ui;
}
