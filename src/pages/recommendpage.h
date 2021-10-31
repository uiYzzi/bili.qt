#ifndef RECOMMENDPAGE_H
#define RECOMMENDPAGE_H

#include <QWidget>
#include <QListWidgetItem>
#include "src/backend/bili-api/appapi.h"
#include "src/widgets/common/videoitem.h"
namespace Ui {
class RecommendPage;
}

class RecommendPage : public QWidget
{
    Q_OBJECT

public:
    void updateUI();
    explicit RecommendPage(QWidget *parent = nullptr);
    ~RecommendPage();

private slots:
    void onReachedBottom();
    void on_pushButton_clicked();
private:
    QStringList bvids;
    void addItem(QString author,QString title,QUrl cover,QString bvid,int play,QString danmaku);
    Ui::RecommendPage *ui;
};

#endif // RECOMMENDPAGE_H
