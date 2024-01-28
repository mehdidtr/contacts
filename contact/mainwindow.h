#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QScrollArea>
#include <QFormLayout>


#include "src/controller/companyController.h"
#include "src/controller/internshipController.h"
#include "src/controller/mdsController.h"
#include "src/controller/studentController.h"

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
    QLabel* TitleMDS;
    QLabel* TitleStudent;

    QLabel* companyDetails;
    QLabel* subjectDetails;
    QLabel* mdsDetails;
    QLabel* studentDetails;

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

    companyController* dataCompany;
    internshipController* dataInternship;
    mdsController* dataMDS;
    studentController* dataStudent;

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

    QLineEdit *searchLineEdit;
    QComboBox *menuDeroulant;
    QComboBox *ongletsStage;
    QVBoxLayout *layoutResultats;
    QWidget *widgetResultats;
    QScrollArea *scrollArea;
    QFormLayout *formlayoutEntreprise;

    QLineEdit* nomEntreprise;
    QLineEdit* domaineEntreprise;
    QVBoxLayout *layoutEntreprise;
    QDialog *popupEntreprise;

    QLineEdit *nomEtudiant;
    QLineEdit *prenomEtudiant;
    QLineEdit *promotionEtudiant;
    QLineEdit *mailEtudiant;
    QDialog *popupEtudiant;

    QLineEdit* nomContact;
    QLineEdit* prenomContact;
    QLineEdit* positionContact;
    QComboBox* menuDeroulantContact;
    QLineEdit* mailContact;
    QLineEdit* telContact;
    QVBoxLayout *layoutContact;
    QComboBox* entrepriseComboBox;
    QLabel* logoLabel;
    QDialog *popupContact;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool isLayoutEmpty(QLayout* layout);
    void clear_pDroite(void);

    // GET & SET Company
    QString getCompanyAllData(int companyId);
    QString getCompanyName(int companyId);
    QString getCompanyDomain(int companyId);
    void setCompanyData(const QString& nom, const QString& domaine, int companyId);

    // GET & SET Subject
    QString getSubjectData(int companyId);
    void setSubjectData(const QString& subject, int companyId);

    // GET & SET MDS
    QString getMDSAllData(int mdsId);
    QString getMDSName(int mdsId);
    QString getMDSSurname(int mdsId);
    QString getMDSContact(int mdsId);
    void setMDSData(const QString& mdsName, const QString& mdsSurname, const QString& mdsContact, int mdsId);

    // GET & SET Student
    QString getStudentAllData(int studentId);
    QString getStudentNom(int studentId);
    QString getStudentPrenom(int studentId);
    QString getStudentMail(int studentId);
    QString getStudentPromotion(int studentId);
    void setStudentData(const QString& studentName, const QString& studentSurname, const QString& studentMail, const QString& studentPromotion, int studentId);

private slots:
    void init_pDroite_Modify(void);
    void init_components(void);
    void init_layout(void);
    void init_logo(void);
    void init_pGauche(void);
    void init_pDroite(void);
    void afficherResultatsDeRecherche();
    void onModifierButtonClicked();
    void onSauvegarderButtonClicked();
    void showPopup(int index);
    void validerButtonClickedCompany(void);
    void validerButtonClickedEtudiant();
    void validerButtonClickedContact(void);
};
#endif // MAINWINDOW_H
