#include "logincontroller.h"

LoginController::LoginController()
{

}

bool LoginController::verifyLogin(QString username,QString password){
    QString username_db = "admin";
    QString password_db = "password";
    if(username_db == username&&password_db == password){
        return true;
    }else{
        return false;

    }
}
