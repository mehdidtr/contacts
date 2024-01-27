#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "src/view/formulaireAjoutEntreprise.h"
#include "src/view/formulaireAjoutContact.h"
#include "src/view/formulaireAjoutEtudiant.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("Ma fenêtre Qt");
    this->setGeometry(100, 100, 800, 600);
    this->init_components();
    this->init_layout();
    this->init_logo();

    afficherResultatsDeRecherche();

    //this->init_pGauche();
}

void MainWindow::init_components (void){
    this->principal = new QWidget();
    this->droite = new QWidget();
    this->gauche = new QWidget();
    this->bas = new QWidget();
    this->haut = new QWidget();
    this->gBas = new QWidget();
    this->gHaut = new QWidget();
    this->boutonEntreprise = new QPushButton("ENTREPRISE");
    this->boutonMds= new QPushButton("MAITRE DE STAGE");
    this->boutonEtudiant= new QPushButton("ETUDIANT");
    this->boutonLocalite= new QPushButton("LOCALITE");
    this->boutonAjouter= new QPushButton("Ajouter");
    this->menuDeroulant = new QComboBox();
    this->searchLineEdit = new QLineEdit(this);
    this->widgetResultats = new QWidget();
    this->scrollArea = new QScrollArea();
    this->logoLabel = new QLabel(this);
}

void MainWindow::init_layout (void){
    // Création d'une mainWindow
    this->setCentralWidget(this->principal);

    // Pour la division de la fenêtre en deux
    this->vboxlayout = new QVBoxLayout();
    this->principal->setLayout(this->vboxlayout);
    this->vboxlayout->addWidget(this->haut);
    this->vboxlayout->addWidget(this->bas);

    // Pour le logo
    this->hboxlayoutHaut = new QHBoxLayout();
    this->haut->setLayout(this->hboxlayoutHaut);

    // Pour la création des widgets gauche et droite
    this->hboxlayout = new QHBoxLayout();
    this->bas->setLayout(this->hboxlayout);
    this->hboxlayout->addWidget(gauche);
    this->hboxlayout->addWidget(droite);

    // Pour la subdivision gauche
    this->vboxlayoutGauche = new QVBoxLayout();
    this->gauche->setLayout(vboxlayoutGauche);
    this->gauche->setMaximumSize(600,400);
    this->vboxlayoutGauche->addWidget(gHaut);
    this->vboxlayoutGauche->addWidget(gBas);

    // Pour la grid haute
    this->gridLayout = new QGridLayout();
    this->gHaut->setLayout(gridLayout);
    this->gridLayout->addWidget(this->boutonEntreprise,1,0);
    this->gridLayout->addWidget(this->boutonMds,1,1);
    this->gridLayout->addWidget(this->boutonEtudiant,1,2);
    this->gridLayout->addWidget(this->boutonLocalite,1,3);
    this->gridLayout->addWidget(this->boutonAjouter,0,3);

    // // Création de la barre de recherche


    // Connecter le signal de clic du bouton de recherche à une fonction
    connect(searchLineEdit, &QLineEdit::returnPressed, [this]() {
        // Afficher le texte saisi dans la console
        qDebug() << "Texte de recherche : " << searchLineEdit->text();

        afficherResultatsDeRecherche();
    });

    // // Ajouter la barre de recherche à la disposition gauche
    this->gridLayout->addWidget(searchLineEdit,0,0,1,2);


    this->menuDeroulant->addItem("Ajouter une Entreprise");
    this->menuDeroulant->addItem("Ajouter un Etudiant");
    this->menuDeroulant->addItem("Ajouter un Contact");
    this->gridLayout->addWidget(this->menuDeroulant,0,2);

    connect(menuDeroulant, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::showPopup);


    this->vboxResultatsgBas = new QVBoxLayout();
    this->gBas->setLayout(vboxResultatsgBas);
    // Resultats de la fonction recherche qui utilisera le layout ci-dessus

    this->vboxResultatsgBas->addWidget(scrollArea);

    // Création d'un widget pour contenir les résultats de recherche

    this->layoutResultats = new QVBoxLayout();

    this->layoutResultats->addWidget(widgetResultats);

    // Ajouter le widget des résultats à la QScrollArea
    this->scrollArea->setWidget(widgetResultats);
    this->scrollArea->setWidgetResizable(true);

    this->widgetResultats->setMinimumSize(300, 300);
    this->widgetResultats->setStyleSheet("background-color: lightGray; border: 10px solid black;");
}

void MainWindow::init_logo(void){
    QPixmap logoPixmap("../contact/ressources/image/LOGO_ESEO.jpg");
    if (logoPixmap.isNull()) {
        qDebug() << "Erreur : Impossible de charger l'image du logo.";
    }



    logoPixmap = logoPixmap.scaledToWidth(100, Qt::SmoothTransformation);

    logoLabel->setPixmap(logoPixmap);

    this->hboxlayoutHaut->addWidget(logoLabel, 0, Qt::AlignTop | Qt::AlignLeft);
}

void MainWindow::init_pGauche(void){

}

void MainWindow::afficherResultatsDeRecherche()
{
    // Supprimer tous les anciens résultats avant d'afficher les nouveaux
    QLayoutItem *item;
    while ((item = layoutResultats->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Ajouter de nouveaux widgets pour chaque résultat
    QStringList noms = {"Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hank", "Ivy", "Jack"};
    for (const QString &nom : noms) {
        // Créer un widget de résultat (par exemple, un QLabel pour afficher du texte)
        QLabel *labelResultat = new QLabel(nom);
        layoutResultats->addWidget(labelResultat);
        // Ajoutez d'autres widgets ou personnalisez selon vos besoins
    }
}

void MainWindow::showPopup(int index) {

    if (index == 0) { // Check if the selected item is "Ajouter une Entreprise"
        FormulaireAjoutEntreprise *popupEntreprise = new FormulaireAjoutEntreprise(this);
        popupEntreprise->exec();
    }

    if (index == 1) { // Check if the selected item is "Ajouter un Etudiant"
        FormulaireAjoutEtudiant *popupEtudiant = new FormulaireAjoutEtudiant(this);
        popupEtudiant->exec();
    }

    if (index == 2) { // Check if the selected item is "Ajouter un Contact"
        FormulaireAjoutContact *popupContact = new FormulaireAjoutContact(this);
        popupContact->exec();
    }


MainWindow::~MainWindow()
{
    delete this->vboxlayout;
    delete this->principal;
}
