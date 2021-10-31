#ifndef MAINWINDOWDTK_H
#define MAINWINDOWDTK_H

#include <QMainWindow>
#include <DBlurEffectWidget>
#include <DTitlebar>
#include <DSearchEdit>
#include <QGraphicsDropShadowEffect>
#include <QThread>
#include "src/backend/bili-api/appapi.h"
#include <QPushButton>
DWIDGET_USE_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public DBlurEffectWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
private:
    void setAvantar(QPixmap pi);
    QPushButton *avantarButton;
    void initPage(int now);
    void updateUi(int now);
    DSearchEdit *searchEdit=new DSearchEdit;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOWDTK_H
