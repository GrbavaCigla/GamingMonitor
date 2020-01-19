#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <libssh/libssh.h>

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(ssh_session session, QWidget *parent = nullptr);
    ~Dashboard();

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
