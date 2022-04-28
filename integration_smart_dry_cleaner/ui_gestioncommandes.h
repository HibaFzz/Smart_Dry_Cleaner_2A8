/********************************************************************************
** Form generated from reading UI file 'gestioncommandes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONCOMMANDES_H
#define UI_GESTIONCOMMANDES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionCommandes
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QGroupBox *groupBox_9;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_13;
    QLineEdit *N_fact;
    QPushButton *pushButton_Ajouter;
    QLabel *label_14;
    QLabel *label_15;
    QDateEdit *dateR;
    QDateEdit *dateL;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QPushButton *quitter_2;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QLabel *label_3;
    QLabel *label_26;
    QLineEdit *lineEdit_8;
    QLabel *label_25;
    QLineEdit *lineEdit_7;
    QLabel *label_24;
    QLineEdit *lineEdit_6;
    QPushButton *recherche_button;
    QLabel *label_22;
    QDateEdit *dateEdit_3;
    QLabel *label_23;
    QDateEdit *dateEdit_4;
    QTableView *tab_com;
    QGroupBox *groupBox_5;
    QLabel *label_9;
    QLabel *label_12;
    QLineEdit *num_fact2;
    QPushButton *modifier;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QComboBox *IDCom;
    QLineEdit *emp;
    QLineEdit *cl;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QGroupBox *groupBox_8;
    QLabel *label_8;
    QPushButton *supprimer;
    QLineEdit *num_sup;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pdf_2;
    QRadioButton *radioButton_3;
    QPushButton *quitter;
    QPushButton *pushButton_2;

    void setupUi(QDialog *GestionCommandes)
    {
        if (GestionCommandes->objectName().isEmpty())
            GestionCommandes->setObjectName(QStringLiteral("GestionCommandes"));
        GestionCommandes->resize(1079, 676);
        label = new QLabel(GestionCommandes);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1141, 711));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/wt.jpg")));
        tabWidget = new QTabWidget(GestionCommandes);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1091, 681));
        tabWidget->setStyleSheet(QLatin1String("\n"
"background-image: url(:/new/prefix1/background.jpg);\n"
"QTabBar::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid#C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width:20ex;\n"
"    padding: 2px;\n"
"     font: bold, \"Comic Sans MS\";\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}"));
        tabWidget->setElideMode(Qt::ElideLeft);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, -20, 1151, 671));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/wt.jpg")));
        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(-50, 0, 1171, 691));
        groupBox_9->setAcceptDrops(false);
        groupBox_9->setLayoutDirection(Qt::LeftToRight);
        groupBox_9->setAutoFillBackground(false);
        groupBox_9->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 30px;"));
        groupBox_9->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_9);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(310, 50, 191, 71));
        label_6->setLayoutDirection(Qt::RightToLeft);
        label_6->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 30px;"));
        label_10 = new QLabel(groupBox_9);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(310, 150, 201, 31));
        label_10->setLayoutDirection(Qt::RightToLeft);
        label_10->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 30px;"));
        label_13 = new QLabel(groupBox_9);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(310, 230, 191, 31));
        label_13->setLayoutDirection(Qt::RightToLeft);
        label_13->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 30px;"));
        N_fact = new QLineEdit(groupBox_9);
        N_fact->setObjectName(QStringLiteral("N_fact"));
        N_fact->setGeometry(QRect(530, 60, 301, 51));
        N_fact->setLayoutDirection(Qt::RightToLeft);
        N_fact->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        pushButton_Ajouter = new QPushButton(groupBox_9);
        pushButton_Ajouter->setObjectName(QStringLiteral("pushButton_Ajouter"));
        pushButton_Ajouter->setGeometry(QRect(510, 460, 111, 51));
        pushButton_Ajouter->setLayoutDirection(Qt::RightToLeft);
        pushButton_Ajouter->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        pushButton_Ajouter->setIcon(icon);
        pushButton_Ajouter->setIconSize(QSize(30, 30));
        label_14 = new QLabel(groupBox_9);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(310, 390, 191, 31));
        label_14->setLayoutDirection(Qt::RightToLeft);
        label_14->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 30px;"));
        label_15 = new QLabel(groupBox_9);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(310, 310, 191, 31));
        label_15->setLayoutDirection(Qt::RightToLeft);
        label_15->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 30px;"));
        dateR = new QDateEdit(groupBox_9);
        dateR->setObjectName(QStringLiteral("dateR"));
        dateR->setGeometry(QRect(530, 140, 301, 51));
        dateR->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        dateL = new QDateEdit(groupBox_9);
        dateL->setObjectName(QStringLiteral("dateL"));
        dateL->setGeometry(QRect(530, 220, 301, 51));
        dateL->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        comboBox_2 = new QComboBox(groupBox_9);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(530, 300, 301, 51));
        comboBox_2->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        comboBox_3 = new QComboBox(groupBox_9);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(530, 380, 301, 51));
        comboBox_3->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        pushButton = new QPushButton(groupBox_9);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 460, 201, 51));
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
        label_4 = new QLabel(groupBox_9);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(940, -10, 211, 211));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/Capture d\342\200\231\303\251cran 2022-04-06 014158.png")));
        label_4->setScaledContents(true);
        label_4->setOpenExternalLinks(false);
        quitter_2 = new QPushButton(groupBox_9);
        quitter_2->setObjectName(QStringLiteral("quitter_2"));
        quitter_2->setGeometry(QRect(1010, 600, 111, 41));
        quitter_2->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        icon1.addFile(QStringLiteral(":/image/icons8-log-out-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitter_2->setIcon(icon1);
        quitter_2->setIconSize(QSize(30, 30));
        pushButton_3 = new QPushButton(groupBox_9);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 460, 191, 51));
        pushButton_3->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/icons8-pdf-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 1091, 651));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/image/wt.jpg")));
        label_26 = new QLabel(tab_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 16, 91, 20));
        lineEdit_8 = new QLineEdit(tab_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(500, 10, 131, 31));
        lineEdit_8->setAutoFillBackground(false);
        lineEdit_8->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        label_25 = new QLabel(tab_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(230, 10, 71, 31));
        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(290, 10, 131, 31));
        lineEdit_7->setAutoFillBackground(false);
        lineEdit_7->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(430, 10, 81, 31));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(100, 10, 131, 31));
        lineEdit_6->setAutoFillBackground(false);
        lineEdit_6->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        recherche_button = new QPushButton(tab_2);
        recherche_button->setObjectName(QStringLiteral("recherche_button"));
        recherche_button->setGeometry(QRect(640, 10, 71, 31));
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
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/icons8-search-64 (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        recherche_button->setIcon(icon3);
        recherche_button->setIconSize(QSize(22, 22));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(30, 50, 81, 31));
        label_22->setAutoFillBackground(false);
        label_22->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        dateEdit_3 = new QDateEdit(tab_2);
        dateEdit_3->setObjectName(QStringLiteral("dateEdit_3"));
        dateEdit_3->setGeometry(QRect(120, 50, 131, 31));
        dateEdit_3->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(260, 50, 81, 31));
        label_23->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        dateEdit_4 = new QDateEdit(tab_2);
        dateEdit_4->setObjectName(QStringLiteral("dateEdit_4"));
        dateEdit_4->setGeometry(QRect(350, 50, 131, 31));
        dateEdit_4->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        tab_com = new QTableView(tab_2);
        tab_com->setObjectName(QStringLiteral("tab_com"));
        tab_com->setGeometry(QRect(0, 90, 721, 491));
        tab_com->setAutoFillBackground(true);
        tab_com->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(730, 90, 351, 331));
        groupBox_5->setAutoFillBackground(true);
        groupBox_5->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 16px;"));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 70, 111, 31));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 110, 111, 31));
        num_fact2 = new QLineEdit(groupBox_5);
        num_fact2->setObjectName(QStringLiteral("num_fact2"));
        num_fact2->setGeometry(QRect(170, 70, 141, 31));
        num_fact2->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        modifier = new QPushButton(groupBox_5);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(180, 280, 121, 41));
        modifier->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/icons8-edit-64 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        modifier->setIcon(icon4);
        modifier->setIconSize(QSize(30, 30));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(30, 150, 111, 31));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 190, 111, 31));
        label_20->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 16px;"));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 230, 111, 31));
        label_21->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 16px;"));
        IDCom = new QComboBox(groupBox_5);
        IDCom->setObjectName(QStringLiteral("IDCom"));
        IDCom->setGeometry(QRect(30, 280, 121, 41));
        IDCom->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        emp = new QLineEdit(groupBox_5);
        emp->setObjectName(QStringLiteral("emp"));
        emp->setGeometry(QRect(170, 230, 141, 31));
        emp->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        cl = new QLineEdit(groupBox_5);
        cl->setObjectName(QStringLiteral("cl"));
        cl->setGeometry(QRect(170, 190, 141, 31));
        cl->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        dateEdit = new QDateEdit(groupBox_5);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(170, 110, 141, 31));
        dateEdit->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        dateEdit_2 = new QDateEdit(groupBox_5);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(170, 150, 141, 31));
        dateEdit_2->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(730, 430, 351, 151));
        groupBox_8->setAutoFillBackground(true);
        groupBox_8->setStyleSheet(QLatin1String("color: #00002d;\n"
"  font-size: 16px;"));
        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 50, 111, 31));
        supprimer = new QPushButton(groupBox_8);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(150, 100, 131, 41));
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
        num_sup->setGeometry(QRect(140, 50, 151, 31));
        num_sup->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;"));
        radioButton = new QRadioButton(tab_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 590, 111, 41));
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
        radioButton_2 = new QRadioButton(tab_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(160, 590, 111, 41));
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
        pdf_2 = new QPushButton(tab_2);
        pdf_2->setObjectName(QStringLiteral("pdf_2"));
        pdf_2->setGeometry(QRect(500, 50, 121, 31));
        pdf_2->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        pdf_2->setIcon(icon2);
        radioButton_3 = new QRadioButton(tab_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(290, 590, 111, 41));
        radioButton_3->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        quitter = new QPushButton(tab_2);
        quitter->setObjectName(QStringLiteral("quitter"));
        quitter->setGeometry(QRect(960, 590, 111, 41));
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
        quitter->setIcon(icon1);
        quitter->setIconSize(QSize(30, 30));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(640, 50, 41, 31));
        pushButton_2->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
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
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/icons8-synchronize-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon6);
        pushButton_2->setIconSize(QSize(30, 30));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(GestionCommandes);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GestionCommandes);
    } // setupUi

    void retranslateUi(QDialog *GestionCommandes)
    {
        GestionCommandes->setWindowTitle(QApplication::translate("GestionCommandes", "Dialog", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        groupBox_9->setTitle(QApplication::translate("GestionCommandes", "Ajouter Une Commande", Q_NULLPTR));
        label_6->setText(QApplication::translate("GestionCommandes", "Id Commande", Q_NULLPTR));
        label_10->setText(QApplication::translate("GestionCommandes", "Date Reception", Q_NULLPTR));
        label_13->setText(QApplication::translate("GestionCommandes", "Date Livraison", Q_NULLPTR));
        pushButton_Ajouter->setText(QString());
        label_14->setText(QApplication::translate("GestionCommandes", "Id Employ\303\251", Q_NULLPTR));
        label_15->setText(QApplication::translate("GestionCommandes", "Id Client", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("GestionCommandes", "-----------------------------", Q_NULLPTR)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("GestionCommandes", "-----------------------------", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("GestionCommandes", "Passer une commande", Q_NULLPTR));
        label_4->setText(QString());
        quitter_2->setText(QString());
        pushButton_3->setText(QApplication::translate("GestionCommandes", "Recu", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("GestionCommandes", "Ajouter Commande", Q_NULLPTR));
        label_3->setText(QString());
        label_26->setText(QApplication::translate("GestionCommandes", "Id_Commande", Q_NULLPTR));
        label_25->setText(QApplication::translate("GestionCommandes", "Id_Client", Q_NULLPTR));
        label_24->setText(QApplication::translate("GestionCommandes", "Id_Employe", Q_NULLPTR));
        recherche_button->setText(QString());
        label_22->setText(QApplication::translate("GestionCommandes", "Date_R", Q_NULLPTR));
        label_23->setText(QApplication::translate("GestionCommandes", "Date_L", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("GestionCommandes", "Modifier", Q_NULLPTR));
        label_9->setText(QApplication::translate("GestionCommandes", "Id Commande", Q_NULLPTR));
        label_12->setText(QApplication::translate("GestionCommandes", "Date Reception", Q_NULLPTR));
        modifier->setText(QString());
        label_19->setText(QApplication::translate("GestionCommandes", "Date Livraison", Q_NULLPTR));
        label_20->setText(QApplication::translate("GestionCommandes", "Id Client", Q_NULLPTR));
        label_21->setText(QApplication::translate("GestionCommandes", "Id Employ\303\251", Q_NULLPTR));
        IDCom->clear();
        IDCom->insertItems(0, QStringList()
         << QApplication::translate("GestionCommandes", "-------------------", Q_NULLPTR)
        );
        groupBox_8->setTitle(QApplication::translate("GestionCommandes", "Supprimer", Q_NULLPTR));
        label_8->setText(QApplication::translate("GestionCommandes", "Id Commande", Q_NULLPTR));
        supprimer->setText(QString());
        radioButton->setText(QApplication::translate("GestionCommandes", "ID", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("GestionCommandes", "DATE_R", Q_NULLPTR));
        pdf_2->setText(QApplication::translate("GestionCommandes", "pdf", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("GestionCommandes", "DATE_L", Q_NULLPTR));
        quitter->setText(QString());
        pushButton_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("GestionCommandes", "Gestion des Commandes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GestionCommandes: public Ui_GestionCommandes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONCOMMANDES_H
