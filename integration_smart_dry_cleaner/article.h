#ifndef ARTICLE_H
#define ARTICLE_H
#include<QString>
#include<QSqlQueryModel>

class article
{
    //attribut
    int ref;
    QString nom_ar;
    QString type_ar;
    float prix;
public:
    //construc
    article();
    article(int,QString,QString,float);
    //getters
    int getRef();
    QString getNom_ar();
    QString getType_ar();
     float getPrix();

    //setters
    void setRef(int c);
    void setNom_ar(QString p);
    void setType_ar(QString q);
    void setPrix(float f);
         //ajouter afficher supprimer (methode de base )
    bool ajouter ();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,float);
    QSqlQueryModel * tri_prixdecroissant();
       QSqlQueryModel * tri_prixcroissant();
         QSqlQueryModel * tri_quantitecroissant();
         QSqlQueryModel * tri_produitsoldecroissant();
         QSqlQueryModel * tri_quantitedecroissant();
         QSqlQueryModel * tri_produitsoldedecroissant();

        QSqlQueryModel* rechercher(int );

    QSqlQueryModel* rechercherprix(int );

QSqlQueryModel* rechercherquantite(QString );
 QSqlQueryModel * rechercher_Nom(QString Nom);
void statistique(QVector<double>* ticks,QVector<QString> *labels);
QSqlQueryModel * articlesplusdemande();
};

#endif // ARTICLE_H
