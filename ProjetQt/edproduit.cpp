#include "edproduit.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

edproduit::edproduit()
{
ref=0,nompo=" ",quantite=0,ref_article=0,prix=0;
}

edproduit::edproduit(int ref,int quantite,int ref_article,QString nompo,int prix)
{
    this-> ref=ref ;
    this->quantite=quantite ;
    this->ref_article=ref_article ;
    this->nompo=nompo;
    this->prix=prix;
}

int edproduit::getref(){return ref;}
 QString  edproduit::getnom(){return nompo;}
 int  edproduit::getquantite(){return quantite;}
 int  edproduit::getarticle(){return ref_article;}
 int  edproduit::getprix(){return prix;}
 void edproduit::setref(int ref){this->ref=ref ;}
 void edproduit::setnom(QString nompo){this->nompo=nompo ;}
 void edproduit::setquantite(int quantite){this->quantite=quantite ;}

 void edproduit::setprix(int prix){ this->prix=prix;}

bool edproduit::ajouter()
{
    QSqlQuery query;

     query.prepare("INSERT INTO edproduit (REF, nompo, QUANTITE, ref_article,PRIX) "
                   "VALUES (:ref, :nompo, :quantite, :article, :prix)");
     query.bindValue(":ref",ref);
     query.bindValue(":nompo",nompo);
     query.bindValue(":quantite",quantite);
     query.bindValue(":article",ref_article);
     query.bindValue(":prix",prix);
     return query.exec();


}
bool edproduit::supprimer(int ref)
{
     QSqlQuery query;
     query.prepare(" Delete from edproduit where ref =:ref");
     query.bindValue(0, ref);
     return query.exec();

}
QSqlQueryModel* edproduit::afficher()
{
     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT ref,prix,quantite,nompo,ref_article FROM edproduit");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nompo"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ref_article"));

     return model;
}


bool edproduit :: modifier(int ref)
{
    QSqlQuery query;
    query.prepare("UPDATE edproduit SET ref=:ref,nompo=:nompo,quantite=:quantite ,ref_article=:ref_article ,prix=:prix WHERE ref=:ref");
    query.bindValue(":ref", ref);
    query.bindValue(":nompo", nompo);
    query.bindValue(":quantite", quantite);
    query.bindValue(":ref_article", ref_article);
    query.bindValue(":prix", prix);
    return    query.exec();

}
QSqlQueryModel * edproduit::recherche(QString res)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM edproduit where ref like'"+res+"%' or nompo like'"+res+"%' or quantite like'"+res+"%' or ref_article like'"+res+"%' or prix like'"+res+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nompo"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ref_article"));
    return model;
}
QSqlQueryModel* edproduit::afficherArticle()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT ref from article");
    return model;
}
