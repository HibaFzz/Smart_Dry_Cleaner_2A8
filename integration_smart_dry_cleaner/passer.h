#ifndef PASSER_H
#define PASSER_H

#include <QDialog>
#include"contenir.h"


namespace Ui {
class passer;
}

class passer : public QDialog
{
    Q_OBJECT

public:
    explicit passer(QWidget *parent = nullptr);
    ~passer();

private slots:
    void on_pushButton_Ajouter_2_clicked();

    void on_pushButton_clicked();

    void on_pdf_clicked();

    void on_Statistiques_clicked();



    void on_supprimer_clicked();

    void on_Atualiser_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_quitter_clicked();

    void on_recherche_button_clicked();



private:
    Ui::passer *ui;
    Contenir Con;
};

#endif // PASSER_H
