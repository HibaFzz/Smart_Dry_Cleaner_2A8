#include "mainwindow.h"
#include "ui_mainwindow.h"
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





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pwd->setEchoMode(QLineEdit::Password);
      ui->usr->setEchoMode(QLineEdit::Password);
      ui->tab_com->setModel(C.afficher());
      ui->tableAr->setModel(temparticle.afficher());
      ui->comboBox_2->setModel(C.combo_comboclient());
      ui->comboBox_3->setModel(C.combo_comboemploye());
      ui->IDCom_2->setModel(C.combo_comboCom());
      ui->tableView->setModel(Con.afficher());
      ui->comboBox_12->setModel(Con.combo_comboCom());
      ui->comboBox_13->setModel(Con.combo_comboAr());
      ui->dateR->setDate(QDate::currentDate());
      ui->dateL->setDate(QDate::currentDate().addDays(3));
      ui->tab_employe->setModel(E.afficher());
      ui->tab_cl->setModel(Cl.afficher());


      //Arduino------------------------------------------------------------------------------------------

      int ret= A.connect_arduino(); // lancer la connexion à arduino
          switch(ret){
          case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
              break;
          case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
             break;
          case(-1):qDebug() << "arduino is not available";
          }
           QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
           //le slot update_label suite à la reception du signal readyRead (reception des données).

}
void MainWindow::update_label() {

    {
        //data=A.read_from_arduino();
        refus.append(A.read_from_arduino());
            if(refus[refus.size()-1]=='\n') {
               refus.remove(refus.size()-2,2);

               // we're full
                qDebug()<<refus;
               bool test=E.rechercher_arduino(refus);
               qDebug()<<test;
               // bool test=true;
                if(test==true){
                    A.write_to_arduino("1");
                }
                else
                    A.write_to_arduino("0");

                refus.clear();

            }


               }

    }





MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_passerCom_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_GestionCom_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);
}




void MainWindow::on_quitter_clicked()
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

void MainWindow::on_GestionCom_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_Connecter_clicked()
{
   login l;
   l.USERNAME=ui->usr->text(), l.PWD=ui->usr->text();
   QSqlQuery query;

   query.prepare("SELECT * FROM LOGIN WHERE USERNAME=:l.USERNAME and PWD=:l.PWD");
   query.bindValue(":USERNAME",l.USERNAME);
   query.bindValue(":PWD",l.PWD);
   query.exec();
   {


         if(l.USERNAME=="admin" && l.PWD=="admin")

       { QMessageBox::information(this,"username et password correct","Bienvenu Admin");
          ui->stackedWidget->setCurrentIndex(1);
          QSqlQuery qry;
                  QDateTime dateTime=QDateTime::currentDateTime();

                  QString date=dateTime.toString();

                  qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',:dateTime)");
                  qry.bindValue(":dateTime",dateTime);


                  qry.exec();
                  ui->usr->clear();
                  ui->pwd->clear();

          }

    else if(l.USERNAME=="user" && l.PWD=="user")
       {
        QMessageBox::information(this,"username et password correct","Bienvenu Employe");
                  ui->stackedWidget->setCurrentIndex(2);
                  QSqlQuery qry;
                          QDateTime dateTime=QDateTime::currentDateTime();

                          QString date=dateTime.toString();

                          qry.prepare("insert into HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',:dateTime)");
                          qry.bindValue(":dateTime",dateTime);


                          qry.exec();
                          ui->usr->clear();
                          ui->pwd->clear();
       }
        else
            {
            QMessageBox::critical(nullptr, QObject::tr("Echec d'authentification"),
            QObject::tr("Mot de passe ou nom d'utilisateur non-valide"), QMessageBox::Cancel);
            ui->usr->clear();
            ui->pwd->clear();
            }
}
}

void MainWindow::on_pushButton_4_clicked()
{
     ui->usr->setEchoMode(QLineEdit::Normal);
}

void MainWindow::on_pushButton_3_clicked()
{
        ui->pwd->setEchoMode(QLineEdit::Normal);
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->usr->setEchoMode(QLineEdit::Password);

}

