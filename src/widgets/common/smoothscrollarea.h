#ifndef SMOOTHSCROLLAREA_H
#define SMOOTHSCROLLAREA_H

#include <QWidget>
#include <QScrollArea>
#include "smoothscrollbar.h"
class SmoothScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit SmoothScrollArea(QWidget *parent = nullptr);
private:
    SmoothScrollBar* vScrollBar=new SmoothScrollBar(); //纵向滚动条
    void wheelEvent(QWheelEvent* e); //捕获鼠标滚轮事件
};

#endif // SMOOTHSCROLLAREA_H
