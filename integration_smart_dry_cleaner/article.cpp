#include "article.h"
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
#include<QDesktopServices>
#include <QTextStream>
#include <QPainter>
#include<QMessageBox>
article::article()
{

    ref=prix=0;
    nom_ar="";
    type_ar="";
}
article::article(int c,QString p,QString q,float f)
{
    this ->ref=c;
    this ->nom_ar=p;
    this ->type_ar=q;
    this ->prix=f;


}
//getters
int article:: getRef(){return ref;}
QString article::getNom_ar(){return nom_ar;}
QString article::getType_ar(){return type_ar;}
float article::getPrix(){return  prix;}
//setters
void article::setRef(int c){this->ref=c;}
void article::setNom_ar(QString p){this->nom_ar=p;}
void article::setType_ar(QString q){this->type_ar=q;}
void article::setPrix(float f){this->prix=f;}

bool article::ajouter()
{
    QSqlQuery query ;

    QString ref_string =QString::number(ref);
    QString prix_string =QString::number(prix);

    //preparation de lexecution (requete)
    query.prepare("INSERT INTO articl (ref, nom_ar, type_ar,prix)"
                  "VALUES (:ref, :nom_ar, :type_ar, :prix)");
    // creation des variables liées
    query.bindValue(0,ref_string);
    query.bindValue(1,nom_ar);
    query.bindValue(2,type_ar);
    query.bindValue(3,prix_string);
    QSqlQuery qry;
            QDateTime dateTime=QDateTime::currentDateTime();

            QString date=dateTime.toString();

            qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',:dateTime)");
            qry.bindValue(":dateTime",dateTime);


            qry.exec();
    // envoie de requete pour l'executer ;

    return query.exec();
}
QSqlQueryModel * article::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from articl");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_ar"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_ar"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

    return model;
    }

bool article::supprimer(int ref)
{
QSqlQuery query;
QString ref_string =QString::number(ref);
query.prepare("Delete from articl where ref=:ref");
query.bindValue(":ref",ref_string);
QSqlQuery qry;
        QDateTime dateTime=QDateTime::currentDateTime();

        QString date=dateTime.toString();

        qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',:dateTime)");
        qry.bindValue(":dateTime",dateTime);


        qry.exec();
return    query.exec();
}

bool article::modifier(int ref,QString nom_ar,QString type_ar ,float prix)
{
QSqlQuery query;
QString ref_string =QString::number(ref);
QString prix_string =QString::number(prix);
query.prepare("update articl set nom_ar=:nom_ar,type_ar=:type_ar,prix=:prix where ref=:ref");
query.bindValue(":ref", ref_string);
query.bindValue(":nom_ar", nom_ar);
query.bindValue(":type_ar", type_ar);
query.bindValue(":prix", prix_string);
QSqlQuery qry;
        QDateTime dateTime=QDateTime::currentDateTime();

        QString date=dateTime.toString();

        qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modifier Article',:dateTime)");
        qry.bindValue(":dateTime",dateTime);


        qry.exec();

return    query.exec();
}

QSqlQueryModel * article::tri_prixcroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM articl ORDER BY prix ASC ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_ar"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_ar"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));

            return model;
}
QSqlQueryModel * article::tri_prixdecroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM articl ORDER BY prix DESC ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_ar"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_ar"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
            return model;
}

QSqlQueryModel * article::tri_quantitecroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM articl ORDER BY nom_ar ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_ar"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_ar"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
      return model;
}

QSqlQueryModel * article::tri_quantitedecroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM articl ORDER BY nom_ar DESC ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_ar"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_ar"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
            return model;
}


QSqlQueryModel* article::rechercher(int ref)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(ref);
        QString recher="select * from ARTICl where REF like '%"+res+"%' ";
        model->setQuery(recher);
        return model;


}
QSqlQueryModel* article::rechercherprix(int prix)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(prix);
        QString recher="select * from ARTICl where PRIX like '%"+res+"%' ";
        model->setQuery(recher);
        return model;

}


QSqlQueryModel* article::rechercher_Nom(QString nom_ar)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from articl where nom_ar  like '%"+nom_ar+"%' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_ar"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_ar"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
        return model;

}
void article::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery f;
    int i=0;
    f.exec("select nom_ar from articl");
    while (f.next())
    {
        QString identifiant =f.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}
QSqlQueryModel * article::articlesplusdemande()
{}

