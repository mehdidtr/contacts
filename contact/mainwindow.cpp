#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "src/view/formulaireAjoutEntreprise.h"
#include "src/view/formulaireAjoutContact.h"
#include "src/view/formulaireAjoutEtudiant.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Ma fenêtre Qt");
    this->setGeometry(100, 100, 800, 600);
    this->init_components();
    this->init_layout();
    this->init_logo();


    //this->init_pGauche();
}

void MainWindow::init_components(void)
{
    this->principal = new QWidget();
    this->droite = new QWidget();
    this->gauche = new QWidget();
    this->bas = new QWidget();
    this->haut = new QWidget();
    this->gBas = new QWidget();
    this->gHaut = new QWidget();
    this->pDroiteWidget = new QWidget();
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

void MainWindow::init_layout(void)
{
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

    this->gauche->setMaximumSize(500,600);

    // Pour la subdivision gauche
    this->vboxlayoutGauche = new QVBoxLayout();
    this->gauche->setLayout(vboxlayoutGauche);
    this->gauche->setMaximumSize(600,400);
    this->vboxlayoutGauche->addWidget(gHaut);
    this->vboxlayoutGauche->addWidget(gBas);

    // Pour la subdivision droite
    this->pDroiteLayout = new QVBoxLayout();
    this->droite->setLayout(pDroiteLayout);
    this->init_pDroite();

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
        qDebug() << "Texte de recherche : " << searchLineEdit->text();

        afficherResultatsDeRecherche();
    });

    // Ajouter la barre de recherche à la disposition gauche
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

    // Create a QVBoxLayout to hold the components
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

void MainWindow::init_pGauche(void){}

void MainWindow::init_pDroite(void)
{
    this->clear_pDroite();

    /* Init */
    this->pDroiteLayout->addWidget(droite);
    this->TitleCompany = new QLabel("Entreprise:");
    this->companyDetails = new QLabel(getCompanyAllData(1));
    this->TitleSubject = new QLabel("Sujet du stage:");
    this->subjectDetails = new QLabel(getSubjectData(1));
    this->TitleMDS = new QLabel("Maître de stage:");
    this->mdsDetails = new QLabel(getMDSAllData(1));
    this->TitleStudent = new QLabel("Etudiant:");
    this->studentDetails = new QLabel(getStudentAllData(1));
    this->push_button_modify = new QPushButton("Modifier");
    connect(push_button_modify, &QPushButton::clicked, this, &MainWindow::onModifierButtonClicked);
    this->push_button_modify->setFixedWidth(100);

    /* Font Title*/
    fontTitle.setPointSize(14);
    TitleCompany->setFont(fontTitle);
    TitleCompany->setStyleSheet("font-weight: bold;");
    TitleSubject->setFont(fontTitle);
    TitleSubject->setStyleSheet("font-weight: bold;");
    TitleMDS->setFont(fontTitle);
    TitleMDS->setStyleSheet("font-weight: bold;");
    TitleStudent->setFont(fontTitle);
    TitleStudent->setStyleSheet("font-weight: bold;");

    /* Font SubTitle*/
    fontSubTitle.setPointSize(12);
    companyDetails->setFont(fontSubTitle);
    companyDetails->setIndent(40);
    subjectDetails->setFont(fontSubTitle);
    subjectDetails->setIndent(40);
    mdsDetails->setFont(fontSubTitle);
    mdsDetails->setIndent(40);
    studentDetails->setFont(fontSubTitle);
    studentDetails->setIndent(40);

    /* AddWidget */
    pDroiteLayout->addWidget(TitleCompany);
    pDroiteLayout->addWidget(companyDetails);
    pDroiteLayout->addWidget(TitleSubject);
    pDroiteLayout->addWidget(subjectDetails);
    pDroiteLayout->addWidget(TitleMDS);
    pDroiteLayout->addWidget(mdsDetails);
    pDroiteLayout->addWidget(TitleStudent);
    pDroiteLayout->addWidget(studentDetails);
    pDroiteLayout->addWidget(push_button_modify, 0, Qt::AlignRight);
}

void MainWindow::onModifierButtonClicked()
{
    QMetaObject::invokeMethod(this, "init_pDroite_Modify", Qt::QueuedConnection);
}

