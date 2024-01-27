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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private :
    QWidget* principal;
    QWidget* haut;
    QWidget* bas;
    QWidget* gauche;
    QWidget* droite;
    QWidget* gHaut;
    QWidget* gBas;
    QGridLayout* gridLayout;
    QHBoxLayout* hboxlayout;
    QVBoxLayout* vboxlayout;
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
    void init_components(void);
    void init_layout(void);
    void init_logo(void);
    void init_pGauche(void);
    void afficherResultatsDeRecherche();
    void showPopup(int index);
    void validerButtonClickedCompany(void);
    void validerButtonClickedEtudiant();
    void validerButtonClickedContact(void);
};
#endif // MAINWINDOW_H
