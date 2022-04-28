#include "employe.h"

#include <QSqlQuery>
#include<QDebug>
#include<QObject>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDate>
#include <QTimer>
#include <QDateTime>

employe::employe()
{
id=0;salaire=0;Num_tel=0;
Nomemp=" "; Prenomemp=" ";date_naissance=" ";mail=" ";
}
employe::employe(int id,QString Nomemp,QString Prenomemp,QString date_naissance,QString mail,int salaire,int Num_tel)
{this->id=id;this->Nomemp=Nomemp;this->Prenomemp=Prenomemp;this->date_naissance=date_naissance;this->mail=mail;this->salaire=salaire;this->Num_tel=Num_tel;}
int employe:: getid(){return id;}
 QString employe::getNomemp(){return Nomemp;}
 QString employe::getPrenomemp(){return Prenomemp;}
 QString employe::getdate_naissance(){return date_naissance;}
 QString employe::getmail(){return mail;}
 int employe::getsalaire(){return salaire;}
 int employe::getNum_tel(){return Num_tel;}
 void employe::setid(int id){this->id=id;}
 void employe::setNomemp(QString Nomemp){this->Nomemp=Nomemp;}
 void employe::setPrenomemp(QString Prenomemp){this->Prenomemp=Prenomemp;}
 void employe::setdate_naissance(QString date_naissance){this->date_naissance=date_naissance;}
 void employe::setmail(QString mail){this->mail=mail;}
 void employe::setsalaire(int salaire){this->salaire=salaire;}
 void employe::setNum_tel(int Num_tel){this->Num_tel=Num_tel;}


  bool employe::ajouter()
  {bool test=false;
      QSqlQuery query;
      QString id_String=QString::number(id);
       QString salaire_String=QString::number(salaire);
       QString Num_tel_string=QString::number(Num_tel);

            query.prepare("INSERT INTO EMPLOYE (id, Nomemp, Prenomemp,date_naissance,mail,salaire,Num_tel) "
                          "VALUES (:id, :Nomemp, :prenomemp ,:date_naissance,:mail,:salaire,:Num_tel)");
            query.bindValue(0, id_String);
            query.bindValue(1, Nomemp);
            query.bindValue(2, Prenomemp);
            query.bindValue(3, date_naissance);
             query.bindValue(4, mail);
             query.bindValue(5, salaire_String);
             query.bindValue(6, Num_tel_string);
             QSqlQuery qry;
                     QDateTime dateTime=QDateTime::currentDateTime();

                     QString date=dateTime.toString();

                     qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion employe',:dateTime)");
                     qry.bindValue(":dateTime",dateTime);


                     qry.exec();
            query.exec();

      return test;
  }
  bool employe::supprimer(int ID)
  {
      QSqlQuery query;
              QString id_string=QString::number(ID);
              query.prepare(" Delete from EMPLOYE where ID=:ID");
              query.bindValue(0,id_string);
                      QSqlQuery qry;
                              QDateTime dateTime=QDateTime::currentDateTime();

                              QString date=dateTime.toString();

                              qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression employe',:dateTime)");
                              qry.bindValue(":dateTime",dateTime);


                              qry.exec();
             return query.exec();


  }

  QSqlQueryModel* employe::afficher()
  {
      QSqlQueryModel* model=new QSqlQueryModel();
      model->setQuery("SELECT* FROM EMPLOYE");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Num_tel"));

      return model;


  }

  bool employe ::modifier(int id)
  {
      bool test=false;
      QSqlQuery query;
      QString id_string=QString::number(id);
      QString Num_tel_string=QString::number(Num_tel);
      QString salaire_string=QString::number(salaire);





     query.prepare(" UPDATE EMPLOYE SET ID=:ID ,NOMEMP=:NOMEMP,PRENOMEMP=:PRENOMEMP,DATE_NAISSANCE=:DATE_NAISSANCE,MAIL=:MAIL, SALAIRE=:SALAIRE,NUM_TEL=:NUM_TEL WHERE ID=:ID");
     query.bindValue(":ID", id_string);
     query.bindValue(":NOMEMP",Nomemp);
     query.bindValue(":PRENOMEMP",Prenomemp);
     query.bindValue(":DATE_NAISSANCE",date_naissance);
      query.bindValue(":MAIL",mail);
      query.bindValue(":SALAIRE",salaire_string);
      query.bindValue(":NUM_TEL",Num_tel_string);
      QSqlQuery qry;
              QDateTime dateTime=QDateTime::currentDateTime();

              QString date=dateTime.toString();

              qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification employe',:dateTime)");
              qry.bindValue(":dateTime",dateTime);


              qry.exec();
     return query.exec();
     return test;

  }
  QSqlQueryModel *  employe::rechercher_Nom(QString Nom)
       {
           QSqlQuery qry;
           qry.prepare("select * from EMPLOYE where NOMEMP=:NOMEMP");
           qry.bindValue(":NOMEMP",Nom);
           qry.exec();

           QSqlQueryModel *model= new QSqlQueryModel;
           model->setQuery(qry);


          return model;


       }

      QSqlQueryModel *  employe::rechercher_Prenom(QString Prenom)
       {
           QSqlQuery qry;
           qry.prepare("select * from employe where PRENOMEMP =:PRENOMEMP");
           qry.bindValue(":PRENOMEMP",Prenom);
           qry.exec();

           QSqlQueryModel *model= new QSqlQueryModel;
           model->setQuery(qry);


          return model;


       }

      QSqlQueryModel * employe::rechercher_Num_tel(int Num_tel)
       {
           QSqlQuery qry;
           qry.prepare("select * from employe where Num_tel=:Num_tel");
           qry.bindValue(":Num_tel",Num_tel);
           qry.exec();
           QSqlQueryModel *model= new QSqlQueryModel;
           model->setQuery(qry);


          return model;


      }

      QSqlQueryModel * employe::rechercher_NomPrenom(QString Nom, QString Prenom)
      {
          QSqlQuery *qry= new QSqlQuery();
          qry->prepare("select * from employe where PRENOMEMP=:PRENOMEMP and NOMEMP=:NOMEMP");
          qry->bindValue(":PRENOMEMP",Prenom);
          qry->bindValue(":NOMEMP",Nom);
          qry->exec();


             QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery(*qry);
              return model;


      }
      QSqlQueryModel *employe:: rechercher_NomNum_tel(QString Nom, int Num_tel)
      {QSqlQuery *qry= new QSqlQuery();
          qry->prepare("select * from employe where NOMEMP=:NOMEMP and Num_tel=:Num_tel ");
          qry->bindValue(":Num_tel",Num_tel);
          qry->bindValue(":NOMEMP",Nom);
          qry->exec();


             QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery(*qry);
              return model;
      }

       QSqlQueryModel *employe:: rechercher_Num_telPrenom(int Num_tel, QString Prenom)
       {
           QSqlQuery *qry= new QSqlQuery();
               qry->prepare("select * from employe where PRENOMEMP=:PRENOMEMP and Num_tel=:Num_tel");
               qry->bindValue(":Num_tel",Num_tel);
               qry->bindValue(":PRENOMEMP",Prenom);
               qry->exec();


                  QSqlQueryModel *model = new QSqlQueryModel();
                  model->setQuery(*qry);
                   return model;
       }


      QSqlQueryModel *employe:: rechercher_tous( QString Nom,QString Prenom, int Num_tel)
      {
          QSqlQuery *qry= new QSqlQuery();
              qry->prepare("select * from employe where NOMEMP=:NOMEMP and PRENOMEMP=:PRENOMEMP and Num_tel=:Num_tel  ");
              qry->bindValue(":Num_tel",Num_tel);
              qry->bindValue(":PRENOMEMP",Prenom);
              qry->bindValue(":NOMEMP",Nom);
              qry->exec();


                 QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery(*qry);
                  return model;
      }
      QSqlQueryModel *employe:: trie_employeQ()
          {
              QSqlQueryModel *model=new QSqlQueryModel();
              model->setQuery("select * from employe order by NOMEMP" );
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMEMP"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMEMP"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("Num_tel"));

           return model;

          }

          QSqlQueryModel *employe:: trie_employeN()
          {
              QSqlQueryModel *model=new QSqlQueryModel();

              model->setQuery("select * from employe order by salaire" );

              model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMEMP"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMEMP"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("Num_tel"));


           return model;

          }
          QSqlQueryModel * employe::afficher_historique()
          {
              QSqlQueryModel * model=new QSqlQueryModel();

              model->setQuery("select * from HISTORIQUE");
              model->setHeaderData(0,Qt::Horizontal,QObject::tr("Activite"));
              model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date et Heure"));


              return model;
          }
          bool employe::rechercher_arduino(QByteArray data)
          {

              QSqlQueryModel *model=new QSqlQueryModel();
              QSqlQuery query;
              //QString res = QString::number(data);
              query.prepare("SELECT * FROM  employe WHERE id ="+data);
              //query.bindValue(":data",data.toStdString());
              query.exec();
              model->setQuery(query);


                  return model->rowCount()>=1;
             }
          QSqlQueryModel* employe::statistiques(){


              QSqlQueryModel* model=new QSqlQueryModel();
              model->setQuery("SELECT count(*),FK_EMPLOYE FROM COMMANDE group by FK_EMPLOYE ");

              return model;
          }

