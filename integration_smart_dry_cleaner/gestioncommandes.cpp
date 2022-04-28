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
#include "commande.h"
#include"notification.h"
#include <QSystemTrayIcon>
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
#include"login.h"
#include<QSqlRecord>
#include"arduino.h"
#include"article.h"
#include"client.h"
#include<QDebug>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
#include<QTimer>
#include<QDebug>
#include<QSvgRenderer>
#include <qrcode.h>
#include <vector>
#include<QDirModel>
#include"qrcode.h"
using qrcodegen::QrCode;




GestionCommandes::GestionCommandes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionCommandes)
{
    ui->setupUi(this);
    ui->comboBox_10->setModel(C.combo_comboclient());
    ui->comboBox_11->setModel(C.combo_comboemploye());
    ui->tab_com_4->setModel(C.afficher());
    ui->dateR_5->setDate(QDate::currentDate());
    ui->dateL_5->setDate(QDate::currentDate().addDays(3));



}

GestionCommandes::~GestionCommandes()
{
    delete ui;
}



void GestionCommandes::on_GestionCom_6_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void GestionCommandes::on_GestionCom_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionCommandes::on_GestionCom_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionCommandes::on_passerCom_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void GestionCommandes::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionCommandes::on_pushButton_Ajouter_5_clicked()
{
    int ID_COM=ui->N_fact_5->text().toInt();
    QDate DATE_RECEP=ui->dateR_5->date();
    QDate DATE_LIVR=ui->dateL_5->date();
    int FK_CLIENT=ui->comboBox_10->currentText().toInt();
    int FK_EMPLOYE=ui->comboBox_11->currentText().toInt();
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
            N.notification_ajout();
            msgBox.setText("ajouter avec succes");
            ui->tab_com_4->setModel(C.afficher());
            ui->N_fact_5->clear();

        }
        else
            msgBox.setText("Echec d'Ajout");
            msgBox.exec();
}
}

