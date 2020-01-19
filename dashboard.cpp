#include "dashboard.h"
#include "ui_dashboard.h"
#include "ssh_get_info.h"

#include <iostream>

Dashboard::Dashboard(ssh_session session, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
//    QString test_text = QString::fromStdString(send_command(session,"ls -l"));
//    ui->bla->setText(test_text);
    ui->image_sel->pixmap()->scaledToWidth(ui->frame->size().width());
}


Dashboard::~Dashboard()
{
    delete ui;
}
