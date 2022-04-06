#ifndef CONTENIR_H
#define CONTENIR_H


#include<QString>
#include<QSqlQueryModel>
#include <QDate>
class Contenir
{
public:
    Contenir();
    Contenir(float,int,int,int);
    float getPrix();
    int getQuantite();
    int getFK_COM();

    void setPrix(float);
    void setQuantite(int);
    void setFK_COM(int);
    bool ajouter ();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* combo_comboAr();
    QSqlQueryModel*combo_comboCom();
    QSqlQueryModel * trier_commande_id();
    QSqlQueryModel * trier_prix();
     QSqlQueryModel * rechercher_duo(int,int);




private:
    int QUANTITE,FK_AR,FK_COM;
    float PRIX;
};

#endif // CONTENIR_H
