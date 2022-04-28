#ifndef LOGIN_H
#define LOGIN_H
#include<QString>

class login
{
public:
    login();
    login(QString,QString);
    QString getUsername();
    QString getPwd();
    void setUsername(QString);
    void setPwd(QString);
    bool ajouter ();
     QString USERNAME,PWD;

};

#endif // LOGIN_H
