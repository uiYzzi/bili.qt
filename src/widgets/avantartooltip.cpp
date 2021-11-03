#include "avantartooltip.h"
#include "ui_avantartooltip.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QDebug>
AvantarToolTip::AvantarToolTip(QWidget *parent) :
    DBlurEffectWidget(parent),
    ui(new Ui::AvantarToolTip)
{
    ui->setupUi(this);
    installEventFilter(this);
    setFocus();
    setFixedSize(310,300);
}

AvantarToolTip::~AvantarToolTip()
{
    delete ui;
}
void AvantarToolTip::m_move(int x,int y)
{
    m_rect.setX(x);
    m_rect.setY(y);
    move(x,y);
    return;
}
bool AvantarToolTip::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == this) {
        if (event->type() == QEvent::FocusOut)
        {
            this->hide();

        }
    }
        return QWidget::eventFilter(watched,event);
}
void AvantarToolTip::mouseMoveEvent(QMouseEvent *event)
{
    setGeometry(m_rect);
}
