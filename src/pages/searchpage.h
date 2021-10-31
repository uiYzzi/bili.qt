#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include "src/backend/bili-api/appapi.h"
#include "src/widgets/common/videoitem.h"
namespace Ui {
class SearchPage;
}

class SearchPage : public QWidget
{
    Q_OBJECT

public:
    void updateUI(QString type,QString keyword,int page);
    explicit SearchPage(QWidget *parent = nullptr);
    ~SearchPage();

private slots:
private:
    void addItem(QString author,QString title,QUrl cover,QString bvid,int play,QString danmaku);
    Ui::SearchPage *ui;
};

#endif // SEARCHPAGE_H
