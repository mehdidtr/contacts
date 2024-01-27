#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("CONTACT");
    this->init_components();
    this->init_layout();
    this->init_pDroite();
}

void MainWindow::init_components(void)
{
    this->centre = new QWidget();
    this->pDroiteWidget = new QWidget();
}

void MainWindow::init_layout(void)
{
    this->setCentralWidget(this->centre);
    this->vboxlayout = new QVBoxLayout();
    this->centre->setLayout(this->vboxlayout);
    this->pDroiteLayout = new QVBoxLayout();

}

void MainWindow::dataFromController(int id)
{
    // Récupérer la bonne ligne du CSV grâce à l'id de stage retourné par Maxime !!!!
//    dataCtrl = new dataController();

//    std::vector<Company> companyName = dataCtrl->getData<Company>();

//    auto it = std::find_if(companyName.begin(), companyName.end(), [id](const Company& company) {
//       return company.getId() == id;
//    });

//    // Vérifier si l'entreprise avec l'ID spécifié a été trouvée
//    if (it != companyName.end()) {
//        // L'entreprise a été trouvée, faites quelque chose avec les données
//        const Company& foundCompany = *it;

//        // Par exemple, afficher le nom de l'entreprise dans un QLineEdit
//        ui->lineEditCompany->setText(QString::fromStdString(foundCompany.getNom()));
//    } else {
//        // L'entreprise avec l'ID spécifié n'a pas été trouvée, faites quelque chose en conséquence
//        ui->lineEditCompany->setText("Entreprise non trouvée");
//    }

}

void MainWindow::init_pDroite(void)
{
    this->clear_pDroite();


    //Conversion de CSV à string
//    if (!companyName.empty()) {
//        QString companyInfo = "Company Name: " + QString::fromStdString(companyName[0].getName());
//        this->SubTitleCompany_Name = new QLabel(companyInfo);
//    } else {
//        // Gérer le cas où le vecteur est vide
//        this->SubTitleCompany_Name = new QLabel("Aucune entreprise disponible");
//    }

    /* Init */
    this->pDroiteWidget->setLayout(this->pDroiteLayout);
    this->TitleCompany = new QLabel("Entreprise:");
    this->SubTitleCompany_Name = new QLabel("METTRE GETDATA");
    this->SubTitleCompany_domain = new QLabel("METTRE GETDATA");

    this->TitleSubject = new QLabel("Sujet du stage: ");
    this->SubjectDetails = new QLabel("METTRE GETDATA");

    this->TitleMDSInfo = new QLabel("Maître de stage:");
    this->SubTitleMDS_Name = new QLabel("METTRE GETDATA");
    this->SubTitleMDS_Surname = new QLabel("METTRE GETDATA");
    this->SubTitleMDS_Contact = new QLabel("METTRE GETDATA");

    this->TitleStudentInfo = new QLabel("Etudiant:");
    this->SubTitleStudent_Name = new QLabel("Nom Etu");
    this->SubTitleStudent_Surname = new QLabel("Prénom Etu");
    this->SubTitleStudent_Mail = new QLabel("Mail Etu");
    this->SubTitleStudent_Promotion = new QLabel("Promotion Etu");

    this->push_button_modify = new QPushButton("Modifier");
    connect(push_button_modify, &QPushButton::clicked, this, &MainWindow::init_pDroite_Modify);
    this->push_button_modify->setFixedWidth(100);

    /* Font Title*/
    fontTitle.setPointSize(14);
    TitleCompany->setFont(fontTitle);
    TitleCompany->setStyleSheet("font-weight: bold;");
    TitleSubject->setFont(fontTitle);
    TitleSubject->setStyleSheet("font-weight: bold;");
    TitleMDSInfo->setFont(fontTitle);
    TitleMDSInfo->setStyleSheet("font-weight: bold;");
    TitleStudentInfo->setFont(fontTitle);
    TitleStudentInfo->setStyleSheet("font-weight: bold;");

    /* Font SubTitle*/
    fontSubTitle.setPointSize(12);
    SubTitleCompany_Name->setFont(fontSubTitle);
    SubTitleCompany_Name->setIndent(40);
    SubTitleCompany_domain->setFont(fontSubTitle);
    SubTitleCompany_domain->setIndent(40);
    SubjectDetails->setFont(fontSubTitle);
    SubjectDetails->setIndent(40);
    SubTitleMDS_Name->setFont(fontSubTitle);
    SubTitleMDS_Name->setIndent(40);
    SubTitleMDS_Surname->setFont(fontSubTitle);
    SubTitleMDS_Surname->setIndent(40);
    SubTitleMDS_Contact->setFont(fontSubTitle);
    SubTitleMDS_Contact->setIndent(40);
    SubTitleStudent_Name->setFont(fontSubTitle);
    SubTitleStudent_Name->setIndent(40);
    SubTitleStudent_Surname->setFont(fontSubTitle);
    SubTitleStudent_Surname->setIndent(40);
    SubTitleStudent_Mail->setFont(fontSubTitle);
    SubTitleStudent_Mail->setIndent(40);
    SubTitleStudent_Promotion->setFont(fontSubTitle);
    SubTitleStudent_Promotion->setIndent(40);

    /* AddWidget */
    pDroiteLayout->addWidget(TitleCompany);
    pDroiteLayout->addWidget(SubTitleCompany_Name);
    pDroiteLayout->addWidget(SubTitleCompany_domain);
    pDroiteLayout->addWidget(TitleSubject);
    pDroiteLayout->addWidget(SubjectDetails);
    pDroiteLayout->addWidget(TitleMDSInfo);
    pDroiteLayout->addWidget(SubTitleMDS_Name);
    pDroiteLayout->addWidget(SubTitleMDS_Surname);
    pDroiteLayout->addWidget(SubTitleMDS_Contact);
    pDroiteLayout->addWidget(TitleStudentInfo);
    pDroiteLayout->addWidget(SubTitleStudent_Name);
    pDroiteLayout->addWidget(SubTitleStudent_Surname);
    pDroiteLayout->addWidget(SubTitleStudent_Mail);
    pDroiteLayout->addWidget(SubTitleStudent_Promotion);
    pDroiteLayout->addWidget(push_button_modify, 0, Qt::AlignRight);

    /* */
    pDroiteWidget->setLayout(pDroiteLayout);

    this->mainLayout = qobject_cast<QVBoxLayout*>(centre->layout());

    if (mainLayout) {
        mainLayout->addWidget(pDroiteWidget, 0, Qt::AlignTop);
    }
}

