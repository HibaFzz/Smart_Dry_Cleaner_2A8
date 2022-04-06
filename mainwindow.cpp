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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_passerCom_clicked()
{
    passer p;
    p.setModal(true);
    hide();
    p.exec();
}

void MainWindow::on_GestionCom_clicked()
{
    GestionCommandes Gc;
    Gc.setModal(true);
    hide();
    Gc.exec();
}


void MainWindow::on_Statistiques_clicked()
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
                    QString d=QString("Rideaux "+QString::number((ref3*100)/total,'f',2)+"%" );
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
                    chart->setTitle("Pourcentage Par Article :Nombre Des Commandes "+ QString::number(total));
                    chart->legend();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
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
