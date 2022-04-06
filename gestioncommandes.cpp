#include "gestioncommandes.h"
#include "ui_gestioncommandes.h"
#include"ui_passer.h"
#include <QMessageBox>
#include <QtWidgets>
#include<QSqlQuery>
#include<QDate>
#include <QTextStream>
#include <QDataStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include<QPrinter>
#include <QFileDialog>
#include"notification.h"
#include <QSystemTrayIcon>
#include"passer.h"
#include"commande.h"
#include"mainwindow.h"



GestionCommandes::GestionCommandes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionCommandes)
{
    ui->setupUi(this);
    ui->tab_com->setModel(C.afficher());
    ui->comboBox_2->setModel(C.combo_comboclient());
    ui->comboBox_3->setModel(C.combo_comboemploye());
    ui->IDCom->setModel(C.combo_comboCom());

}

GestionCommandes::~GestionCommandes()
{
    delete ui;
}


void GestionCommandes::on_pushButton_Ajouter_clicked()
{
        int ID_COM=ui->N_fact->text().toInt();
        QDate DATE_RECEP=ui->dateR->date();
        QDate DATE_LIVR=ui->dateL->date();
        int FK_CLIENT=ui->comboBox_2->currentText().toInt();
        int FK_EMPLOYE=ui->comboBox_3->currentText().toInt();
        QSqlQuery query= C.rechercherCommande(ID_COM);
        query.first();
        bool test2 = query.value(0).toBool();
        if (ID_COM == NULL)
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),QObject::tr("Le Id est obligatoire"));
        else if(test2 == true)
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),QObject::tr("Id déja existe"));
        else
        {
        Notification N;
        Commande C(ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE);
        bool test=C.ajouter();
        QMessageBox msgBox;
            if (test)
            {
                msgBox.setText("ajouter avec succes");
                ui->tab_com->setModel(C.afficher());
                ui->N_fact->clear();

            }
            else
                msgBox.setText("Echec d'Ajout");
                msgBox.exec();
    }
}
void GestionCommandes::on_supprimer_clicked()
{

    Notification N;
    C.setID_COM(ui->num_sup->text().toInt());
    QSqlQuery query= C.rechercherCommande(C.getID_COM());
    query.first();
    bool test2 = query.value(0).toBool();

    bool test=C.supprimer(C.getID_COM());
    if(C.getID_COM()==0)
     {     QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                 QObject::tr("Id Obligatoire!!\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                                 ui->num_sup->clear();
    }
    else if
            (test2==false)
             {     QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                         QObject::tr("Id n'existe pas!!\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                                          ui->num_sup->clear();
            }
    else if(test)
     {    QMessageBox::information(nullptr, QObject::tr("suppression avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                                    ui->num_sup->clear();
ui->tab_com->setModel(C.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                                    ui->num_sup->clear();
}

void GestionCommandes::on_modifier_clicked()
{
    int ID_COM=ui->num_fact2->text().toInt();
    QDate DATE_RECEP=ui->dateEdit->date();
    QDate DATE_LIVR=ui->dateEdit_2->date();
    int FK_CLIENT=ui->cl->text().toInt();
    int FK_EMPLOYE=ui->emp->text().toInt();
    QSqlQuery query= C.rechercherCommande(ID_COM);
    query.first();
    bool test2 = query.value(0).toBool();
    if (ID_COM == NULL)
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),QObject::tr("Le Id est obligatoire"));
    else if(test2 == false)
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),QObject::tr("Id n'existe pas"));
    else
    {

    Notification N;
    Commande C(ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE);
    {
        bool test=C.modifier(ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE);
        QMessageBox msgBox;
        if (test)
        {
            N.notification_modifier();
            ui->tab_com->setModel(C.afficher());
            msgBox.setText("modifier avec succes");
            ui->num_fact2->clear();



        }
        else
            msgBox.setText("Echec de modification");
            msgBox.exec();
}

}
}

void GestionCommandes::on_IDCom_currentIndexChanged(int)
{
    int id=ui->IDCom->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from COMMANDE where ID_COM=:id");
        query.bindValue(":id",id);
        if(query.exec())
            {
                while(query.next())
                      {
               ui->num_fact2->setText(query.value(0).toString());
               ui->dateEdit->setDate(query.value(1).toDate());
               ui->dateEdit_2->setDate(query.value(2).toDate());
               ui->cl->setText(query.value(3).toString());
               ui->emp->setText(query.value(4).toString());
                }
}
}

void GestionCommandes::on_pdf_2_clicked()
{
    QString strStream;
     QTextStream out(&strStream);

     const int rowCount = ui->tab_com->model()->rowCount();
     const int columnCount = ui->tab_com->model()->columnCount();


     out <<  "<html>\n"
         "<head>\n"
         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg("strTitle")
         <<  "</head>\n"
         "<body bgcolor=#ffffff link=#5000A0>\n"

         //     "<align='right'> " << datefich << "</align>"
         "<center> <H1>Liste Des Commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

     // headers
     out << "<thead><tr bgcolor=#f0f0f0> <th>numero</th>";
     for (int column = 0; column < columnCount; column++)
         if (!ui->tab_com->isColumnHidden(column))
             out << QString("<th>%1</th>").arg(ui->tab_com->model()->headerData(column, Qt::Horizontal).toString());
     out << "</tr></thead>\n";

     // data table
     for (int row = 0; row < rowCount; row++)
     {
         out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
         for (int column = 0; column < columnCount; column++)
         {
             if (!ui->tab_com->isColumnHidden(column))
             {
                 QString data = ui->tab_com->model()->data(ui->tab_com->model()->index(row, column)).toString().simplified();
                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
             }
         }
         out << "</tr>\n";
     }
     out <<  "</table> </center>\n"
         "</body>\n"
         "</html>\n";

     QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
     if (QFileInfo(fileName).suffix().isEmpty())
     {
         fileName.append(".pdf");
     }

     QPrinter printer (QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);

     QTextDocument doc;
     doc.setHtml(strStream);
     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
     doc.print(&printer);

}

void GestionCommandes::on_recherche_button_clicked()
{
    QDate date_recep=ui->dateEdit_3->date();
    QDate date_livr=ui->dateEdit_4->date();
    int id_com=ui->lineEdit_6->text().toInt();
    int id_cl=ui->lineEdit_8->text().toInt();
    int id_emp=ui->lineEdit_7->text().toInt();


    QSqlQueryModel *rech=C.rechercher_multi(date_recep,date_livr,id_com,id_cl,id_emp);
    if(rech)
    {
        ui->tab_com->setModel(rech);
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();

    }
    else
    {
        ui->tab_com->setModel(C.afficher());
    }
}

void GestionCommandes::on_radioButton_clicked()
{
    ui->tab_com->setModel(C.trier_commande_id());
}

void GestionCommandes::on_radioButton_2_clicked()
{
     ui->tab_com->setModel(C.trier_commande_dtr("date_recep"));
}

void GestionCommandes::on_radioButton_3_clicked()
{
    ui->tab_com->setModel(C.trier_commande_dtr("date_livr"));
}

void GestionCommandes::on_pushButton_clicked()
{
    passer p;
    p.setModal(true);
    hide();
    p.exec();
}





void GestionCommandes::on_pushButton_2_clicked()
{
     ui->tab_com->setModel(C.afficher());
}

void GestionCommandes::on_quitter_clicked()
{
    int reponse = QMessageBox::question(this, "Interrogatoire", "Madame ou monsieur Es-que vous etes sur que vous voulez quitter?", QMessageBox ::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::critical(this, "Au revoir", "A la prochaine !");
            close();
        }
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::information(this, "Bonjour", "Et bienvenue!");
        }
}

void GestionCommandes::on_quitter_2_clicked()
{
    int reponse = QMessageBox::question(this, "Interrogatoire", "Madame ou monsieur Es-que vous etes sur que vous voulez quitter?", QMessageBox ::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::critical(this, "Au revoir", "A la prochaine !");
            close();
        }
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::information(this, "Bonjour", "Et bienvenue!");
        }
}

