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
    QSqlQueryModel * model= new QSqlQueryModel();
                    model->setQuery("select * from CONTENIR where FK_AR=1 ");
                    int ref=model->rowCount();
                    model->setQuery("select * from CONTENIR where FK_AR=2 ");
                    int ref1=model->rowCount();
                    model->setQuery("select * from CONTENIR where FK_AR=3 ");
                    int ref2=model->rowCount();
                    model->setQuery("select * from CONTENIR where FK_AR=4 ");
                    int ref3=model->rowCount();
                    model->setQuery("select * from CONTENIR where FK_AR=5 ");
                    int ref4=model->rowCount();
                    model->setQuery("select * from CONTENIR where FK_AR=6 ");
                    int ref5=model->rowCount();
                    int total=ref+ref1+ref2+ref3+ref4+ref5;
                    QString a=QString("Robe  "+QString::number((ref*100)/total,'f',2)+"%" );
                    QString b=QString("Costume "+QString::number((ref1*100)/total,'f',2)+"%" );
                    QString c=QString("Couverture "+QString::number((ref2*100)/total,'f',2)+"%" );
                     QString d=QString("Rideaux"+QString::number((ref3*100)/total,'f',2)+"%" );
                      QString e=QString("Tapis "+QString::number((ref4*100)/total,'f',2)+"%" );
                       QString f=QString("Chemise "+QString::number((ref5*100)/total,'f',2)+"%" );
                    QPieSeries *series = new QPieSeries();
                    series->append(a,ref);
                    series->append(b,ref1);
                    series->append(c,ref2);
                    series->append(d,ref3);
                    series->append(e,ref4);
                    series->append(f,ref5);
            if (ref!=0)
            {QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());}
            if ( ref1!=0)
            {
                     // Add label, explode and define brush for 2nd slice
                     QPieSlice *slice1 = series->slices().at(1);
                     //slice1->setExploded();
                     slice1->setLabelVisible();
            }
            if(ref2!=0)
            {
                     // Add labels to rest of slices
                     QPieSlice *slice2 = series->slices().at(2);
                     //slice1->setExploded();
                     slice2->setLabelVisible();
            }
            if(ref3!=0)
            {
                     // Add labels to rest of slices
                     QPieSlice *slice3 = series->slices().at(3);
                     //slice1->setExploded();
                     slice3->setLabelVisible();
            }
            if(ref4!=0)
            {
                     // Add labels to rest of slices
                     QPieSlice *slice4 = series->slices().at(4);
                     //slice1->setExploded();
                     slice4->setLabelVisible();
            }
            if(ref5!=0)
            {
                     // Add labels to rest of slices
                     QPieSlice *slice5 = series->slices().at(5);
                     //slice1->setExploded();
                     slice5->setLabelVisible();
            }
                    // Create the chart widget
                    QChart *chart = new QChart();
                    // Add data to chart with title and hide legend
                    chart->addSeries(series);
                    chart->setTitle("Pourcentage Par Article :Nombre Des Articles "+ QString::number(total));
                    chart->legend()->hide();
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
    int FK_AR=ui->comboBox_4->currentText().toInt();
    int FK_COM=ui->comboBox_5->currentText().toInt();
    Notification N;
    Contenir Con(PRIX,QUANTITE,FK_AR,FK_COM);
    bool test1=Con.ajouter();
    QMessageBox msgBox;
        if (test1)
        {
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
    QString strStream;
     QTextStream out(&strStream);

     const int rowCount = ui->tableView->model()->rowCount();
     const int columnCount = ui->tableView->model()->columnCount();

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
         if (!ui->tableView->isColumnHidden(column))
             out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
     out << "</tr></thead>\n";

     // data table
     for (int row = 0; row < rowCount; row++)
     {
         out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
         for (int column = 0; column < columnCount; column++)
         {
             if (!ui->tableView->isColumnHidden(column))
             {
                 QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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




void passer::on_pushButton_2_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        QString TT = QDateTime::currentDateTime().toString();
        out <<"<html>\n"
              "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << "<title>ERP - COMmANDE LIST<title>\n "
            << "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Commandes ******"+TT+" </strong></h1>"
               +"<img src=C:/Users/HP/Desktop/Capture d’écran 2022-04-06 014158.jpg/>"
            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
              "</br> </br>";
        // headers
        out << "<thead><tr bgcolor=#d6e5ff>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView->isColumnHidden(column)) {
                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

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
         {    QMessageBox::information(nullptr, QObject::tr("suppression avec succes"),
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
