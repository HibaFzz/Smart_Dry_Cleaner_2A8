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
#include"passer.h"
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




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pwd->setEchoMode(QLineEdit::Password);
      ui->usr->setEchoMode(QLineEdit::Password);
      ui->tab_com->setModel(C.afficher());
      ui->comboBox_2->setModel(C.combo_comboclient());
      ui->comboBox_3->setModel(C.combo_comboemploye());
      ui->IDCom_2->setModel(C.combo_comboCom());
      ui->tableView->setModel(Con.afficher());
      ui->comboBox_12->setModel(Con.combo_comboCom());
      ui->comboBox_13->setModel(Con.combo_comboAr());
      ui->dateR->setDateTime(QDateTime::currentDateTime());
      ui->dateL->setDate(QDate::currentDate().addDays(3));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_passerCom_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_GestionCom_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
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
   QString usr=ui->usr->text(), pwd=ui->usr->text();

         if(usr=="admin" && pwd=="admin")

       { QMessageBox::information(this,"username et password correct","Bienvenu Admin");
          ui->stackedWidget->setCurrentIndex(3);}

    else if(usr=="user" && pwd=="user")
       {
        QMessageBox::information(this,"username et password correct","Bienvenu Employe");
                  ui->stackedWidget->setCurrentIndex(2);
       }
        else
            {
            QMessageBox::critical(nullptr, QObject::tr("Echec d'authentification"),
            QObject::tr("Mot de passe ou nom d'utilisateur non-valide"), QMessageBox::Cancel);
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
     ui->stackedWidget->setCurrentIndex(4);
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
    passer p;
    p.setModal(true);
    hide();
    p.exec();
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
    ui->stackedWidget->setCurrentIndex(6);
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
    ui->stackedWidget->setCurrentIndex(5);
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
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
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
