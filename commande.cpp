#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>
#include<QMessageBox>
#include<QFileDialog>
#include<QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include<QPrinter>
#include <QFileDialog>
#include<QPdfWriter>
#include<QSqlRecord>
Commande::Commande()
{

}
    Commande::Commande(int ID_COM,QDate DATE_RECEP,QDate DATE_LIVR,int FK_CLIENT,int FK_EMPLOYE)
    {this ->ID_COM=ID_COM; this ->DATE_RECEP=DATE_RECEP; this ->DATE_LIVR=DATE_LIVR;this ->FK_CLIENT=FK_CLIENT; this ->FK_EMPLOYE=FK_EMPLOYE;}
    int Commande::getID_COM(){return ID_COM;}
    QDate Commande::getDATE_RECEP(){return DATE_RECEP;}
    QDate Commande::getDATE_LIVR(){return DATE_LIVR;}
    void Commande::setID_COM(int ID_COM){this ->ID_COM=ID_COM;}
    void Commande::setDATE_RECEP(QDate DATE_RECEP){this ->DATE_RECEP=DATE_RECEP;}
    void Commande::setDATE_LIVR(QDate DATE_LIVR){this ->DATE_LIVR=DATE_LIVR;}
    bool Commande::ajouter()
    {

        QString idcom_string= QString ::number(ID_COM) ;
        QString idcl_string= QString::number(FK_CLIENT) ;
        QString idemp_string= QString::number(FK_EMPLOYE) ;
        QSqlQuery query;
        query.prepare("INSERT INTO COMMANDE (ID_COM, DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE)VALUES (:ID_COM,:DATE_RECEP, :DATE_LIVR, :FK_CLIENT,:FK_EMPLOYE)");
              query.bindValue(0, idcom_string);
              query.bindValue(1, DATE_RECEP);
              query.bindValue(2, DATE_LIVR);
              query.bindValue(3, idcl_string);
              query.bindValue(4, idemp_string);

             return query.exec();


    }
    bool Commande::supprimer(int ID_COM)
    {
              QSqlQuery query;
              query.prepare("delete from COMMANDE where ID_COM=:ID_COM");
              query.bindValue(0, ID_COM);


              return query.exec();
    }
    QSqlQueryModel* Commande::afficher()
    {
      QSqlQueryModel *model=new QSqlQueryModel();

           model->setQuery("SELECT* FROM COMMANDE");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Commmande"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Reception"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Livraison"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("Id Client"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("Id Employe"));

      return model ;
    }
    bool Commande::modifier(int ID_COM,QDate DATE_RECEP,QDate DATE_LIVR,int FK_CLIENT,int FK_EMPLOYE)
        {
        QSqlQuery query;
        QString idcom_string= QString::number(ID_COM);
        QString idcl_string= QString::number(FK_CLIENT);
        QString idemp_string= QString::number(FK_EMPLOYE);
        query.prepare("UPDATE COMMANDE set ID_COM=:ID_COM,DATE_RECEP=:DATE_RECEP,DATE_LIVR=:DATE_LIVR,FK_CLIENT=:FK_CLIENT,FK_EMPLOYE=:FK_EMPLOYE" " WHERE ID_COM=:ID_COM");
        query.bindValue(":ID_COM", idcom_string);
        query.bindValue(":DATE_RECEP", DATE_RECEP);
        query.bindValue(":DATE_LIVR", DATE_LIVR);
        query.bindValue(":FK_CLIENT", idcl_string);
        query.bindValue(":FK_EMPLOYE", idemp_string);


        return    query.exec();
        }

    QSqlQuery Commande::rechercherCommande(int ID_COM)
    {

        QSqlQuery query;
        QString id_string = QString::number(ID_COM);
        query.prepare("SELECT * FROM COMMANDE WHERE ID_COM=:ID_COM");
        query.bindValue(":ID_COM",id_string);
        query.exec();
        return   query;

    }
   QSqlQueryModel * Commande::rechercher_multi(QDate DATE_RECEP,QDate DATE_LIVR,int ID_COM,int FK_EMPLOYE,int FK_CLIENT)
    {
        QSqlQuery *query=new QSqlQuery();
        QString id_string = QString::number(ID_COM);
        QString id_emp = QString::number(FK_EMPLOYE);
        QString id_cl = QString::number(FK_CLIENT);
        query->prepare("select * from COMMANDE where DATE_RECEP=:DATE_RECEP and DATE_LIVR=:DATE_LIVR or ID_COM=:ID_COM or FK_EMPLOYE =:FK_EMPLOYE or FK_CLIENT=:FK_CLIENT");
        query->bindValue(":DATE_RECEP",DATE_RECEP);
        query->bindValue(":DATE_LIVR",DATE_LIVR);
        query->bindValue(":ID_COM",id_string);
        query->bindValue(":FK_EMPLOYE",id_emp);
        query->bindValue(":FK_CLIENT",id_cl);

        query->exec();
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(*query);
        return model;
    }
    QSqlQueryModel *Commande::trier_commande_id(){
        QSqlQuery *qry=new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("select * from COMMANDE order by ID_COM ASC");
        qry->exec();
        model->setQuery(*qry);
        return model;
    }
    QSqlQueryModel *Commande::trier_commande_dtr(QString date){

        QSqlQuery *query=new QSqlQuery();
           QSqlQueryModel *model=new QSqlQueryModel();
           query->prepare("select * from COMMANDE order by "+date+"");
           query->exec();
           model->setQuery(*query);
           return model;
    }


   QSqlQueryModel* Commande::combo_comboCom()
    {

        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("select ID_COM from COMMANDE ");
        return model;
    }

    QSqlQueryModel* Commande::combo_comboclient(){

        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("select IDCl from CLIENTS ");
        return model;
    }


    QSqlQueryModel* Commande::combo_comboemploye(){

        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("select IDEMP from EMPlOYE");
        return model;
    }
