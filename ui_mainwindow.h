/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QPushButton *GestionCom;
    QPushButton *passerCom;
    QLabel *label_3;
    QPushButton *Statistiques;
    QLabel *label_4;
    QPushButton *quitter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1175, 743);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 1481, 951));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 1071, 631));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/wt.jpg")));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(150, 90, 751, 511));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QLatin1String("color: #00002d;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"  font-size: 40px;"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        GestionCom = new QPushButton(groupBox);
        GestionCom->setObjectName(QStringLiteral("GestionCom"));
        GestionCom->setGeometry(QRect(140, 90, 431, 101));
        GestionCom->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"font: italic 8pt \"Palace Script MT\";\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 30px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 36px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        passerCom = new QPushButton(groupBox);
        passerCom->setObjectName(QStringLiteral("passerCom"));
        passerCom->setGeometry(QRect(140, 230, 431, 101));
        passerCom->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"font: italic 8pt \"Palace Script MT\";\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 30px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 36px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-40, 10, 321, 581));
        Statistiques = new QPushButton(groupBox);
        Statistiques->setObjectName(QStringLiteral("Statistiques"));
        Statistiques->setGeometry(QRect(140, 370, 431, 101));
        Statistiques->setStyleSheet(QLatin1String(" border: 2px solid black;\n"
"font: italic 8pt \"Palace Script MT\";\n"
"border-radius: 10px;\n"
"  color: white;\n"
"  padding: 30px;\n"
"  text-align: center;\n"
"  \n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 36px;\n"
" \n"
"  border-radius : 16px;\n"
"background-color:rgb(108, 149, 203)"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(900, -10, 211, 211));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/Capture d\342\200\231\303\251cran 2022-04-06 014158.png")));
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);
        label_4->setOpenExternalLinks(false);
        quitter = new QPushButton(centralwidget);
        quitter->setObjectName(QStringLiteral("quitter"));
        quitter->setGeometry(QRect(960, 587, 93, 41));
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/icons8-log-out-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitter->setIcon(icon);
        quitter->setIconSize(QSize(30, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1175, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Bienvenu chez notre pressing \"FastDry\"", Q_NULLPTR));
        GestionCom->setText(QApplication::translate("MainWindow", "Gestion des Commandes", Q_NULLPTR));
        passerCom->setText(QApplication::translate("MainWindow", "Passer une Commande", Q_NULLPTR));
        label_3->setText(QString());
        Statistiques->setText(QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        label_4->setText(QString());
        quitter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
