/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QTableView *tabProduit;
    QLineEdit *p_recherche;
    QStackedWidget *stackedWidget_2;
    QWidget *page_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *page_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *p_ref;
    QLineEdit *p_nom;
    QLineEdit *p_quantite;
    QLineEdit *p_prix;
    QComboBox *p_article;
    QPushButton *p_ajouterBtn;
    QLabel *label_3;
    QPushButton *annuler_ajout;
    QWidget *page_6;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *p_ref_m;
    QLineEdit *p_nom_m;
    QLineEdit *p_quantite_m;
    QLineEdit *p_prix_m;
    QComboBox *p_article_m;
    QHBoxLayout *horizontalLayout;
    QPushButton *p_modifierBtn;
    QPushButton *p_supprimerBtn;
    QPushButton *annuler_modification;
    QMenuBar *menubar;
    QMenu *menuproduit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 0, 341, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Impact"));
        font.setPointSize(22);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"text-color :qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255))\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 60, 731, 451));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        tabProduit = new QTableView(page_3);
        tabProduit->setObjectName(QString::fromUtf8("tabProduit"));
        tabProduit->setGeometry(QRect(210, 60, 511, 271));
        p_recherche = new QLineEdit(page_3);
        p_recherche->setObjectName(QString::fromUtf8("p_recherche"));
        p_recherche->setGeometry(QRect(530, 30, 171, 20));
        p_recherche->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        stackedWidget_2 = new QStackedWidget(page_3);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 3, 201, 331));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayoutWidget = new QWidget(page_4);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(14, 10, 181, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayoutWidget_2 = new QWidget(page_5);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 90, 160, 178));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        p_ref = new QLineEdit(verticalLayoutWidget_2);
        p_ref->setObjectName(QString::fromUtf8("p_ref"));
        p_ref->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(p_ref);

        p_nom = new QLineEdit(verticalLayoutWidget_2);
        p_nom->setObjectName(QString::fromUtf8("p_nom"));
        p_nom->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(p_nom);

        p_quantite = new QLineEdit(verticalLayoutWidget_2);
        p_quantite->setObjectName(QString::fromUtf8("p_quantite"));
        p_quantite->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(p_quantite);

        p_prix = new QLineEdit(verticalLayoutWidget_2);
        p_prix->setObjectName(QString::fromUtf8("p_prix"));
        p_prix->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(p_prix);

        p_article = new QComboBox(verticalLayoutWidget_2);
        p_article->addItem(QString());
        p_article->setObjectName(QString::fromUtf8("p_article"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Impact"));
        p_article->setFont(font1);

        verticalLayout_2->addWidget(p_article);

        p_ajouterBtn = new QPushButton(verticalLayoutWidget_2);
        p_ajouterBtn->setObjectName(QString::fromUtf8("p_ajouterBtn"));

        verticalLayout_2->addWidget(p_ajouterBtn);

        label_3 = new QLabel(page_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 53, 161, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        font2.setPointSize(10);
        label_3->setFont(font2);
        annuler_ajout = new QPushButton(page_5);
        annuler_ajout->setObjectName(QString::fromUtf8("annuler_ajout"));
        annuler_ajout->setGeometry(QRect(60, 290, 75, 23));
        stackedWidget_2->addWidget(page_5);
        stackedWidget->addWidget(page_3);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_4 = new QLabel(page_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 80, 321, 21));
        label_4->setFont(font2);
        verticalLayoutWidget_3 = new QWidget(page_6);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(290, 120, 162, 178));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        p_ref_m = new QLineEdit(verticalLayoutWidget_3);
        p_ref_m->setObjectName(QString::fromUtf8("p_ref_m"));
        p_ref_m->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(p_ref_m);

        p_nom_m = new QLineEdit(verticalLayoutWidget_3);
        p_nom_m->setObjectName(QString::fromUtf8("p_nom_m"));
        p_nom_m->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(p_nom_m);

        p_quantite_m = new QLineEdit(verticalLayoutWidget_3);
        p_quantite_m->setObjectName(QString::fromUtf8("p_quantite_m"));
        p_quantite_m->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(p_quantite_m);

        p_prix_m = new QLineEdit(verticalLayoutWidget_3);
        p_prix_m->setObjectName(QString::fromUtf8("p_prix_m"));
        p_prix_m->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(p_prix_m);

        p_article_m = new QComboBox(verticalLayoutWidget_3);
        p_article_m->addItem(QString());
        p_article_m->setObjectName(QString::fromUtf8("p_article_m"));
        p_article_m->setFont(font1);

        verticalLayout_3->addWidget(p_article_m);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        p_modifierBtn = new QPushButton(verticalLayoutWidget_3);
        p_modifierBtn->setObjectName(QString::fromUtf8("p_modifierBtn"));

        horizontalLayout->addWidget(p_modifierBtn);

        p_supprimerBtn = new QPushButton(verticalLayoutWidget_3);
        p_supprimerBtn->setObjectName(QString::fromUtf8("p_supprimerBtn"));

        horizontalLayout->addWidget(p_supprimerBtn);


        verticalLayout_3->addLayout(horizontalLayout);

        annuler_modification = new QPushButton(page_6);
        annuler_modification->setObjectName(QString::fromUtf8("annuler_modification"));
        annuler_modification->setGeometry(QRect(340, 340, 75, 23));
        stackedWidget->addWidget(page_6);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuproduit = new QMenu(menubar);
        menuproduit->setObjectName(QString::fromUtf8("menuproduit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuproduit->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gestion Des Produits", nullptr));
        p_recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recherche ...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Afficher Formulaire d'ajout :", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        p_ref->setPlaceholderText(QCoreApplication::translate("MainWindow", "Reference", nullptr));
        p_nom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        p_quantite->setPlaceholderText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        p_prix->setPlaceholderText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        p_article->setItemText(0, QCoreApplication::translate("MainWindow", "Article id", nullptr));

        p_ajouterBtn->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "AJOUT -  PRODUIT - FORMULAIRE", nullptr));
        annuler_ajout->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "MODIFICATION - SUPPRESSION - PRODUIT", nullptr));
        p_ref_m->setPlaceholderText(QCoreApplication::translate("MainWindow", "Reference", nullptr));
        p_nom_m->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        p_quantite_m->setPlaceholderText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        p_prix_m->setPlaceholderText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        p_article_m->setItemText(0, QCoreApplication::translate("MainWindow", "Article id", nullptr));

        p_modifierBtn->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        p_supprimerBtn->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        annuler_modification->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        menuproduit->setTitle(QCoreApplication::translate("MainWindow", "produit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
