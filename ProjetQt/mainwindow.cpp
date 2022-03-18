#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FonctionInisialisation();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::FonctionInisialisation(){

       //stackedWidget Formulaire Ajout produit
       ui->stackedWidget_2->setCurrentIndex(0);
        //Combobox article id
        ui->p_article->setModel(prod.afficherArticle());
        ui->p_article_m->setModel(prod.afficherArticle());

       //stackedWidget Main (Affichage) produit
       ui->stackedWidget->setCurrentIndex(0);
       // Affichage des produits :
       proxy = new QSortFilterProxyModel();

       proxy->setSourceModel(prod.afficher());
       proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
       ui->tabProduit->setModel(proxy);

       //Controle saisie du formulaire ajout Produit :
       ui->p_ref->setValidator(new QIntValidator(0,9999999,this));
       ui->p_nom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*") , this ));
       ui->p_prix->setValidator(new QIntValidator(0,9999999,this));
       ui->p_quantite->setValidator(new QIntValidator(0,9999999,this));
       ui->p_prix->setValidator(new QIntValidator(0,9999999,this));
       ui->p_ref->clear();
       ui->p_nom->clear();
       ui->p_prix->clear();
       ui->p_quantite->clear();
       ui->p_article->setCurrentIndex(0);
       //Controle saisie du formulaire Modification :
       ui->p_ref_m->setValidator(new QIntValidator(0,9999999,this));
      // ui->p_intitule_m->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]*") , this ));
       ui->p_prix_m->setValidator(new QIntValidator(0,9999999,this));
       ui->p_quantite_m->setValidator(new QIntValidator(0,9999999,this));
       ui->p_prix_m->setValidator(new QIntValidator(0,9999999,this));
       ui->p_ref_m->clear();
       ui->p_nom_m->clear();
       ui->p_prix_m->clear();
       ui->p_quantite_m->clear();
       ui->p_article_m->setCurrentIndex(0);




}

void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_annuler_ajout_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_p_ajouterBtn_clicked()
{

    QString ref = ui->p_ref->text();
    int reft = ref.toInt();
    QString nom = ui->p_nom->text();
    int quantite = ui->p_quantite->text().toInt();
    int prix = ui->p_prix->text().toInt();
    int article =ui->p_article->currentText().toInt();
    if (reft<=0){
        QMessageBox::critical(nullptr, QObject::tr("Produit ajout"),
                                      QObject::tr("Reference invalide! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    else if(nom.size()<=2){
        QMessageBox::critical(nullptr, QObject::tr("Produit ajout"),
                                      QObject::tr("Nom invalide! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);
        }
    else if(quantite<0){
        QMessageBox::critical(nullptr, QObject::tr("Produit ajout"),
                                      QObject::tr("Quantite invalide! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    else if(prix<=0){
        QMessageBox::critical(nullptr, QObject::tr("Produit ajout"),
                                      QObject::tr("Prix invalide! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }

    else{
 qDebug() <<"Article " << article;
    edproduit prod(reft,quantite,article,nom,prix);
    bool validation = prod.ajouter();
    if (validation){
        FonctionInisialisation();
        QMessageBox::information(nullptr, QObject::tr("Produit ajout"),
                                      QObject::tr("Produit ajouté.\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Produit ajout"),
                                      QObject::tr("Ref deja utiliser!! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    }
}

void MainWindow::on_p_modifierBtn_clicked()
{
    int ref = ui->p_ref_m->text().toInt();
       QString nom = ui->p_nom_m->text();
       int quantite = ui->p_quantite_m->text().toInt();
       int prix = ui->p_prix_m->text().toInt();
       int article =ui->p_article_m->currentText().toInt();
        if(nom.size()<=2){
           QMessageBox::critical(nullptr, QObject::tr("Produit Modification"),
                                         QObject::tr("Nom invalide! .\n"
                                                     "Click Ok to exit."), QMessageBox::Ok);

       }
       else if(quantite<=0){
           QMessageBox::critical(nullptr, QObject::tr("Produit Modification"),
                                         QObject::tr("Quantite invalide! .\n"
                                                     "Click Ok to exit."), QMessageBox::Ok);

       }
       else if(prix<=0){
           QMessageBox::critical(nullptr, QObject::tr("Produit Modification"),
                                         QObject::tr("Prix invalide! .\n"
                                                     "Click Ok to exit."), QMessageBox::Ok);

       }

       else{
        edproduit prod(ref,quantite,article,nom,prix);
       bool validation = prod.modifier(ref);
       if (validation){
           ui->stackedWidget->setCurrentIndex(0);
           FonctionInisialisation();
           QMessageBox::information(nullptr, QObject::tr("Produit Modification"),
                                         QObject::tr("Produit Modifié.\n"
                                                     "Click Ok to exit."), QMessageBox::Ok);

       }
       else{
           QMessageBox::critical(nullptr, QObject::tr("Produit Modification"),
                                         QObject::tr("Erreur!! .\n"
                                                     "Click Ok to exit."), QMessageBox::Ok);

       }
       }
}

void MainWindow::on_p_recherche_textChanged(const QString &arg1)
{
    if(arg1.size()<=0){
           FonctionInisialisation();
       }
       else{
           ui->tabProduit->setModel(prod.recherche(arg1));
        }
}

void MainWindow::on_tabProduit_activated(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(1);
       QString val=ui->tabProduit->model()->data(index).toString();
           QSqlQuery qry;
           qry.prepare("Select nompo,quantite,prix from edproduit where  ref='"+val+"'");
           if(qry.exec())
           {
               while(qry.next())
                       {
                           ui->p_ref_m->setText(val);
                           ui->p_nom_m->setText(qry.value(0).toString());
                           ui->p_quantite_m->setText(qry.value(1).toString());
                           ui->p_prix_m->setText(qry.value(2).toString());
                           ui->p_ref_m->setEnabled(false);
                       }
           }
}

void MainWindow::on_p_supprimerBtn_clicked()
{
    QString ref = ui->p_ref_m->text();
        bool test = prod.supprimer(ref.toInt());
        if (test){
            FonctionInisialisation();
            ui->stackedWidget->setCurrentIndex(0);
            QMessageBox::information(nullptr, QObject::tr("Produit Suppression"),
                                          QObject::tr("Produit supprimer!! .\n"
                                                      "Click Ok to exit."), QMessageBox::Ok);

        }
        else{
            FonctionInisialisation();
            QMessageBox::critical(nullptr, QObject::tr("Produit Suppression"),
                                          QObject::tr("Erreur Ref!! .\n"
                                                      "Click Ok to exit."), QMessageBox::Ok);

        }
}