void MainWindow::init_pDroite_Modify(void)
{
    this->clear_pDroite();

    // Créer une méthode qui récupère les id

    /* Init */
    this->pDroiteLayout->addWidget(droite);
    this->TitleCompany = new QLabel("Entreprise:");
    this->TitleSubject = new QLabel("Sujet du stage:");
    this->TitleMDS = new QLabel("Maître de stage:");
    this->TitleStudent = new QLabel("Etudiant:");

    this->lineEditCompanyName = new QLineEdit(getCompanyName(1));
    this->lineEditCompanyDomain = new QLineEdit(getCompanyDomain(1));
    this->lineEditSubject = new QLineEdit(getSubjectData(1));
    this->lineEditMDSName = new QLineEdit(getMDSName(1));
    this->lineEditMDSSurname = new QLineEdit(getMDSSurname(1));
    this->lineEditMDSContact = new QLineEdit(getMDSContact(1));
    this->lineEditStudentName = new QLineEdit(getStudentNom(1));
    this->lineEditStudentSurname = new QLineEdit(getStudentPrenom(1));
    this->lineEditStudentMail = new QLineEdit(getStudentMail(1));
    this->lineEditStudentPromotion = new QLineEdit(getStudentPromotion(1));

    this->push_button_save = new QPushButton("Enregistrer");
    connect(push_button_save, &QPushButton::clicked, this, &MainWindow::onSauvegarderButtonClicked);
    this->push_button_save->setFixedWidth(100);

    /* Font Title */
    fontTitle.setPointSize(14);
    TitleCompany->setFont(fontTitle);
    TitleCompany->setStyleSheet("font-weight: bold;");
    TitleSubject->setFont(fontTitle);
    TitleSubject->setStyleSheet("font-weight: bold;");
    TitleMDS->setFont(fontTitle);
    TitleMDS->setStyleSheet("font-weight: bold;");
    TitleStudent->setFont(fontTitle);
    TitleStudent->setStyleSheet("font-weight: bold;");

    /* AddWidget */
    pDroiteLayout->addWidget(TitleCompany);
    pDroiteLayout->addWidget(lineEditCompanyName);
    pDroiteLayout->addWidget(lineEditCompanyDomain);
    pDroiteLayout->addWidget(TitleSubject);
    pDroiteLayout->addWidget(lineEditSubject);
    pDroiteLayout->addWidget(TitleMDS);
    pDroiteLayout->addWidget(lineEditMDSName);
    pDroiteLayout->addWidget(lineEditMDSSurname);
    pDroiteLayout->addWidget(lineEditMDSContact);
    pDroiteLayout->addWidget(TitleStudent);
    pDroiteLayout->addWidget(lineEditStudentName);
    pDroiteLayout->addWidget(lineEditStudentSurname);
    pDroiteLayout->addWidget(lineEditStudentMail);
    pDroiteLayout->addWidget(lineEditStudentPromotion);
    pDroiteLayout->addWidget(push_button_save, 0, Qt::AlignRight);
}

void MainWindow::onSauvegarderButtonClicked()
{
    QString companyName = lineEditCompanyName->text();
    QString companyDomain = lineEditCompanyDomain->text();
    QString subject = lineEditSubject->text();
    QString mdsName = lineEditMDSName->text();
    QString mdsSurname = lineEditMDSSurname->text();
    QString mdsContact = lineEditMDSContact->text();
    QString studentName = lineEditStudentName->text();
    QString studentSurname = lineEditStudentSurname->text();
    QString studentMail = lineEditStudentMail->text();
    QString studentPromotion = lineEditStudentPromotion->text();

    setCompanyData(companyName, companyDomain, 1);
    setSubjectData(subject, 1);
    setMDSData(mdsName, mdsSurname, mdsContact, 1);
    setStudentData(studentName, studentSurname, studentMail, studentPromotion, 1);

    QMetaObject::invokeMethod(this, "init_pDroite", Qt::QueuedConnection);
}

void MainWindow::clear_pDroite ( void )
{
    QLayoutItem* item;
    if ( this->pDroiteLayout->count() > 0 ){
        while((item = this->pDroiteLayout->takeAt(0)) != nullptr) {
            this->pDroiteLayout->removeItem(item);
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
    }
}

void MainWindow::afficherResultatsDeRechercheEntreprise(std::vector<Company> companies, QScrollArea* scrollArea)
{
    // Supprimer tous les anciens résultats avant d'afficher les nouveaux
    QLayoutItem *item;
    while ((item = layoutResultats->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    QStringList noms = {"Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hank", "Ivy", "Jack"};
    for (const QString &nom : noms) {
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
    delete ui;
    delete this->principal;
    delete this->vboxlayout;
}

Type MainWindow::getType()
{
    return this->type;
}
void MainWindow::setType(Type type)
{
    this->type = type;
}
