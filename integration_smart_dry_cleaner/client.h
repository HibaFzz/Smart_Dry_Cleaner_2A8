#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include<QSqlQueryModel>
class client
{
public:
    client();

    client(int,QString,QString,QString,int);
    int getid();
     QString getNomC(){return NOMC;}
     QString getPrenomC(){return PRENOMC;}
     QString getmail(){return MAIL;}
     int getNum_tel(){return NUMTEL;}
     void setid(int);
     void setNomC(QString);
     void setPrenomC(QString);
     void setmail(QString);
     void setNum_tel(int);
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int);
     bool controlsaisiechar(QString,QString);
     bool controlSaisieNumVide(int , QString );
     bool controlSaisieCharVide (QString,QString);
     QSqlQueryModel* rechercher(int);
     QSqlQueryModel * triN();
     QSqlQueryModel * triI();
     QSqlQueryModel * triNum();
     QSqlQueryModel * statistiques();



private:
int IDC,NUMTEL;
QString NOMC,PRENOMC,MAIL;
};

#endif // CLIENT_H
