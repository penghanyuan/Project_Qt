#include "login.h"
#include "ui_login.h"
#include <QSettings>
#include <QDebug>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->username->setFocus();
    loadcfg();
    ui->username->setText(login_username);
    ui->password->setText(login_password);

}

Login::~Login()
{
    delete ui;
}

void Login::on_connect_clicked()
{
    AccountController accountController;
    if(login_username.isEmpty()&&login_password.isEmpty())
    {
        login_username = ui->username->text();
        login_password = ui->password->text();
    }
    if(accountController.verifyLogin(login_username,login_password)){
        savecfg();
        accept();
    }
    else{
            QMessageBox::warning(this, tr("Waring"),
                                         tr("user name or password error!"),
                                         QMessageBox::Ok);
            ui->password->clear();
            ui->password->setFocus();
            login_username.clear();
            login_password.clear();
        }



}

void Login::savecfg()
{
    QString path = "login.ini";
    QSettings *config = new QSettings(path, QSettings::IniFormat);
    login_username = ui->username->text();
    login_password = ui->password->text();
    config->setValue("username", login_username);
    config->setValue("password", login_password);
    delete config;

}


void Login::loadcfg()
{
    QString path = "login.ini";
    QSettings *config = new QSettings(path, QSettings::IniFormat);
    login_username = config->value("username").toString();
    login_password = config->value("password").toString();

    delete config;


}
