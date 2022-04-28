#include "login.h"
#include<QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>
#include<QMessageBox>

login::login()
{

}
    login::login(QString USERNAME,QString PWD)
    {this ->USERNAME=USERNAME; this ->PWD=PWD;}
    QString login::getUsername(){return USERNAME;}
    QString login::getPwd(){return PWD;}
    void login::setUsername(QString USERNAME){this ->USERNAME=USERNAME;}
    void login::setPwd(QString PWD){this ->PWD=PWD;}


    bool login::ajouter()
    {

        QSqlQuery query;
        query.prepare("INSERT INTO LOGIN (USERNAME, PWD)VALUES (:USERNAME,:PWD)");
              query.bindValue(":USERNAME",USERNAME);
              query.bindValue(":PWD", PWD);
             return query.exec();

    }
