#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Projet_2A8");
db.setUserName("molka");//inserer nom de l'utilisateur
db.setPassword("esprit8");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
