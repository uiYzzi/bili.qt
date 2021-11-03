#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <DDialog>
DWIDGET_USE_NAMESPACE

namespace Ui {
class LoginDialog;
}

class LoginDialog : public DDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
