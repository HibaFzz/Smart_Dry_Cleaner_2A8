#ifndef COMMANDE_H
#define COMMANDE_H

#include<QString>
#include<QSqlQueryModel>
#include <QDate>
class Commande
{
public:
    Commande();
    Commande(int,QDate,QDate,int,int);
    int getID_COM();
    QDate getDATE_RECEP();
    QDate getDATE_LIVR();
    void setID_COM(int);
    void setDATE_RECEP(QDate);
    void setDATE_LIVR(QDate);
    bool ajouter ();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,QDate,QDate,int,int);
    QSqlQuery rechercherCommande(int);
    QSqlQueryModel* combo_comboclient();
    QSqlQueryModel* combo_comboemploye();
    QSqlQueryModel*combo_comboCom();
    QSqlQueryModel * rechercher_multi(QDate,QDate,int,int,int);
    QSqlQueryModel * trier_commande_id();
    QSqlQueryModel * trier_commande_dtr(QString);

    /*QSqlQueryModel * trier_commande_dtl(QDate);*/


private:
    int ID_COM,FK_CLIENT,FK_EMPLOYE;
    QDate DATE_RECEP;QDate DATE_LIVR;
};

#endif // COMMANDE_H