void MainWindow::on_pushButton_6_clicked()
{
     ui->pwd->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_GestionCom_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
/****************************************************************************/
                       /*Gestion Des Commandes*/

void MainWindow::on_pushButton_Ajouter_clicked()
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
            N.notification_ajout();
            msgBox.setText("ajouter avec succes");
            ui->tab_com->setModel(C.afficher());
            ui->N_fact->clear();

        }
        else
            msgBox.setText("Echec d'Ajout");
            msgBox.exec();
}
}

void MainWindow::on_supprimer_2_clicked()
{
    Notification N;
    C.setID_COM(ui->num_sup_2->text().toInt());
    QSqlQuery query= C.rechercherCommande(C.getID_COM());
    query.first();
    bool test2 = query.value(0).toBool();

    bool test=C.supprimer(C.getID_COM());
    if(C.getID_COM()==0)
     {     QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                 QObject::tr("Id Obligatoire!!\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                                 ui->num_sup_2->clear();
    }
    else if
            (test2==false)
             {     QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                         QObject::tr("Id n'existe pas!!\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                                          ui->num_sup_2->clear();
            }
    else if(test)
     {
        N.notification_supprimer();
        QMessageBox::information(nullptr, QObject::tr("suppression avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                                    ui->num_sup_2->clear();
ui->tab_com->setModel(C.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                                    ui->num_sup_2->clear();
}

void MainWindow::on_recu_pdf_clicked()
{
    QString strStream;
     QTextStream out(&strStream);
     QString d_info=QDate::currentDate().toString("dd.MM.yyyy");

    int ID_COM=ui->N_fact->text().toInt();

    QString DATE_RECEP=ui->dateR->text();
    QString DATE_LIVR=ui->dateL->text();
    int FK_CLIENT=ui->comboBox_2->currentText().toInt();
    int FK_EMPLOYE=ui->comboBox_3->currentText().toInt();
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

void MainWindow::on_pushButton_7_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_modifier_2_clicked()
{
    int ID_COM=ui->num_fact2_2->text().toInt();
    QDate DATE_RECEP=ui->dateEdit_5->date();
    QDate DATE_LIVR=ui->dateEdit_6->date();
    int FK_CLIENT=ui->cl_2->text().toInt();
    int FK_EMPLOYE=ui->emp_2->text().toInt();
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
            ui->num_fact2_2->clear();



        }
        else
            msgBox.setText("Echec de modification");
            msgBox.exec();
}

}
}

void MainWindow::on_IDCom_2_currentIndexChanged(int)
{
    int id=ui->IDCom_2->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from COMMANDE where ID_COM=:id");
        query.bindValue(":id",id);
        if(query.exec())
            {
                while(query.next())
                      {
               ui->num_fact2_2->setText(query.value(0).toString());
               ui->dateEdit_5->setDate(query.value(1).toDate());
               ui->dateEdit_6->setDate(query.value(2).toDate());
               ui->cl_2->setText(query.value(3).toString());
               ui->emp_2->setText(query.value(4).toString());
                }
}
}

void MainWindow::on_recherche_button_clicked()
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

void MainWindow::on_pdf_2_clicked()
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

void MainWindow::on_Actualiser_clicked()
{
    ui->tab_com->setModel(C.afficher());
}

void MainWindow::on_id_tri_clicked()
{
    ui->tab_com->setModel(C.trier_commande_id());
}

void MainWindow::on_dateR_tri_clicked()
{
     ui->tab_com->setModel(C.trier_commande_dtr("date_recep"));
}

void MainWindow::on_dateL_tri_clicked()
{
    ui->tab_com->setModel(C.trier_commande_dtr("date_livr"));
}



void MainWindow::on_pushButton_8_clicked()
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


void MainWindow::on_pushButton_17_clicked()
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
void MainWindow::on_passeC_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
/****************************************************************************************/
                      /**********Passer Une Commande**********/





void MainWindow::on_ajouter_c_clicked()
{
    float PRIX=ui->N_fact_9->text().toFloat();
    int QUANTITE=ui->N_fact_10->text().toInt();
    int fk_ar=ui->comboBox_13->currentText().toInt();
    int FK_COM=ui->comboBox_12->currentText().toInt();
    Notification N;
    Contenir Con(PRIX,QUANTITE,fk_ar,FK_COM);
    bool test1=Con.ajouter();
    QMessageBox msgBox;
        if (test1)
        {
                     float total=PRIX*QUANTITE;
                     QString t = QString::number(total);
                     ui->lineEdit_13->setText(t);
                     N.notification_ajout();
                     msgBox.setText("ajouter avec succes");
                     ui->tableView->setModel(Con.afficher());


        }
        else
            msgBox.setText("Echec d'Ajout");
            msgBox.exec();
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_recu_pdf_2_clicked()
{
    QString strStream;
     QTextStream out(&strStream);
     QString d_info=QDateTime::currentDateTime().toString("Le jour dd.MM.yyyy à HH:mm");

    int PRIX=ui->N_fact_9->text().toInt();

    int QUANTITE=ui->N_fact_10->text().toInt();
    int fk_ar=ui->comboBox_13->currentText().toInt();
    int FK_COM=ui->comboBox_12->currentText().toInt();
    float total=PRIX*QUANTITE;
    QString t = QString::number(total);
    ui->lineEdit_13->setText(t);
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
    painter.drawText(200,7100,"Article_Ref:");
    painter.drawText(200,7900,"Quantite:");
    painter.drawText(200,8700,"Prix Total:");
   QString id_string=QString::number(FK_COM);
   QString id_ar_string=QString::number(fk_ar);
   QString qt_string=QString::number(QUANTITE);
    QString t_string=QString::number(total);
    painter.setFont(QFont("Courier New", 18));
        painter.drawText(2400,6300,id_string);
        painter.drawText(2400,7100,id_ar_string);
        painter.drawText(2400,7900,qt_string);
        painter.drawText(2400,8700,t_string);

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

void MainWindow::on_recherche_button_3_clicked()
{
    int id_com=ui->nc->text().toInt();
    int id_Ar=ui->ra->text().toInt();



    QSqlQueryModel *rech=Con.rechercher_duo(id_com,id_Ar);
    if(rech)
    {
        ui->tableView->setModel(rech);
        ui->nc->clear();
        ui->ra->clear();


    }
    else
    {
        ui->tableView->setModel(Con.afficher());
    }
}


void MainWindow::on_supprimer_5_clicked()
{
    Notification N;
    Con.setFK_COM(ui->num_sup_5->text().toInt());
    bool test=Con.supprimer(Con.getFK_COM());
    if(Con.getFK_COM()==0)
     {     QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                 QObject::tr("Id Obligatoire!!\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                                 ui->num_sup_5->clear();
    }

    else if(test)
     {
        N.notification_supprimer();
        QMessageBox::information(nullptr, QObject::tr("suppression avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                                   ui->tableView->setModel(Con.afficher());
                                   ui->num_sup_5->clear();
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("suppression a echouée"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                                   ui->num_sup_5->clear();
}
void MainWindow::on_Statistiques_3_clicked()
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

void MainWindow::on_pdf_clicked()
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

void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_home_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_quitter_4_clicked()
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

void MainWindow::on_radioButton_clicked()
{
    ui->tableView->setModel(Con.trier_commande_id());
}



void MainWindow::on_radioButton_2_clicked()
{
     ui->tableView->setModel(Con.trier_prix());
}

void MainWindow::on_Atualiser_clicked()
{
    ui->tab_com->setModel(Con.afficher());
}

void MainWindow::on_quitter_9_clicked()
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

void MainWindow::on_quitter_13_clicked()
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



void MainWindow::on_Arduino_clicked()
{
    refus ="1";
    A.write_to_arduino(refus);
     qDebug()<<refus;

}

void MainWindow::on_Arduino_2_clicked()
{
    refus ="0";
    A.write_to_arduino(refus);
     qDebug()<<refus;
}
/************************************************************************************************************************************************************/
/*******************************************Gestion des Articles********************************************/

void MainWindow::on_pushButton_ajouter_clicked()
{
    //recuperation des info dans les4 champs
      int ref=ui->lineEdit_id->text().toInt();
      QString nom_ar=ui->lineEdit_prix->text();
      QString type_ar=ui->lineEdit_quantite->text();
     float prix=ui->lineEdit_pri->text().toFloat();

     article P(ref,nom_ar,type_ar,prix);

      bool test=P.ajouter();//inserer produit p dans la table
      if (test)
      {
          ui->tableAr->setModel(P.afficher());
           N.notification_ajout();
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                   QObject::tr("ajout effectué \n"
                                               "Click Cancel to exist ."),QMessageBox::Cancel);
           ui->tableAr->setModel(P.afficher());
           ui->lineEdit_id->clear();
           ui->lineEdit_prix->clear();
           ui->lineEdit_quantite->clear();
           ui->lineEdit_pri->clear();
      }
      else{
          QMessageBox::critical(nullptr,QObject::tr(" not ok"),
                                   QObject::tr("ajout non effectué \n"
                                               "Click Cancel to exist ."),QMessageBox::Cancel);

      }

}

void MainWindow::on_pushButton_supprimer_clicked()
{
        article P;
    //recuperation du id
       int ref=ui->lineEdit_cin_supp->text().toInt();article P1;
       bool test=P1.supprimer(ref);
       ui->tableAr->setModel(P1.afficher());


       if (test)
       {

           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("suppression effectué \n"
                                                "Click Cancel to exist ."),QMessageBox::Cancel);
            ui->tableAr->setModel(P.afficher());
            N.notification_supprimer();
            ui->lineEdit_cin_supp->clear();

       }
       else
             QMessageBox::critical(nullptr, QObject::tr("no"),
                         QObject::tr("Suppression failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int ref=ui->lineEdit_id->text().toInt();
   QString nom_ar=ui->lineEdit_prix->text();
   QString type_ar=ui->lineEdit_quantite->text();
    float prix=ui->lineEdit_pri->text().toFloat();

   article P(ref,nom_ar,type_ar,prix);

   bool test=P.modifier(ref,nom_ar,type_ar,prix);//modifier produit

   if (test)
      {

  ui->tableAr->setModel(P.afficher());
   N.notification_modifier();
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                   QObject::tr("Modification effectué \n"
                                               "Click Cancel to exist ."),QMessageBox::Cancel);
          ui->lineEdit_id->clear();
          ui->lineEdit_prix->clear();
          ui->lineEdit_quantite->clear();
          ui->lineEdit_pri->clear();


      }
      else
            QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                        QObject::tr("Modification failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_11_clicked()
{


    QString choix=ui->comboBox_chercher->currentText();

    if (choix=="Id_Article")
    {
        int ref = ui->lineEdit_rech->text().toInt();
        ui->tableAr->setModel(temparticle.rechercher(ref));
        ui->lineEdit_rech->clear();
    }
    else if (choix=="Prix")
    {
        float prix = ui->lineEdit_rech->text().toFloat();
        ui->tableAr->setModel(temparticle.rechercherprix(prix));
        ui->lineEdit_rech->clear();
    }
    else if (choix=="Nom")
    {
        QString nom = ui->lineEdit_rech->text();
        ui->tableAr->setModel(temparticle.rechercher_Nom(nom));
        ui->lineEdit_rech->clear();
    }

}

void MainWindow::on_pushButton_tri_clicked()
{
    article P;
    QString choix=ui->comboBox_tri->currentText();
    if (choix=="prix")
    {
        ui->tableAr->setModel(P.tri_prixcroissant());
        ui->tableAr->setModel(P.afficher());
        bool test=P.tri_prixcroissant();//tri produit
        if (test)
        {

    ui->tableAr->setModel(P.tri_prixcroissant());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri croissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
              QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri croissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if (choix=="Nom Article")
    {
        ui->tableAr->setModel(P.tri_quantitecroissant());
        ui->tableAr->setModel(P.afficher());
        bool test=P.tri_quantitecroissant();//tri produit
        if (test)
        {

    ui->tableAr->setModel(P.tri_quantitecroissant());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri croissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
              QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri croissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_trid_clicked()
{

    article P;
     QString choix=ui->comboBox_trid->currentText();
     if (choix=="prix")
     {
         ui->tableAr->setModel(P.tri_prixdecroissant());
         ui->tableAr->setModel(P.afficher());
         bool test=P.tri_prixdecroissant();//tri produit
         if (test)
         {

     ui->tableAr->setModel(P.tri_prixdecroissant());
             QMessageBox::information(nullptr,QObject::tr("ok"),
                                      QObject::tr("tri decroissante effectué \n"
                                                  "Click Cancel to exist ."),QMessageBox::Cancel);

         }
         else
               QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                           QObject::tr("tri decroissante failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
     }
     if (choix=="Nom Article")
     {
         ui->tableAr->setModel(P.tri_quantitedecroissant());
         ui->tableAr->setModel(P.afficher());
         bool test=P.tri_quantitedecroissant();//tri produit
         if (test)
         {

     ui->tableAr->setModel(P.tri_quantitedecroissant());
             QMessageBox::information(nullptr,QObject::tr("ok"),
                                      QObject::tr("tri decroissante effectué \n"
                                                  "Click Cancel to exist ."),QMessageBox::Cancel);

         }
         else
               QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                           QObject::tr("tri decroissante failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
     }
}

void MainWindow::on_pushButton_supprimer_2_clicked()
{
    QTableView *table;
                      table = ui->tableAr;

                      QString filters("CSV files (.csv);;All files (.*)");
                      QString defaultFilter("CSV files (*.csv)");
                      QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                         filters, &defaultFilter);
                      QFile file(fileName);

                      QAbstractItemModel *model =  table->model();
                      if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                          QTextStream data(&file);
                          QStringList strList;
                          for (int i = 0; i < model->columnCount(); i++) {
                              if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                  strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                              else
                                  strList.append("");
                          }
                          data << strList.join(";") << "\n";
                          for (int i = 0; i < model->rowCount(); i++) {
                              strList.clear();
                              for (int j = 0; j < model->columnCount(); j++) {

                                  if (model->data(model->index(i, j)).toString().length() > 0)
                                      strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                  else
                                      strList.append("");
                              }
                              data << strList.join(";") + "\n";
                          }
                          file.close();
                          QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                    QObject::tr("Export avec succes .\n"
                                                                "Click OK to exit."), QMessageBox::Ok);
                      }

}

void MainWindow::on_Statistiques_4_clicked()
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

void MainWindow::on_pushButton_supprimer_3_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this ,tr("choisir"),"",tr("photos(*.png)"));
        if(QString::compare(filename, QString())!=0)
        {
            QImage photo;
            bool valid=photo.load(filename);
            if(valid)
            {   photo=photo.scaledToWidth(ui->imageI->width(), Qt::SmoothTransformation);
                ui->imageI->setPixmap(QPixmap::fromImage(photo));
            }
            else
            {
            //error
            }
        }
}

void MainWindow::on_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_GestionCom_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(6);
}
/*************************************************************************************************************************************************/
/*************************************************Gestion Des employes**************************************************************/

void MainWindow::on_pushButton_ajouter_2_clicked()
{
    int id =ui->lineEdit_2->text().toInt();

     QString Nomemp=ui->lineEdit_3->text();
    QString PreNomemp=ui->lineEdit_4->text();
    QString date_naissance=ui->dateEdit->date().toString();
    QString mail=ui->lineEdit_5->text();
   int salaire=ui->lineEdit_10->text().toInt();
   int Num_tel=ui->lineEdit_9->text().toInt();
employe E(id,Nomemp,PreNomemp,date_naissance,mail,salaire,Num_tel);
bool test =E.ajouter();




    if(test)

    {

        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("ajout a échoué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
         ui->tab_employe->setModel(E.afficher());
         N.notification_ajout();

    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Ajout effectué\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_supprimer_4_clicked()
{

    employe E; E.setid(ui->lineEdit_cin_supp_2->text().toInt());
    bool test1=E.supprimer(E.getid());
    QMessageBox msg;
    if(test1)
    {
       msg.setText("employe supprimer") ;
     ui->tab_employe->setModel(E.afficher());
     N.notification_supprimer();


  }
    else

   msg.setText("employe non supprimer");
    msg.exec();
}

void MainWindow::on_pushButton_supprimer_5_clicked()
{
    int id=ui->lineEdit_18->text().toInt();
     QString Nom=ui->lineEdit_17->text();
     QString PreNom=ui->lineEdit_12->text();
     QString date_naissance=ui->dateEdit_2->date().toString();
     QString mail=ui->lineEdit_16->text();
     int salaire=ui->lineEdit_15 ->text().toInt();
      int Num_tel=ui->lineEdit_11 ->text().toInt();
     employe E(id,Nom,PreNom,date_naissance,mail,salaire,Num_tel);


            bool test= E.modifier(id);
             if(test)
             {
                   ui->tab_employe->setModel(E.afficher());
                    N.notification_modifier();
                 QMessageBox::information(nullptr, QObject::tr("modifier l'employé avec succées"),
                                            QObject::tr("employé  modifié.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);



          }
             else


          QMessageBox::critical(nullptr, QObject::tr("modifier employé"),
                                    QObject::tr("employé non modifié, vérifier les champs.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_historique_clicked()
{
    employe p;
        ui->tableView_historique->setModel(p.afficher_historique());
}

void MainWindow::on_rechercher_P_clicked()
{
    if (ui->checkBox_Nom->isChecked())
    { QString Nom=ui->rech_Nom->text();
        QSqlQueryModel *verif=E.rechercher_Nom(Nom);
        if (verif!=nullptr)
        {
            ui->tab_employe->setModel(verif);
        }
     }


        if (ui->checkBox_Prenom->isChecked())
    { QString Prenom=ui->rech_Prenom->text();
        QSqlQueryModel *verif=E.rechercher_Prenom(Prenom);
        if (verif!=nullptr)
        {
            ui->tab_employe->setModel(verif);
        }
     }

            if (ui->checkBox_Num_tel->isChecked())
    { int Num_tel=ui->rech_Num_tel->text() .toInt();
        QSqlQueryModel *verif=E.rechercher_Num_tel(Num_tel);
        if (verif!=nullptr)
        {
            ui->tab_employe->setModel(verif);
        }
     }

       if ((ui->checkBox_Num_tel->isChecked())&&(ui->checkBox_Nom->isChecked()))
    {
        int Num_tel=ui->rech_Num_tel->text() .toInt();
        QString Nom=ui->rech_Nom->text();

                    QSqlQueryModel *verif=E.rechercher_NomNum_tel(Nom,Num_tel);
                    if (verif!=nullptr)
                    {
                        ui->tab_employe->setModel(verif);
                    }

    }
            if ((ui->checkBox_Num_tel->isChecked())&&(ui->checkBox_Prenom->isChecked()))
       {
        QString Prenom=ui->rech_Prenom->text();
       int Num_tel=ui->rech_Num_tel->text() .toInt();


                    QSqlQueryModel *verif=E.rechercher_Num_telPrenom(Num_tel,Prenom);
                    if (verif!=nullptr)
                    {
                        ui->tab_employe->setModel(verif);
                    }

    }
            if ((ui->checkBox_Nom->isChecked())&&(ui->checkBox_Prenom->isChecked()))
    {
       QString Nom=ui->rech_Nom->text();
       QString Prenom=ui->rech_Prenom->text();


                    QSqlQueryModel *verif=E.rechercher_NomPrenom(Nom,Prenom);
                    if (verif!=nullptr)
                    {
                        ui->tab_employe->setModel(verif);
                    }

 if ((ui->checkBox_Nom->isChecked())&&(ui->checkBox_Prenom->isChecked())&&(ui->checkBox_Num_tel->isChecked()))
 {

     QString Prenom=ui->rech_Prenom->text();
     QString Nom=ui->rech_Nom->text();
     int Num_tel=ui->rech_Num_tel->text() .toInt();


                 QSqlQueryModel *verif=E.rechercher_tous(Nom,Prenom,Num_tel);
                 if (verif!=nullptr)
                 {
                     ui->tab_employe->setModel(verif);
                 }


 } // else QMessageBox::warning(this,"erreur","Aucun critére n'est coché");
 }
}


void MainWindow::on_radioButton_TRInProd_clicked()
{
     ui->tab_employe->setModel(E.trie_employeN());
}

void MainWindow::on_radioButton_TRIqProd_clicked()
{
      ui->tab_employe->setModel(E.trie_employeQ());
}

void MainWindow::on_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_GestionCom_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}
/*************************************************************************************************************************************************/
/*******************************************************Gestion des clients*******************************************/

void MainWindow::on_pushButton_ajouter_6_clicked()
{
    int id =ui->lineEdit_35->text().toInt();

    QString NomC=ui->lineEdit_34->text();
    QString PreNomC=ui->lineEdit_33->text();
    QString mail=ui->lineEdit_31->text();
    int Num_tel=ui->lineEdit_32->text().toInt();

client Cl(id,NomC,PreNomC,mail,Num_tel);
bool test =Cl.ajouter();




    if(test)

    {
         ui->tab_cl->setModel(Cl.afficher());
          N.notification_ajout();

        QMessageBox::information(nullptr, QObject::tr("Not OK"),
                    QObject::tr("ajout a échoué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else


    QMessageBox::critical(nullptr, QObject::tr("OK"),
                QObject::tr("Ajout effectué\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_8_clicked()
{
     Cl.setid(ui->lineEdit_cin_supp_4->text().toInt());
    bool test1=Cl.supprimer(Cl.getid());
    if(test1)
    {
        ui->tab_cl->setModel(Cl.afficher());//refresh
        N.notification_supprimer();
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("suppression effectué\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);

    }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("suppression non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);

    ui->lineEdit_cin_supp_4->clear();
}

void MainWindow::on_pushButton_supprimer_9_clicked()
{
    int ID=ui->lineEdit_42->text().toInt();
    QString NOM=ui->lineEdit_41->text();
    QString PRENOM=ui->lineEdit_38->text();
    QString MAIL=ui->lineEdit_40->text();
    int NUMTEL=ui->lineEdit_39->text().toInt();


   client Cl ( ID,NOM,PRENOM, MAIL,NUMTEL);
        bool test=Cl.modifier( ID);
    if(test)
    {
        ui->tab_cl->setModel(Cl.afficher());
         N.notification_modifier();

       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification effectué\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);

    }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("modification non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);

   ui->lineEdit_42->clear();
  ui->lineEdit_41->clear();
    ui->lineEdit_38->clear();
    ui->lineEdit_40->clear();
    ui->lineEdit_39->clear();

}


void MainWindow::on_rechercher_P_3_clicked()
{
    int rech=ui->rech_Nom_3->text().toInt();

      ui->tab_cl->setModel(Cl.rechercher(rech));
      ui->lineEdit_rech->clear();
}


void MainWindow::on_radioButton_TRIqProd_4_clicked()
{
  ui->tab_cl->setModel(Cl.triN());
}

void MainWindow::on_radioButton_TRInProd_3_clicked()
{
    ui->tab_cl->setModel(Cl.triI());
}

void MainWindow::on_radioButton_TRIqProd_5_clicked()
{
    ui->tab_cl->setModel(Cl.afficher());
}

void MainWindow::on_radioButton_TRIqProd_3_clicked()
{
     ui->tab_cl->setModel(Cl.triNum());
}

void MainWindow::on_Statistiques_5_clicked()
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

    //******* STAT ******
    QPieSeries *series = new QPieSeries();

    QSqlQueryModel* model;
    client cl;

    model=cl.statistiques();
        QPieSlice *slice[10] ;
        for (int i=0;i<model->rowCount();i++) {

                float p=model->record(i).value(0).toInt();
                QString g=QString::number((model->record(i).value(0).toFloat()*100/total),'f',2)+"%";

                series->append(g+" d' id client "+model->record(i).value(1).toString(),p);

                slice[i]= series->slices().at(i);
                slice[i]->setLabelVisible();

        }

                    // Create the chart widget
                    QChart *chart = new QChart();
                    // Add data to chart with title and hide legend
                    chart->addSeries(series);
                    chart->setTitle("Pourcentage Par Nombre des Commandes par clients :Nombre Des Commande "+ QString::number(total));
                    chart->legend();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
}

void MainWindow::on_GestionCom_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_retour_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Statistiques_6_clicked()
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

    //******* STAT ******
    QPieSeries *series = new QPieSeries();

    QSqlQueryModel* model;
    employe E;

    model=E.statistiques();
        QPieSlice *slice[10] ;
        for (int i=0;i<model->rowCount();i++) {

                float p=model->record(i).value(0).toInt();
                QString g=QString::number((model->record(i).value(0).toFloat()*100/total),'f',2)+"%";

                series->append(g+" d' id employe "+model->record(i).value(1).toString(),p);

                slice[i]= series->slices().at(i);
                slice[i]->setLabelVisible();

        }

                    // Create the chart widget
                    QChart *chart = new QChart();
                    // Add data to chart with title and hide legend
                    chart->addSeries(series);
                    chart->setTitle("Pourcentage Par Nombre des Commandes par Employe :Nombre Des Commande "+ QString::number(total));
                    chart->legend();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
}

void MainWindow::on_quitter_2_clicked()
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

void MainWindow::on_GestionCom_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_quitter_5_clicked()
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

void MainWindow::on_quitter_6_clicked()
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

void MainWindow::on_quitter_12_clicked()
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

void MainWindow::on_quitter_7_clicked()
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

void MainWindow::on_quitter_8_clicked()
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

void MainWindow::on_quitter_10_clicked()
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

void MainWindow::on_quitter_16_clicked()
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

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Qrcode_2_clicked()
{

    if(ui->tab_cl->currentIndex().row()==-1)

           QMessageBox::information(nullptr, QObject::tr("QrCode"),

                                    QObject::tr("Veuillez Choisir un(e) visiteur(e) du Tableau.\n"

                                                "Click Ok to exit."), QMessageBox::Ok);

       else

       {

            int cin=ui->tab_cl->model()->data(ui->tab_cl->model()->index(ui->tab_cl->currentIndex().row(),0)).toInt();

            const QrCode qr = QrCode::encodeText(std::to_string(cin).c_str(), QrCode::Ecc::LOW);

            std::ofstream myfile;

            myfile.open ("qrcode.svg") ;

            myfile << qr.toSvgString(1);

            myfile.close();

            QSvgRenderer svgRenderer(QString("qrcode.svg"));

            QPixmap pix( QSize(90, 90) );

            QPainter pixPainter( &pix );

            svgRenderer.render( &pixPainter );

            ui->label_87->setPixmap(pix);

       }
}

/*void MainWindow::on_radioButton_TRInProd_4_clicked()
{


void MainWindow::on_pushButton_12_clicked()
{
    GestionCommandes Gc;
    Gc.setModal(true);
    hide();
    Gc.exec();
}*/

void MainWindow::on_radioButton_TRInProd_4_clicked()
{
    ui->tab_employe->setModel(E.afficher());
}


void MainWindow::on_radioButton_TRInProd_5_clicked()
{
    ui->tableAr->setModel(temparticle.afficher());
}

void MainWindow::on_pushButton_9_clicked()
{
    //  data=A.read_from_arduino();

      data="24";
      bool code =E.rechercher_arduino(data);

      //A.write_to_arduino(data);
      if(code==true){
                     A.write_to_arduino("1");
                 }
                 else
                     A.write_to_arduino("0");

                 data.clear();

             }


void MainWindow::on_browseBtn_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );
}

void MainWindow::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("homar4338@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//(const QString &from, const QString &to, const QString &subject, const QString &body)
    if( !files.isEmpty() )
        smtp->sendMail("homar4338@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
    else
        smtp->sendMail("homar4338@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->toPlainText());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    //ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

