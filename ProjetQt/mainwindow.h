#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSortFilterProxyModel>
#include <QSqlQuery>
#include "edproduit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QSortFilterProxyModel *proxy;
private slots:
    void FonctionInisialisation();

    void on_pushButton_clicked();

    void on_annuler_ajout_clicked();

    void on_p_supprimerBtn_clicked();
    void on_p_ajouterBtn_clicked();
    void on_p_modifierBtn_clicked();

    void on_p_recherche_textChanged(const QString &arg1);

    void on_tabProduit_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
     edproduit prod;
};
#endif // MAINWINDOW_H
