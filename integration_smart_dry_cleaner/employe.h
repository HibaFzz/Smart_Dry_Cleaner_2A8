#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include<QSqlQueryModel>
#include <QSqlQuery>

class employe
{
public:
    employe();
    employe(int,QString,QString,QString,QString,int,int);
    int getid();
     QString getNomemp();
     QString getPrenomemp();
     QString getdate_naissance();
     QString getmail();
     int getsalaire();
     int getNum_tel();
     void setid(int);
     void setNomemp(QString);
     void setPrenomemp(QString);
     void setdate_naissance(QString);
     void setmail(QString);
     void setsalaire(int);
     void setNum_tel(int);
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int);
     bool rechercher_arduino(QByteArray );

     QSqlQueryModel * trie_employeQ();
      QSqlQueryModel * trie_employeN();
     QSqlQueryModel * rechercher_Nom(QString Nom);
     QSqlQueryModel * rechercher_Prenom(QString Prenom);
     QSqlQueryModel * rechercher_Num_tel(int Num_tel);
     QSqlQueryModel * rechercher_NomPrenom(QString Nom, QString Prenom);
     QSqlQueryModel * rechercher_NomNum_tel(QString Nom, int Num_tel);
     QSqlQueryModel * rechercher_Num_telPrenom(int Num_tel, QString Prenom);
     QSqlQueryModel * rechercher_tous( QString Nom,QString Prenom, int Num_tel);
     QSqlQueryModel * afficher_historique();
     QByteArray * rechercher_arduino();
     QSqlQueryModel * statistiques();



     private:
     int id,salaire,Num_tel;
     QString Nomemp,Prenomemp,date_naissance,mail;
};

#endif // EMPLOYE_H
