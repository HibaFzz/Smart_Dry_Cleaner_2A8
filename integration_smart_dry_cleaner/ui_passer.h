/********************************************************************************
** Form generated from reading UI file 'passer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSER_H
#define UI_PASSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_passer
{
public:
    QLabel *label;
    QTableView *tableView;
    QGroupBox *groupBox;
    QComboBox *comboBox_5;
    QComboBox *comboBox_4;
    QLineEdit *N_fact_2;
    QLineEdit *N_fact_3;
    QPushButton *pushButton_Ajouter_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_11;
    QLabel *label_4;
    QPushButton *pdf;
    QPushButton *Statistiques;
    QPushButton *Atualiser;
    QPushButton *quitter;
    QGroupBox *groupBox_8;
    QLabel *label_8;
    QPushButton *supprimer;
    QLineEdit *num_sup;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *recherche_button;
    QLabel *label_7;
    QLabel *label_9;

    void setupUi(QDialog *passer)
    {
        if (passer->objectName().isEmpty())
            passer->setObjectName(QStringLiteral("passer"));
        passer->resize(1082, 811);
        label = new QLabel(passer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 1101, 691));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/wt.jpg")));
        tableView = new QTableView(passer);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 390, 541, 271));
        groupBox = new QGroupBox(passer);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 1071, 391));
        groupBox->setStyleSheet(QLatin1String("color: #00002d;\n"
"\n"
"  font-size: 19px;"));
        groupBox->setAlignment(Qt::AlignCenter);
        comboBox_5 = new QComboBox(groupBox);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(420, 250, 311, 51));
        comboBox_5->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(420, 190, 311, 51));
        comboBox_4->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        N_fact_2 = new QLineEdit(groupBox);
        N_fact_2->setObjectName(QStringLiteral("N_fact_2"));
        N_fact_2->setGeometry(QRect(420, 70, 311, 51));
        N_fact_2->setLayoutDirection(Qt::RightToLeft);
        N_fact_2->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        N_fact_3 = new QLineEdit(groupBox);
        N_fact_3->setObjectName(QStringLiteral("N_fact_3"));
        N_fact_3->setGeometry(QRect(420, 130, 311, 51));
        N_fact_3->setLayoutDirection(Qt::RightToLeft);
        N_fact_3->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        pushButton_Ajouter_2 = new QPushButton(groupBox);
        pushButton_Ajouter_2->setObjectName(QStringLiteral("pushButton_Ajouter_2"));
        pushButton_Ajouter_2->setGeometry(QRect(460, 320, 111, 51));
        pushButton_Ajouter_2->setLayoutDirection(Qt::RightToLeft);
        pushButton_Ajouter_2->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 20px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 16px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/icons8-add-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Ajouter_2->setIcon(icon);
        pushButton_Ajouter_2->setIconSize(QSize(30, 30));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 320, 111, 51));
        pushButton->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 16px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 80, 111, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 130, 111, 51));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 200, 111, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 250, 121, 51));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(590, 320, 111, 51));
        lineEdit_4->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(660, 330, 61, 31));
        label_4 = new QLabel(passer);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(890, -10, 211, 211));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/Capture d\342\200\231\303\251cran 2022-04-06 014158.png")));
        label_4->setScaledContents(true);
        label_4->setOpenExternalLinks(false);
        pdf = new QPushButton(passer);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(730, 620, 111, 41));
        pdf->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 8px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 14px;\n"
" \n"
"  border-radius : 10px;\n"
"background-color:rgb(108, 149, 203)"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/icons8-pdf-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon1);
        Statistiques = new QPushButton(passer);
        Statistiques->setObjectName(QStringLiteral("Statistiques"));
        Statistiques->setGeometry(QRect(850, 620, 111, 41));
        Statistiques->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 8px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 14px;\n"
" \n"
"  border-radius : 10px;\n"
"background-color:rgb(108, 149, 203)"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/icons8-pie-chart-report-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        Statistiques->setIcon(icon2);
        Statistiques->setIconSize(QSize(30, 30));
        Atualiser = new QPushButton(passer);
        Atualiser->setObjectName(QStringLiteral("Atualiser"));
        Atualiser->setGeometry(QRect(680, 620, 41, 41));
        Atualiser->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 8px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 14px;\n"
" \n"
"  border-radius : 10px;\n"
"background-color:rgb(108, 149, 203)"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/icons8-synchronize-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        Atualiser->setIcon(icon3);
        Atualiser->setIconSize(QSize(30, 30));
        quitter = new QPushButton(passer);
        quitter->setObjectName(QStringLiteral("quitter"));
        quitter->setGeometry(QRect(962, 620, 111, 41));
        quitter->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 8px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 14px;\n"
" \n"
"  border-radius : 10px;\n"
"background-color:rgb(108, 149, 203)"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/icons8-log-out-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitter->setIcon(icon4);
        quitter->setIconSize(QSize(30, 30));
        groupBox_8 = new QGroupBox(passer);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(850, 390, 221, 231));
        groupBox_8->setAutoFillBackground(false);
        groupBox_8->setStyleSheet(QLatin1String("color: #00002d;\n"
"\n"
"  font-size: 17px;"));
        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 70, 111, 31));
        supprimer = new QPushButton(groupBox_8);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(70, 110, 91, 41));
        supprimer->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 20px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 16px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/icons8-delete-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer->setIcon(icon5);
        supprimer->setIconSize(QSize(40, 40));
        num_sup = new QLineEdit(groupBox_8);
        num_sup->setObjectName(QStringLiteral("num_sup"));
        num_sup->setGeometry(QRect(140, 70, 81, 31));
        num_sup->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        radioButton = new QRadioButton(passer);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(560, 460, 131, 41));
        radioButton->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 7px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 16px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        radioButton_2 = new QRadioButton(passer);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(710, 460, 131, 41));
        radioButton_2->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 7px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 16px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        lineEdit = new QLineEdit(passer);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(570, 541, 113, 31));
        lineEdit->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        lineEdit_2 = new QLineEdit(passer);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(720, 541, 113, 31));
        lineEdit_2->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        recherche_button = new QPushButton(passer);
        recherche_button->setObjectName(QStringLiteral("recherche_button"));
        recherche_button->setGeometry(QRect(580, 620, 91, 41));
        QFont font;
        font.setFamily(QStringLiteral("calibri"));
        font.setBold(true);
        font.setWeight(75);
        recherche_button->setFont(font);
        recherche_button->setAutoFillBackground(false);
        recherche_button->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 14px;\n"
" \n"
"  border-radius : 10px;\n"
"background-color:rgb(108, 149, 203)"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/icons8-search-64 (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        recherche_button->setIcon(icon6);
        recherche_button->setIconSize(QSize(22, 22));
        label_7 = new QLabel(passer);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(580, 580, 91, 20));
        label_9 = new QLabel(passer);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(740, 580, 71, 16));

        retranslateUi(passer);

        QMetaObject::connectSlotsByName(passer);
    } // setupUi

    void retranslateUi(QDialog *passer)
    {
        passer->setWindowTitle(QApplication::translate("passer", "Dialog", Q_NULLPTR));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("passer", "Passer une commande", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("passer", "-----------------------------", Q_NULLPTR)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("passer", "-----------------------------", Q_NULLPTR)
        );
        pushButton_Ajouter_2->setText(QString());
        pushButton->setText(QApplication::translate("passer", "Retour", Q_NULLPTR));
        label_2->setText(QApplication::translate("passer", "Prix_Unitaire", Q_NULLPTR));
        label_3->setText(QApplication::translate("passer", "Quantite", Q_NULLPTR));
        label_5->setText(QApplication::translate("passer", "Ref_Article", Q_NULLPTR));
        label_6->setText(QApplication::translate("passer", "N\302\260Commande", Q_NULLPTR));
        label_11->setText(QApplication::translate("passer", "TND", Q_NULLPTR));
        label_4->setText(QString());
        pdf->setText(QApplication::translate("passer", "pdf", Q_NULLPTR));
        Statistiques->setText(QApplication::translate("passer", "Statistiques", Q_NULLPTR));
        Atualiser->setText(QString());
        quitter->setText(QString());
        groupBox_8->setTitle(QApplication::translate("passer", "Supprimer", Q_NULLPTR));
        label_8->setText(QApplication::translate("passer", "Id Commande", Q_NULLPTR));
        supprimer->setText(QString());
        radioButton->setText(QApplication::translate("passer", "N\302\260 Commande", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("passer", "Prix", Q_NULLPTR));
        recherche_button->setText(QString());
        label_7->setText(QApplication::translate("passer", "N\302\260Commande", Q_NULLPTR));
        label_9->setText(QApplication::translate("passer", "Ref_Article", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class passer: public Ui_passer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSER_H
