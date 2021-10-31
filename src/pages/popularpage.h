#ifndef POPULARPAGE_H
#define POPULARPAGE_H

#include <QWidget>
#include "src/backend/bili-api/appapi.h"
#include "src/widgets/common/videoitem.h"
namespace Ui {
class PopularPage;
}

class PopularPage : public QWidget
{
    Q_OBJECT

public:
    void updateUI();
    bool first=true;
    explicit PopularPage(QWidget *parent = nullptr);
    ~PopularPage();
private slots:
private:
    QStringList bvids;
    void addItem(QString author,QString title,QUrl cover,QString bvid,int play);
    Ui::PopularPage *ui;
};

#endif // POPULARPAGE_H
