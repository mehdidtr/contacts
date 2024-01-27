#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QScrollArea>

#include "src/controller/companyController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget* centre;
    QLabel* label;
    QVBoxLayout* vboxlayout;

    QWidget* pDroiteWidget;
    QVBoxLayout* pDroiteLayout;
    QWidget* pDroiteModifyWidget;
    QVBoxLayout* pDroiteModifyLayout;
    QVBoxLayout* mainLayout;

    QLabel* TitleCompany;
    QLabel* TitleSubject;
    QLabel* TitleMDSInfo;
    QLabel* TitleStudentInfo;

    QLabel* SubTitleCompany_Name;
    QLabel* SubTitleCompany_domain;

    QLabel* SubjectDetails;

    QLabel* SubTitleMDS_Name;
    QLabel* SubTitleMDS_Surname;
    QLabel* SubTitleMDS_Contact;

    QLabel* SubTitleStudent_Name;
    QLabel* SubTitleStudent_Surname;
    QLabel* SubTitleStudent_Mail;
    QLabel* SubTitleStudent_Promotion;

    QPushButton* push_button_modify;
    QPushButton* push_button_save;

    QLineEdit* lineEditCompanyName;
    QLineEdit* lineEditCompanyDomain;
    QLineEdit* lineEditSubject;
    QLineEdit* lineEditMDSName;
    QLineEdit* lineEditMDSSurname;
    QLineEdit* lineEditMDSContact;
    QLineEdit* lineEditStudentName;
    QLineEdit* lineEditStudentSurname;
    QLineEdit* lineEditStudentMail;
    QLineEdit* lineEditStudentPromotion;

    QFont fontTitle;
    QFont fontSubTitle;

    companyController* dataCtrl;

    // PGauche
    QWidget* principal;
    QWidget* haut;
    QWidget* bas;
    QWidget* gauche;
    QWidget* droite;
    QWidget* gHaut;
    QWidget* gBas;
    QGridLayout* gridLayout;
    QHBoxLayout* hboxlayout;
    QHBoxLayout* hboxlayoutHaut;
    QVBoxLayout* vboxlayoutGauche;
    QVBoxLayout* vboxResultatsgBas;
    QPushButton* boutonEntreprise;
    QPushButton* boutonMds;
    QPushButton* boutonEtudiant;
    QPushButton* boutonLocalite;
    QPushButton* boutonAjouter;

    QLineEdit* searchLineEdit;
    QComboBox* menuDeroulant;
    QComboBox* ongletsStage;
    QVBoxLayout* layoutResultats;
    QWidget* widgetResultats;
    QScrollArea*scrollArea;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void init_pDroite(void);   
    bool isLayoutEmpty(QLayout* layout);
    void clear_pDroite(void);
    void dataFromController();

private slots:
    void init_pDroite_Modify(void);
    void init_components(void);
    void init_layout(void);
    void init_logo(void);
    void init_pGauche(void);
    void afficherResultatsDeRecherche();
    void onModifierButtonClicked();
};
#endif // MAINWINDOW_H
