#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QShortcut>
#include <libssh/libssh.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ssh_session session;
    bool message_label_shown = false;
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
