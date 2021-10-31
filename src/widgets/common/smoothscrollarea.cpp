#include "smoothscrollarea.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QWheelEvent>
#include <QDebug>
SmoothScrollArea::SmoothScrollArea(QWidget *parent) : QScrollArea(parent)
{
    vScrollBar->setOrientation(Qt::Orientation::Vertical); //将滚动条设置为纵向
    setVerticalScrollBar(vScrollBar); //设置纵向滚动条
}

void SmoothScrollArea::wheelEvent(QWheelEvent *e)
{
    //当捕获到事件后，调用相对滚动的槽函数
    vScrollBar->scroll(e->angleDelta().y());
}
