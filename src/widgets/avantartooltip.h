#ifndef AVANTARTOOLTIP_H
#define AVANTARTOOLTIP_H

#include <QWidget>
#include <DBlurEffectWidget>
DWIDGET_USE_NAMESPACE
namespace Ui {
class AvantarToolTip;
}

class AvantarToolTip : public DBlurEffectWidget
{
    Q_OBJECT

public:
    void m_move(int x,int y);
    explicit AvantarToolTip(QWidget *parent = nullptr);
    ~AvantarToolTip();

private:
    QRect m_rect;
    Ui::AvantarToolTip *ui;
private slots:
    bool eventFilter(QObject *,QEvent *);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // AVANTARTOOLTIP_H