void GestionCommandes::on_recu_pdf_5_clicked()
{

    QString strStream;
     QTextStream out(&strStream);
     QString d_info=QDate::currentDate().toString("dd.MM.yyyy");

    int ID_COM=ui->N_fact_5->text().toInt();

    QString DATE_RECEP=ui->dateR_5->text();
    QString DATE_LIVR=ui->dateL_5->text();
    int FK_CLIENT=ui->comboBox_10->currentText().toInt();
    int FK_EMPLOYE=ui->comboBox_11->currentText().toInt();
    QPdfWriter pdf("C:/Users/HP/Desktop/Pdf.pdf");
    QPainter painter(&pdf);

    painter.setPen(Qt::black);
    painter.setFont(QFont("FastDry", 50));
    painter.drawText(1600,4000,"Recu de Commade");
    painter.setFont(QFont("FastDry", 16));
    painter.drawText(200,400,d_info);
    painter.drawText(200,900,"Ariana ,Tunisie");
    painter.drawText(200,1400,"Mail:FastDry@gmail.com");
    painter.drawText(200,1900,"TEL:51010101");
    painter.drawText(200,2400,"¨Pressing :FastDry");

    painter.setPen(Qt::black);

    painter.setFont(QFont("Cambria", 50));
    //painter.drawText(1100,2000,afficheDC);
    painter.drawRect(100,100,7300,2600);

    painter.drawPixmap(QRect(7500,70,2600,2600),QPixmap("C:/Users/HP/Desktop/Capture d’écran 2022-04-06 014158.jpg"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Cambria", 17));
    painter.drawText(200,5000,"Je soussigné le Responsable des Commandes"
                              " Certifie avoir");
    painter.drawText(200,5500,"reçu un paiement en DT de la part du client dont les infomations"
                              " suivantes:");
    painter.drawText(200,6300,"Commande N°:");
    painter.drawText(200,7100,"Date_Reception:");
    painter.drawText(200,7900,"Date_Livraison:");
    painter.drawText(200,8700,"Cient N°:");
    painter.drawText(200,9500,"Id_Employe:");
   QString id_string=QString::number(ID_COM);
   QString id_cl_string=QString::number(FK_CLIENT);
   QString emp_string=QString::number(FK_EMPLOYE);
    painter.setFont(QFont("Courier New", 18));
        painter.drawText(2400,6300,id_string);
        painter.drawText(2400,7100,DATE_RECEP);
        painter.drawText(2400,7900,DATE_LIVR);
        painter.drawText(2400,8700,id_cl_string);
        painter.drawText(2400,9500,emp_string);
        painter.setPen(Qt::red);

        painter.setFont(QFont("Cambria", 30));

         painter.setFont(QFont("Cambria", 14));
        painter.setPen(Qt::black);
        painter.drawText(2800,13000," FastDry Vous Remercie De Votre Fidelite");
         painter.setPen(Qt::black);
         painter.drawText(6000,10500,"RESPONSABLE DES COMMANDES & DES CLIENTS");

int reponse=QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse==1)
    {
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
   else
    {
        painter.end();
    }
}

void GestionCommandes::on_passeC_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void GestionCommandes::on_recherche_button_4_clicked()
{
    QDate date_recep=ui->dateEdit_18->date();
    QDate date_livr=ui->dateEdit_17->date();
    int id_com=ui->lineEdit_16->text().toInt();
    int id_cl=ui->lineEdit_15->text().toInt();
    int id_emp=ui->lineEdit_17->text().toInt();


    QSqlQueryModel *rech=C.rechercher_multi(date_recep,date_livr,id_com,id_cl,id_emp);
    if(rech)
    {
        ui->tab_com_4->setModel(rech);
        ui->lineEdit_16->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_15->clear();

    }
    else
    {
        ui->tab_com_4->setModel(C.afficher());
    }
}

void GestionCommandes::on_Actualiser_4_clicked()
{
    ui->tab_com_4->setModel(C.afficher());
}

void GestionCommandes::on_pdf_5_clicked()
{
    QString strStream;
     QTextStream out(&strStream);

     const int rowCount = ui->tab_com_4->model()->rowCount();
     const int columnCount = ui->tab_com_4->model()->columnCount();


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
         if (!ui->tab_com_4->isColumnHidden(column))
             out << QString("<th>%1</th>").arg(ui->tab_com_4->model()->headerData(column, Qt::Horizontal).toString());
     out << "</tr></thead>\n";

     // data table
     for (int row = 0; row < rowCount; row++)
     {
         out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
         for (int column = 0; column < columnCount; column++)
         {
             if (!ui->tab_com_4->isColumnHidden(column))
             {
                 QString data = ui->tab_com_4->model()->data(ui->tab_com_4->model()->index(row, column)).toString().simplified();
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

void GestionCommandes::on_id_tri_4_clicked()
{
     ui->tab_com_4->setModel(C.trier_commande_id());
}

void GestionCommandes::on_dateR_tri_4_clicked()
{
 ui->tab_com_4->setModel(C.trier_commande_dtr("date_recep"));
}

void GestionCommandes::on_dateL_tri_4_clicked()
{
    ui->tab_com_4->setModel(C.trier_commande_dtr("date_livr"));
}

void GestionCommandes::on_pushButton_20_clicked()
{
    QSqlQuery queryt;

        queryt.prepare("SELECT ID_COM FROM COMMANDE");
              queryt.exec();
              queryt.first();
              int groupid_equipement = queryt.record().indexOf("ID");
              queryt.prepare("SELECT count(ID_COM)FROM COMMANDE ");
              queryt.exec();
              queryt.first() ;
             int total=queryt.value(0).toInt();


    qDebug()<<queryt.value(0);
              while (queryt.next()) {


    }
    qDebug()<<queryt.value(groupid_equipement);

    QSqlQueryModel* model;
   QBarSeries *series = new QBarSeries();
    Commande C;
    model=C.statistiques();
    for (int i=0;i<model->rowCount();i++) {

            QString g=QString::number((model->record(i).value(0).toInt()*100/total),'f',2)+"%";
            QBarSet *set0 = new QBarSet(model->record(i).value(1).toString());
            *set0 <<model->record(i).value(0).toInt();

            series->append(set0);
            series->setLabelsVisible(model->record(i).value(0).toInt());
            QBarCategoryAxis *axisX = new QBarCategoryAxis();
            axisX->append(model->record(i).value(1).toString());
            QChart *chart = new QChart();

            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

                             }
            QChart *chart = new QChart();

            chart->addSeries(series);
            chart->setTitle("Nombre des Commandes par date de reception :Nombre Des Commandes "+ QString::number(total));
            chart->setAnimationOptions(QChart::SeriesAnimations);


            QSqlQuery q;
            q.prepare("Select count(DATE_RECEP) FROM COMMANDE GROUP BY DATE_RECEP");
            q.first();
            q.exec();

            QValueAxis *axisY = new QValueAxis();
            axisY->setRange(q.value(0).toInt(),0);
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);

            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignRight);

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();
}

void GestionCommandes::on_pushButton_11_clicked()
{
    QSqlQuery queryt;

        queryt.prepare("SELECT ID_COM FROM COMMANDE");
              queryt.exec();
              queryt.first();
              int groupid_equipement = queryt.record().indexOf("ID");
              queryt.prepare("SELECT count(ID_COM)FROM COMMANDE ");
              queryt.exec();
              queryt.first() ;
             int total=queryt.value(0).toInt();


    qDebug()<<queryt.value(0);
              while (queryt.next()) {


    }
    qDebug()<<queryt.value(groupid_equipement);

    QSqlQueryModel* model;
   QBarSeries *series = new QBarSeries();
    Commande C;
    model=C.statistiques1();
    for (int i=0;i<model->rowCount();i++) {

            QString g=QString::number((model->record(i).value(0).toInt()*100/total),'f',2)+"%";
            QBarSet *set0 = new QBarSet(model->record(i).value(1).toString());
            *set0 <<model->record(i).value(0).toInt();

            series->append(set0);
            series->setLabelsVisible(model->record(i).value(0).toInt());
            QBarCategoryAxis *axisX = new QBarCategoryAxis();
            axisX->append(model->record(i).value(1).toString());
            QChart *chart = new QChart();

            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

                             }
            QChart *chart = new QChart();

            chart->addSeries(series);
            chart->setTitle("Nombre des Commandes par date de Livraison :Nombre Des Commandes "+ QString::number(total));
            chart->setAnimationOptions(QChart::SeriesAnimations);


            QSqlQuery q;
            q.prepare("Select count(DATE_RECEP) FROM COMMANDE GROUP BY DATE_RECEP");
            q.first();
            q.exec();

            QValueAxis *axisY = new QValueAxis();
            axisY->setRange(q.value(0).toInt(),0);
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);

            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignRight);

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();
}
