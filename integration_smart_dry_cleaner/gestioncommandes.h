#ifndef GESTIONCOMMANDES_H
#define GESTIONCOMMANDES_H

#include <QDialog>
#include"commande.h"


namespace Ui {
class GestionCommandes;
}

class GestionCommandes : public QDialog
{
    Q_OBJECT

public:
    explicit GestionCommandes(QWidget *parent = nullptr);
    ~GestionCommandes();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_IDCom_currentIndexChanged(int index);

    void on_pdf_2_clicked();

    void on_recherche_button_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

    void on_quitter_clicked();

    void on_quitter_2_clicked();



    void on_pushButton_3_clicked();

private:
    Ui::GestionCommandes *ui;
    Commande C;
};

#endif // GESTIONCOMMANDES_H
