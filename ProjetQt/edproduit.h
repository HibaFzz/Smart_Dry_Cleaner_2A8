#ifndef EDPRODUIT_H
#define EDPRODUIT_H

#include <QString>
#include <QSqlQueryModel>
class edproduit
{
public:
    edproduit();
        edproduit(int,int,int,QString,int);
        int getref();
         QString getnom();
         int getquantite();
         int getarticle();
         int getprix();
         void setref(int);
         void setquantite(int);
         void setarticle(int);
         void setnom(QString);
         void setprix(int);
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool modifier(int ref);

        QSqlQueryModel *recherche(QString);
        QSqlQueryModel *afficherArticle();

    private:
        int ref;
        int prix;
        int quantite;
        QString nompo;
        int ref_article;
    };
#endif // EDPRODUIT_H
