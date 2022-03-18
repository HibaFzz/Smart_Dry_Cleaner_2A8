#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirConnexion()
{
    bool testOuverture=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("medmansour");
    db.setUserName("medmansour");
    db.setPassword("medmansour");
    if (db.open())
        testOuverture=true;
    return  testOuverture;
}
void connexion::fermerConnexion()
{db.close();}
