#include "login.h"
#include "ui_login.h"

#include <iostream>
#include "dashboard.h"
#include "ssh_get_info.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    std::string username = ui->username_linedit->text().toStdString();
    std::string password = ui->password_linedit->text().toStdString();
    std::string ip = ui->ip_linedit->text().toStdString();
    int port = ui->port_linedit->text().toInt();
    try {
        session = establish_session(username,password,ip,port);
        Dashboard* dashboard = new Dashboard(session,this);
        dashboard->showFullScreen();
        this->hide();

    }  catch (int) {
        ui->username_linedit->clear();
        ui->password_linedit->clear();
        ui->ip_linedit->clear();

        if(!message_label_shown){
            QLabel* message_label = new QLabel("Connection failed!");
            message_label->setStyleSheet("color:rgb(196,77,88);");
            message_label->setAlignment(Qt::AlignCenter);
            ui->login_widget->layout()->addWidget(message_label);
            message_label_shown = true;
        }
    }
}