void MainWindow::init_pDroite_Modify(void)
{
    this->clear_pDroite();

    /* Init */
    this->pDroiteWidget->setLayout(this->pDroiteLayout);
    this->TitleCompany = new QLabel("Entreprise:");
    this->TitleSubject = new QLabel("Sujet du stage:");
    this->TitleMDSInfo = new QLabel("Maître de stage:");
    this->TitleStudentInfo = new QLabel("Etudiant:");
    this->push_button_save = new QPushButton("Enregistrer");

    this->lineEditCompanyName = new QLineEdit();
    this->lineEditCompanyDomain = new QLineEdit();
    this->lineEditSubject = new QLineEdit();
    this->lineEditMDSName = new QLineEdit();
    this->lineEditMDSSurname = new QLineEdit();
    this->lineEditMDSContact = new QLineEdit();
    this->lineEditStudentName = new QLineEdit();
    this->lineEditStudentSurname = new QLineEdit();
    this->lineEditStudentMail = new QLineEdit();
    this->lineEditStudentPromotion = new QLineEdit();

    connect(push_button_save, &QPushButton::clicked, this, &MainWindow::init_pDroite);
    this->push_button_save->setFixedWidth(100);

    /* Font Title */
    fontTitle.setPointSize(14);
    TitleCompany->setFont(fontTitle);
    TitleCompany->setStyleSheet("font-weight: bold;");
    TitleSubject->setFont(fontTitle);
    TitleSubject->setStyleSheet("font-weight: bold;");
    TitleMDSInfo->setFont(fontTitle);
    TitleMDSInfo->setStyleSheet("font-weight: bold;");
    TitleStudentInfo->setFont(fontTitle);
    TitleStudentInfo->setStyleSheet("font-weight: bold;");

    /* AddWidget */
    pDroiteLayout->addWidget(TitleCompany);
    pDroiteLayout->addWidget(lineEditCompanyName);
    pDroiteLayout->addWidget(lineEditCompanyDomain);

    pDroiteLayout->addWidget(TitleSubject);
    pDroiteLayout->addWidget(lineEditSubject);

    pDroiteLayout->addWidget(TitleMDSInfo);
    pDroiteLayout->addWidget(lineEditMDSName);
    pDroiteLayout->addWidget(lineEditMDSSurname);
    pDroiteLayout->addWidget(lineEditMDSContact);

    pDroiteLayout->addWidget(TitleStudentInfo);
    pDroiteLayout->addWidget(lineEditStudentName);
    pDroiteLayout->addWidget(lineEditStudentSurname);
    pDroiteLayout->addWidget(lineEditStudentMail);
    pDroiteLayout->addWidget(lineEditStudentPromotion);

    pDroiteLayout->addWidget(push_button_save, 0, Qt::AlignRight);

    mainLayout->addWidget(pDroiteWidget, 0, Qt::AlignTop);
}

void MainWindow::clear_pDroite ( void )
{
    QLayoutItem *item;
    if ( this->pDroiteLayout->count() > 0 )
    {
        while((item = this->pDroiteLayout->takeAt(0))) {
            this->pDroiteLayout->removeItem(item);
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->centre;
}
