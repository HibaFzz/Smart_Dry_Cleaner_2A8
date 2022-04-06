#include "contenir.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>
#include<QMessageBox>



Contenir::Contenir()
{

}
    Contenir::Contenir(float PRIX,int QUANTITE,int FK_AR,int FK_COM)
    {this ->PRIX=PRIX; this ->QUANTITE=QUANTITE; this ->FK_AR=FK_AR; this ->FK_COM=FK_COM;}
    float Contenir::getPrix(){return PRIX;}
    int Contenir::getQuantite(){return QUANTITE;}
    int Contenir::getFK_COM(){return FK_COM;}
    void Contenir::setPrix(float PRIX){this ->PRIX=PRIX;}
    void Contenir::setQuantite(int QUANTITE){this ->QUANTITE=QUANTITE;}
    void Contenir::setFK_COM(int FK_COM){this ->FK_COM=FK_COM;}

    bool Contenir::ajouter()
    {


        QString prix= QString::number(PRIX) ;
        QString qte= QString::number(QUANTITE) ;
        QString fk_ar= QString::number(FK_AR) ;
        QString fk_com= QString::number(FK_COM) ;

        QSqlQuery query;
        query.prepare("INSERT INTO CONTENIR (PRIX, QUANTITE,FK_AR,FK_COM)VALUES (:PRIX,:QUANTITE, :FK_AR, :FK_COM)");
              query.bindValue(":PRIX", prix);
              query.bindValue(":QUANTITE",qte);
              query.bindValue(":FK_AR", fk_ar);
              query.bindValue(":FK_COM", fk_com);

             return query.exec();

}
    QSqlQueryModel* Contenir::afficher()
    {
      QSqlQueryModel *model=new QSqlQueryModel();

           model->setQuery("SELECT* FROM CONTENIR");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("Prix_Unitaire"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ref_Article"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_Commande"));


      return model ;
    }
    bool Contenir::supprimer(int FK_COM)
    {
              QSqlQuery query;
              query.prepare("delete from CONTENIR where FK_COM=:FK_COM");
              query.bindValue(0, FK_COM);


              return query.exec();
    }
    QSqlQueryModel* Contenir::combo_comboCom()
     {

         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("select ID_COM from COMMANDE ");
         return model;
     }
    QSqlQueryModel* Contenir::combo_comboAr()
     {

         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("select REF_AR from ARTICLE ");
         return model;
     }
    QSqlQueryModel *Contenir::trier_commande_id(){
        QSqlQuery *qry=new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("select * from CONTENIR order by Fk_COM ASC");
        qry->exec();
        model->setQuery(*qry);
        return model;
    }
    QSqlQueryModel *Contenir::trier_prix(){
        QSqlQuery *qry=new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("select * from CONTENIR order by PRIX ASC");
        qry->exec();
        model->setQuery(*qry);
        return model;
    }
    QSqlQueryModel * Contenir::rechercher_duo(int FK_AR,int FK_COM)
     {
         QSqlQuery *query=new QSqlQuery();
         QString id_string = QString::number(FK_COM);
         QString id_Ar = QString::number(FK_AR);
         query->prepare("select * from CONTENIR where FK_AR=:FK_AR or FK_COM =:FK_COM ");
         query->bindValue(":FK_COM",id_string);
         query->bindValue(":FK_AR",id_Ar);
         query->exec();
         QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery(*query);
         return model;
     }
