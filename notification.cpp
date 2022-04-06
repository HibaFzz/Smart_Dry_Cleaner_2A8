#include "notification.h"

#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}

void Notification::notification_ajout()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("FastDry ","un element ajouté ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimer(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("FastDry","un element Supprimé",QSystemTrayIcon::Information,15000);
}

void Notification::notification_modifier(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("FastDry ","Un element est modifié",QSystemTrayIcon::Information,15000);

}
