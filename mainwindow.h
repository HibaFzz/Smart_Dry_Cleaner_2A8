#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<commande.h>
#include<contenir.h>

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



    void on_Statistiques_clicked();

    void on_quitter_clicked();

private:
    Ui::MainWindow *ui;
    Commande C;
    Contenir Con;

};

#endif // MAINWINDOW_H
