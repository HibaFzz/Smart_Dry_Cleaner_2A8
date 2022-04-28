#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<commande.h>
#include<contenir.h>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "arduino.h"
#include "article.h"
#include "employe.h"
#include "client.h"
#include"stmp.h"
#include "notification.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:



    void on_passerCom_clicked();

    void on_GestionCom_clicked();





    void on_quitter_clicked();

    void on_GestionCom_2_clicked();

    void on_pushButton_clicked();


    void on_Connecter_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_GestionCom_6_clicked();





    void on_pushButton_Ajouter_clicked();

    void on_supprimer_2_clicked();

    void on_recu_pdf_clicked();

    void on_pushButton_7_clicked();

    void on_modifier_2_clicked();

    void on_IDCom_2_currentIndexChanged(int index);

    void on_recherche_button_clicked();

    void on_pdf_2_clicked();

    void on_Actualiser_clicked();

    void on_id_tri_clicked();

    void on_dateR_tri_clicked();

    void on_dateL_tri_clicked();

    void on_pushButton_8_clicked();


    void on_pushButton_17_clicked();




    void update_label();   // slot permettant la mise à jour du label état de Rfid/ servo-moteur,
                           // ce slot est lancé à chaque réception d'un message de Arduino
    void on_ajouter_c_clicked();

    void on_retour_clicked();

    void on_passeC_clicked();

    void on_recu_pdf_2_clicked();

    void on_recherche_button_3_clicked();

    void on_Statistiques_3_clicked();

    void on_supprimer_5_clicked();

    void on_pdf_clicked();

    void on_home_clicked();

    void on_home_2_clicked();

    void on_quitter_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_Atualiser_clicked();

    void on_quitter_9_clicked();

    void on_quitter_13_clicked();

    void on_Arduino_clicked();

    void on_Arduino_2_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_trid_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_Statistiques_4_clicked();

    void on_pushButton_supprimer_3_clicked();

    void on_retour_3_clicked();

    void on_GestionCom_3_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_supprimer_4_clicked();

    void on_pushButton_supprimer_5_clicked();

    void on_historique_clicked();

    void on_rechercher_P_clicked();

    void on_radioButton_TRInProd_clicked();

    void on_radioButton_TRIqProd_clicked();

    void on_retour_4_clicked();

    void on_GestionCom_8_clicked();

    void on_pushButton_ajouter_6_clicked();

    void on_pushButton_supprimer_8_clicked();

    void on_pushButton_supprimer_9_clicked();


    void on_rechercher_P_3_clicked();

    void on_radioButton_TRIqProd_4_clicked();

    void on_radioButton_TRInProd_3_clicked();

    void on_radioButton_TRIqProd_5_clicked();

    void on_radioButton_TRIqProd_3_clicked();

    void on_Statistiques_5_clicked();

    void on_GestionCom_4_clicked();

    void on_retour_8_clicked();

    void on_Statistiques_6_clicked();

    void on_quitter_2_clicked();

    void on_GestionCom_7_clicked();

    void on_quitter_5_clicked();

    void on_quitter_6_clicked();

    void on_quitter_12_clicked();

    void on_quitter_7_clicked();

    void on_quitter_8_clicked();

    void on_quitter_10_clicked();

    void on_quitter_16_clicked();

    void on_pushButton_2_clicked();

    void on_Qrcode_2_clicked();

    void on_radioButton_TRInProd_4_clicked();



    void on_radioButton_TRInProd_5_clicked();


    void on_pushButton_9_clicked();

    void on_browseBtn_clicked();

    void on_sendBtn_clicked();
    void mailSent(QString);

private:
    Ui::MainWindow *ui;
    Commande C;
    Contenir Con;
    Arduino A;
    QByteArray refus; // variable contenant les données reçues
     article temparticle;
     employe E;
     Notification N;
     client Cl;
     QStringList files;
      QByteArray data;
};

#endif // MAINWINDOW_H
