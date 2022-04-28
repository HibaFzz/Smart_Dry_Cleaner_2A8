#include "passer.h"
#include "ui_passer.h"
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
#include "commande.h"
#include"notification.h"
#include <QSystemTrayIcon>
#include "contenir.h"
#include"gestioncommandes.h"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSystemTrayIcon>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include "contenir.h"
#include<QSqlRecord>
#include <QDebug>
passer::passer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passer)
{
    ui->setupUi(this);

    ui->tableView->setModel(Con.afficher());
    ui->comboBox_5->setModel(Con.combo_comboCom());
    ui->comboBox_4->setModel(Con.combo_comboAr());
}

passer::~passer()
{
    delete ui;
}

void passer::on_Statistiques_clicked()
{
    QSqlQuery queryt;

        queryt.prepare("SELECT ID_COM FROM COMMANDE");
              queryt.exec();
              queryt.first();
              int groupid_equipement = queryt.record().indexOf("ID");
              queryt.prepare("SELECT count(FK_COM)FROM CONTENIR ");
              queryt.exec();
              queryt.first() ;
             int total=queryt.value(0).toInt();




    qDebug()<<queryt.value(0);
              while (queryt.next()) {


    }
    qDebug()<<queryt.value(groupid_equipement);

    //******* STAT ******
    QPieSeries *series = new QPieSeries();

    QSqlQueryModel* model;
    Contenir C;

    model=C.statistiques();
        QPieSlice *slice[10] ;
        for (int i=0;i<model->rowCount();i++) {

                float p=model->record(i).value(0).toInt();
                QString g=QString::number((model->record(i).value(0).toFloat()*100/total),'f',2)+"%";

                series->append(g+" de reference "+model->record(i).value(1).toString(),p);

                slice[i]= series->slices().at(i);
                slice[i]->setLabelVisible();

        }

                    // Create the chart widget
                    QChart *chart = new QChart();
                    // Add data to chart with title and hide legend
                    chart->addSeries(series);
                    chart->setTitle("Pourcentage Par Reference des article :Nombre Des Commande "+ QString::number(total));
                    chart->legend();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
}


void passer::on_pushButton_Ajouter_2_clicked()
{
    float PRIX=ui->N_fact_2->text().toFloat();
    int QUANTITE=ui->N_fact_3->text().toInt();
    int fk_ar=ui->comboBox_4->currentText().toInt();
    int FK_COM=ui->comboBox_5->currentText().toInt();
    Notification N;
    Contenir Con(PRIX,QUANTITE,fk_ar,FK_COM);
    bool test1=Con.ajouter();
    QMessageBox msgBox;
        if (test1)
        {
                     float total=PRIX*QUANTITE;
                     QString t = QString::number(total);
                     ui->lineEdit_4->setText(t);
                     N.notification_ajout();
                     msgBox.setText("ajouter avec succes");
                     ui->tableView->setModel(Con.afficher());


        }
        else
            msgBox.setText("Echec d'Ajout");
            msgBox.exec();
}

void passer::on_pushButton_clicked()
{
    GestionCommandes Gc;
    Gc.setModal(true);
    hide();
    Gc.exec();
}

void passer::on_pdf_clicked()
{
    QTableView tablivraison;

    QSqlQueryModel * Modal=new  QSqlQueryModel();


QSqlQuery qrt;

qrt.prepare("SELECT TO_CHAR (SYSDATE, 'MM-DD-YYYY HH24:MI:SS') FROM dual");

    QSqlQuery qry;

     qry.prepare("SELECT * FROM CONTENIR ");

     qry.exec();

     Modal->setQuery(qry);

     tablivraison.setModel(Modal);


     QString strStream;

     QTextStream out(&strStream);



     const int rowCount = tablivraison.model()->rowCount();

     const int columnCount =  tablivraison.model()->columnCount();



     const QString strTitle ="Document";



QString date= qrt.value(0).toString();

QString d_info=QDateTime::currentDateTime().toString();

     out <<  "<html>\n"

             "<img src='C:/Users/HP/Desktop/Capture d’écran 2022-04-06 014158.jpg' height='120' width='120'/>"
         "<p style=\"text-align:right\">"+d_info+"</p>"

         "<head>\n"

             "<meta Content=\"Text/html; charset=Windows-1251\">\n"

         <<  QString("<title>%1</title>\n").arg(strTitle)

         <<  "</head>\n"

         "<body bgcolor=#ffffff link=#5000A0>\n"

        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Commandes")

        <<"<br>"
       << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: black; font-weight: lighter; text-align: right;\">%1</h3>\n").arg(date)
<<"<br>"


        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

     out << "<thead><tr bgcolor=#f0f0f0>";

     for (int column = 0; column < columnCount; column++)

         if (!tablivraison.isColumnHidden(column))

             out << QString("<th>%1</th>").arg(tablivraison.model()->headerData(column, Qt::Horizontal).toString());

     out << "</tr></thead>\n";



     for (int row = 0; row < rowCount; row++) {

         out << "<tr>";

         for (int column = 0; column < columnCount; column++) {

             if (!tablivraison.isColumnHidden(column)) {

                 QString data = tablivraison.model()->data(tablivraison.model()->index(row, column)).toString().simplified();

                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

             }

         }

         out << "</tr>\n";

     }

     out <<  "</table>\n"

             "<br><br>"

             <<"<br>"

             <<"<table border=1 cellspacing=0 cellpadding=2>\n";





         out << "<thead><tr bgcolor=#f0f0f0>";



             out <<  "</table>\n"



         "</body>\n"

         "</html>\n";



     QTextDocument *document = new QTextDocument();

     document->setHtml(strStream);



     QPrinter printer;

     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);

     if (dialog->exec() == QDialog::Accepted) {



         document->print(&printer);

     }



     printer.setOutputFormat(QPrinter::PdfFormat);

     printer.setPaperSize(QPrinter::A4);

     printer.setOutputFileName("C:/Users/HP/Desktop/Commande/.pdf");

     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



     delete document;
}






void passer::on_supprimer_clicked()
{
        Notification N;
        Con.setFK_COM(ui->num_sup->text().toInt());
        bool test=Con.supprimer(Con.getFK_COM());
        if(Con.getFK_COM()==0)
         {     QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                     QObject::tr("Id Obligatoire!!\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                                     ui->num_sup->clear();
        }

        else if(test)
         {
            N.notification_supprimer();
            QMessageBox::information(nullptr, QObject::tr("suppression avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

                                       ui->tableView->setModel(Con.afficher());
                                       ui->num_sup->clear();
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                                       ui->num_sup->clear();
    }









void passer::on_Atualiser_clicked()
{
    ui->tableView->setModel(Con.afficher());
}

void passer::on_radioButton_clicked()
{
    ui->tableView->setModel(Con.trier_commande_id());
}

void passer::on_radioButton_2_clicked()
{
     ui->tableView->setModel(Con.trier_prix());
}

void passer::on_quitter_clicked()
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

void passer::on_recherche_button_clicked()
{
    int id_com=ui->lineEdit_2->text().toInt();
    int id_Ar=ui->lineEdit->text().toInt();



    QSqlQueryModel *rech=Con.rechercher_duo(id_com,id_Ar);
    if(rech)
    {
        ui->tableView->setModel(rech);
        ui->lineEdit_2->clear();
        ui->lineEdit->clear();


    }
    else
    {
        ui->tableView->setModel(Con.afficher());
    }
}



