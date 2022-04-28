#include "client.h"
#include <QString>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include<QDateTime>
client::client()
{
    IDC=0;

    NOMC="";

    PRENOMC="";

    MAIL="";

    NUMTEL=0;


}
client::client(int IDC,QString NOMC,QString PRENOMC,QString MAIL,int NUMTEL)

{

    this->IDC=IDC;
    this->NOMC=NOMC;
    this->PRENOMC=PRENOMC;
    this->MAIL=MAIL;
    this->NUMTEL=NUMTEL;


 }
int client::getid(){return IDC;}
void client::setid(int IDC){this->IDC=IDC;}

bool client::ajouter()

{

    QSqlQuery query;

     QString id_String=QString::number(IDC);
      QString num_String=QString::number(NUMTEL);

    query.prepare("INSERT INTO CLIENTS ( IDC,NOMC, PRENOMC,MAIL,NUMTEL) " "VALUES (:IDC,:NOM, :PRENOMC,:MAIL,:NUMTEL)");
    query.bindValue(0, id_String);
    query.bindValue(1, NOMC);
    query.bindValue(2, PRENOMC);
    query.bindValue(3, MAIL);
    query.bindValue(4,NUMTEL);
    QSqlQuery qry;
            QDateTime dateTime=QDateTime::currentDateTime();

            QString date=dateTime.toString();

            qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Client',:dateTime)");
            qry.bindValue(":dateTime",dateTime);


            qry.exec();






    return    query.exec();

}
QSqlQueryModel* client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM CLIENTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom_client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_Tel"));

    return model;


}
bool client::supprimer(int IDC)
{
    QSqlQuery query;
    query.prepare("delete from CLIENTS where IDC=:IDC");
    query.bindValue(0, IDC);
    QSqlQuery qry;
            QDateTime dateTime=QDateTime::currentDateTime();

            QString date=dateTime.toString();

            qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Client',:dateTime)");
            qry.bindValue(":dateTime",dateTime);


            qry.exec();


    return query.exec();

    return    query.exec();
}
bool client ::modifier(int IDC)
{
    bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(IDC);
    QString Num_tel_string=QString::number(NUMTEL);






   query.prepare(" UPDATE CLIENTS SET IDC=:IDC ,NOMC=:NOMC,PRENOMC=:PRENOMC,MAIL=:MAIL,NUMTEL=:NUMTEL WHERE IDC=:IDC");
   query.bindValue(":IDC", id_string);
   query.bindValue(":NOMC",NOMC);
   query.bindValue(":PRENOMC",PRENOMC);
   query.bindValue(":MAIL",MAIL);
   query.bindValue(":NUMTEL",Num_tel_string);
   QSqlQuery qry;
           QDateTime dateTime=QDateTime::currentDateTime();

           QString date=dateTime.toString();

           qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modifier Client',:dateTime)");
           qry.bindValue(":dateTime",dateTime);


           qry.exec();
   return query.exec();
   return test;

}
bool client::controlsaisiechar(QString saisi,QString type){
    if(saisi.contains(QRegExp("^[A-Za-z ]+$")))
    {
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ID"),
                    QObject::tr("Le %1 contient un Caractére non valid.\n"
                                "Click Cancel to exit.").arg(type), QMessageBox::Cancel);
        return false;
    }


}
bool client::controlSaisieNumVide(int num,QString numm)
{

       if(std::to_string(num).length()==8)
               {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Numéro"),
                    QObject::tr("Le %1 doit avoir 8 chiffre .\n"
                                "Click Cancel to exit.").arg(numm), QMessageBox::Cancel);
        return false;
    }

}

bool client::controlSaisieCharVide(QString prenom,QString prenomm){

 if(prenom.length()!=0)
 {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("IDC"),
                    QObject::tr("Le champs de %1 est vide.\n"
                                "Click Cancel to exit.").arg(prenomm), QMessageBox::Cancel);
        return false;
    }

}
QSqlQueryModel* client::rechercher(int IDC)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(IDC);
        QString recher="select * from CLIENTS where IDC like '%"+res+"%' ";
        model->setQuery(recher);
        return model;
}

QSqlQueryModel* client::triN()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM CLIENTS ORDER BY NOMC");
           return model;
}
QSqlQueryModel* client::triI()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM CLIENTS ORDER BY IDC");
           return model;
}
QSqlQueryModel* client::triNum()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM CLIENTS ORDER BY NUMTEL");
           return model;
}
QSqlQueryModel* client::statistiques(){


    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT count(*),FK_CLIENT FROM COMMANDE group by FK_CLIENT ");

    return model;
}


