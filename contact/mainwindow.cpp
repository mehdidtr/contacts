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
    MainWindow::setStudentId(0);
    MainWindow::setMdsId(0);
    MainWindow::setCompanyId(0);
    if (MainWindow::getType() == Type::Entreprise){
        std::vector<Company> research = companyController::searchCompanyByName("");
        afficherResultatsDeRechercheEntreprise(research, scrollArea);
    }
    else if (MainWindow::getType() == Type::Mds){
        std::vector<Mds> research = mdsController::searchMdsByName("");
            afficherResultatsDeRechercheMds(research, scrollArea);
    }
    else if (MainWindow::getType() == Type::Etudiant){
        std::vector<Student> research = studentController::searchStudentByName("");
        afficherResultatsDeRechercheEtudiant(research, scrollArea);
    }
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
    connect(boutonEntreprise, &QPushButton::clicked, [this]() {
        setType(Type::Entreprise);
        searchLineEdit->setText("");
        std::vector<Company> research = companyController::searchCompanyByName("");
        afficherResultatsDeRechercheEntreprise(research, scrollArea);
    });
    connect(boutonMds, &QPushButton::clicked, [this]() {
        setType(Type::Mds);
        searchLineEdit->setText("");
        std::vector<Mds> research = mdsController::searchMdsByName("");
        afficherResultatsDeRechercheMds(research, scrollArea);
    });
    connect(boutonEtudiant, &QPushButton::clicked, [this]() {
        setType(Type::Etudiant);
        searchLineEdit->setText("");
        std::vector<Student> research = studentController::searchStudentByName("");
        afficherResultatsDeRechercheEtudiant(research, scrollArea);
    });

     // Connecter le signal de clic du bouton de recherche à une fonction
    connect(searchLineEdit, &QLineEdit::returnPressed, [this]() {
        // Afficher le texte saisi dans la console
        qDebug() << "Texte de recherche : " << searchLineEdit->text();
        if (MainWindow::getType() == Type::Entreprise){
            std::vector<Company> research = companyController::searchCompanyByName(searchLineEdit->text().toStdString());
            afficherResultatsDeRechercheEntreprise(research, scrollArea);
        }
        else if (MainWindow::getType() == Type::Mds){
            std::vector<Mds> research = mdsController::searchMdsByName(searchLineEdit->text().toStdString());
            afficherResultatsDeRechercheMds(research, scrollArea);
        }
        else if (MainWindow::getType() == Type::Etudiant){
            std::vector<Student> research = studentController::searchStudentByName(searchLineEdit->text().toStdString());
            afficherResultatsDeRechercheEtudiant(research, scrollArea);
        }
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

    this->lineEditCompanyName = new QLineEdit(getCompanyName(MainWindow::getCompanyId()));
    this->lineEditCompanyDomain = new QLineEdit(getCompanyDomain(MainWindow::getCompanyId()));
    this->lineEditSubject = new QLineEdit(getSubjectData(MainWindow::getCompanyId()));
    this->lineEditMDSName = new QLineEdit(getMDSName(MainWindow::getMdsId()));
    this->lineEditMDSSurname = new QLineEdit(getMDSSurname(MainWindow::getMdsId()));
    this->lineEditMDSContact = new QLineEdit(getMDSContact(MainWindow::getMdsId()));
    this->lineEditStudentName = new QLineEdit(getStudentNom(MainWindow::getStudentId()));
    this->lineEditStudentSurname = new QLineEdit(getStudentPrenom(MainWindow::getStudentId()));
    this->lineEditStudentMail = new QLineEdit(getStudentMail(MainWindow::getStudentId()));
    this->lineEditStudentPromotion = new QLineEdit(getStudentPromotion(MainWindow::getStudentId()));

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
    QVBoxLayout* scrollLayout = new QVBoxLayout();


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

    // Add components for each company to the scroll layout
    for (Company& company : companies) {
        // Create a button for each company with the name and domain as the button's text
        QPushButton* button = new QPushButton(company.getNom().c_str() + QString(" - ") + company.getDomaine().c_str());
        scrollLayout->addWidget(button);
        // Le bouton sont plat et grand pour que l'utilisateur puisse cliquer dessus facilement
        button->setFlat(true);
        button->setMinimumHeight(50);
        // Le bouton est en gras pour que l'utilisateur puisse voir le nom de l'entreprise et avec des contours noirs pour que l'utilisateur puisse voir les limites du bouton
        button->setStyleSheet("font-weight: bold; border: 1px solid black;");
        // Change le curseur de la souris quand il passe sur le bouton
        button->setCursor(Qt::PointingHandCursor);
        // Connect the button's clicked signal to a lambda function
        int id = company.getId();
        connect(button, &QPushButton::clicked, [this, id]() {
            qDebug() << "Clicked on company " << id;
            MainWindow::setCompanyId(id);
        });
    // Set the scroll layout as the widget for the scroll area
    QWidget* scrollWidget = new QWidget();
    scrollWidget->setLayout(scrollLayout);
    this->scrollArea->setWidget(scrollWidget);

    }
}
void MainWindow::afficherResultatsDeRechercheEtudiant(std::vector<Student> students, QScrollArea* scrollArea)
{
    QVBoxLayout* scrollLayout = new QVBoxLayout();
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

    // Add components for each company to the scroll layout
    for (Student& student : students) {
        // Create a button for each company with the name and domain as the button's text
        QPushButton* button = new QPushButton(student.getNom().c_str() + QString(" ") + student.getPrenom().c_str());
        scrollLayout->addWidget(button);
        // Le bouton sont plat et grand pour que l'utilisateur puisse cliquer dessus facilement
        button->setFlat(true);
        button->setMinimumHeight(50);
        // Le bouton est en gras pour que l'utilisateur puisse voir le nom de l'entreprise et avec des contours noirs pour que l'utilisateur puisse voir les limites du bouton
        button->setStyleSheet("font-weight: bold; border: 1px solid black;");
        // Change le curseur de la souris quand il passe sur le bouton
        button->setCursor(Qt::PointingHandCursor);
        // Connect the button's clicked signal to a lambda function
        int id = student.getIdStudent();
        connect(button, &QPushButton::clicked, [this, id]() {
            qDebug() << "Clicked on student " << id;
            MainWindow::setStudentId(id);
        });
    // Set the scroll layout as the widget for the scroll area
    QWidget* scrollWidget = new QWidget();
    scrollWidget->setLayout(scrollLayout);
    this->scrollArea->setWidget(scrollWidget);

    }
}
void MainWindow::afficherResultatsDeRechercheMds(std::vector<Mds> mdss, QScrollArea* scrollArea)
{
    QVBoxLayout* scrollLayout = new QVBoxLayout();
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

    // Add components for each company to the scroll layout
    for (Mds& mds : mdss) {
        // Create a button for each company with the name and domain as the button's text
        QPushButton* button = new QPushButton(mds.get_name().c_str() + QString(" ") + mds.get_firstname().c_str());
        scrollLayout->addWidget(button);
        // Le bouton sont plat et grand pour que l'utilisateur puisse cliquer dessus facilement
        button->setFlat(true);
        button->setMinimumHeight(50);
        // Le bouton est en gras pour que l'utilisateur puisse voir le nom de l'entreprise et avec des contours noirs pour que l'utilisateur puisse voir les limites du bouton
        button->setStyleSheet("font-weight: bold; border: 1px solid black;");
        // Change le curseur de la souris quand il passe sur le bouton
        button->setCursor(Qt::PointingHandCursor);
        // Connect the button's clicked signal to a lambda function
        int id = mds.get_id();
        connect(button, &QPushButton::clicked, [this, id]() {
            qDebug() << "Clicked on mds " << id;
            MainWindow::setMdsId(id);
        });
    // Set the scroll layout as the widget for the scroll area
    QWidget* scrollWidget = new QWidget();
    scrollWidget->setLayout(scrollLayout);
    this->scrollArea->setWidget(scrollWidget);

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
/* GET & SET Company */
QString MainWindow::getCompanyAllData(int companyId)
{
    std::vector<Company> listeEntreprises = companyController::getData();
    for(int i = 0; i<listeEntreprises.size(); i++){
        if(listeEntreprises[i].getId() == companyId){
            QString nomEntreprise = listeEntreprises[i].getNom().c_str();
            QString domaineEntreprise = listeEntreprises[i].getDomaine().c_str();
            return nomEntreprise + "\n" + domaineEntreprise;
        }
    }
}

QString MainWindow::getCompanyName(int companyId)
{
    std::vector<Company> listeEntreprises = companyController::getData();
    for(int i = 0; i<listeEntreprises.size(); i++){
        if(listeEntreprises[i].getId() == companyId){
            QString nomEntreprise = listeEntreprises[i].getNom().c_str();
            return nomEntreprise;
        }
    }
}

QString MainWindow::getCompanyDomain(int companyId)
{
    std::vector<Company> listeEntreprises = companyController::getData();
    for(int i = 0; i<listeEntreprises.size(); i++){
        if(listeEntreprises[i].getId() == companyId){
            QString domaineEntreprise = listeEntreprises[i].getDomaine().c_str();
            return domaineEntreprise;
        }
    }
}

void MainWindow::setCompanyData(const QString& nom, const QString& domaine, int companyId)
{
    std::vector<Company> listeEntreprises = companyController::getData();

    for (int i = 0; i<listeEntreprises.size(); i++){
        if(listeEntreprises[i].getId() == companyId){
            listeEntreprises[i].setNom(nom.toStdString());
            listeEntreprises[i].setDomaine(domaine.toStdString());
        }
    }

    companyController::setData(listeEntreprises);
}

/* GET & SET Subject */
QString MainWindow::getSubjectData(int subjectId)
{
    std::vector<Internship> listeInternships = internshipController::getData();
    for(int i = 0; i<listeInternships.size(); i++){
        if(listeInternships[i].getIdInternship() == subjectId){
            QString subject = listeInternships[i].getSubject().c_str();
            return subject;
        }
    }
}

void MainWindow::setSubjectData(const QString& subject, int subjectId)
{
    std::vector<Internship> listeInternships = internshipController::getData();

    for (int i = 0; i<listeInternships.size(); i++){
        if(listeInternships[i].getIdInternship() == subjectId){
            listeInternships[i].setSubject(subject.toStdString());
        }
    }

    internshipController::setData(listeInternships);
}

/* GET & SET MDS */
QString MainWindow::getMDSAllData(int mdsId)
{
    std::vector<Mds> listeMDS = mdsController::getData();
    for(int i = 0; i<listeMDS.size(); i++){
        if(listeMDS[i].get_id() == mdsId){
            QString nomMDS = listeMDS[i].get_name().c_str();
            QString prenomMDS = listeMDS[i].get_firstname().c_str();
            QString contactMDS = listeMDS[i].get_email().c_str();
            return nomMDS + "\n" + prenomMDS + "\n" + contactMDS;
        }
    }
}

QString MainWindow::getMDSName(int mdsId)
{
    std::vector<Mds> listeMDS = mdsController::getData();
    for(int i = 0; i<listeMDS.size(); i++){
        if(listeMDS[i].get_id() == mdsId){
            QString nomMDS = listeMDS[i].get_name().c_str();
            return nomMDS;
        }
    }

    delete dataMDS;
}

QString MainWindow::getMDSSurname(int mdsId)
{ 
    std::vector<Mds> listeMDS = mdsController::getData();
    for(int i = 0; i<listeMDS.size(); i++){
        if(listeMDS[i].get_id() == mdsId){
            QString prenomMDS = listeMDS[i].get_firstname().c_str();
            return prenomMDS;
        }
    }
}

QString MainWindow::getMDSContact(int mdsId)
{
    std::vector<Mds> listeMDS = mdsController::getData();
    for(int i = 0; i<listeMDS.size(); i++){
        if(listeMDS[i].get_id() == mdsId){
            QString contactMDS = listeMDS[i].get_email().c_str();
            return contactMDS;
        }
    }
}

void MainWindow::setMDSData(const QString& mdsName, const QString& mdsSurname, const QString& mdsContact, int mdsId)
{
    std::vector<Mds> listeMDS = mdsController::getData();

    for (int i = 0; i<listeMDS.size(); i++){
        if(listeMDS[i].get_id() == mdsId){
            listeMDS[i].set_name(mdsName.toStdString());
            listeMDS[i].set_firstname(mdsSurname.toStdString());
            listeMDS[i].set_email(mdsContact.toStdString());
        }
    }

    mdsController::setData(listeMDS);
}

/* GET & SET Student */
QString MainWindow::getStudentAllData(int studentId)
{
    std::vector<Student> listeStudent = studentController::getData();
    for(int i = 0; i<listeStudent.size(); i++){
        if(listeStudent[i].getIdStudent() == studentId){
            QString nomStudent = listeStudent[i].getNom().c_str();
            QString prenomStudent = listeStudent[i].getPrenom().c_str();
            QString mailStudent = listeStudent[i].getMail().c_str();
            QString promotionStudent = listeStudent[i].getPromotion().c_str();
            return nomStudent + "\n" + prenomStudent + "\n" + mailStudent + "\n" + promotionStudent;
        }
    }
}

QString MainWindow::getStudentNom(int studentId)
{
    std::vector<Student> listeStudent = studentController::getData();
    for(int i = 0; i<listeStudent.size(); i++){
        if(listeStudent[i].getIdStudent() == studentId){
            QString nomStudent = listeStudent[i].getNom().c_str();
            return nomStudent;
        }
    }

}

QString MainWindow::getStudentPrenom(int studentId)
{
    std::vector<Student> listeStudent = studentController::getData();
    for(int i = 0; i<listeStudent.size(); i++){
        if(listeStudent[i].getIdStudent() == studentId){
            QString prenomStudent = listeStudent[i].getPrenom().c_str();

            return prenomStudent;
        }
    }

}

QString MainWindow::getStudentMail(int studentId)
{
    std::vector<Student> listeStudent = studentController::getData();
    for(int i = 0; i<listeStudent.size(); i++){
        if(listeStudent[i].getIdStudent() == studentId){
            QString mailStudent = listeStudent[i].getMail().c_str();
            return mailStudent;
        }
    }

}

QString MainWindow::getStudentPromotion(int studentId)
{
    std::vector<Student> listeStudent = studentController::getData();
    for(int i = 0; i<listeStudent.size(); i++){
        if(listeStudent[i].getIdStudent() == studentId){
            QString promotionStudent = listeStudent[i].getPromotion().c_str();
            return promotionStudent;
        }
    }

}

void MainWindow::setStudentData(const QString& studentName, const QString& studentSurname, const QString& studentMail, const QString& studentPromotion, int studentId)
{

    std::vector<Student> listeStudent = studentController::getData();

    for (int i = 0; i<listeStudent.size(); i++){
        if(listeStudent[i].getIdStudent() == studentId){
            listeStudent[i].setNom(studentName.toStdString());
            listeStudent[i].setPrenom(studentSurname.toStdString());
            listeStudent[i].setMail(studentMail.toStdString());
            listeStudent[i].setPromotion(studentPromotion.toStdString());
        }
    }

    studentController::setData(listeStudent);
}

int MainWindow::getCompanyId()
{
    return this->idCompany;
}
void MainWindow::setCompanyId(int companyId)
{
    this->idCompany = companyId;
}
int MainWindow::getStudentId()
{
    return this->idStudent;
}
void MainWindow::setStudentId(int idStudent)
{
    this->idStudent = idStudent;
}
int MainWindow::getMdsId()
{
    return this->idMDS;
}
void MainWindow::setMdsId(int mdsId)
{
    this->idMDS = mdsId;
}