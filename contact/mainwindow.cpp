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
}

void MainWindow::init_layout(void)
{
    this->setCentralWidget(this->centre);
    this->vboxlayout = new QVBoxLayout();
    this->centre->setLayout(this->vboxlayout);
}

void MainWindow::init_pDroite(void)
{
    /* Init */
    this->pDroiteWidget = new QWidget();
    this->pDroiteLayout = new QVBoxLayout(pDroiteWidget);
    this->TitleCompany = new QLabel("Entreprise:");
    this->TitleSubject = new QLabel("Sujet du stage:");
    this->TitleMDSInfo = new QLabel("Maître de stage:");
    this->TitleStudentInfo = new QLabel("Etudiant:");
    this->push_button = new QPushButton("Modifier");

    /* */
    this->push_button->setFixedWidth(100);

    /* Font Title*/
    QFont fontTitle;
    fontTitle.setPointSize(16);
    TitleCompany->setFont(fontTitle);
    TitleSubject->setFont(fontTitle);
    TitleMDSInfo->setFont(fontTitle);
    TitleStudentInfo->setFont(fontTitle);

    /* Font SubTitle*/

    /* AddWidget */
    pDroiteLayout->addWidget(TitleCompany);
    pDroiteLayout->addWidget(TitleSubject);
    pDroiteLayout->addWidget(TitleMDSInfo);
    pDroiteLayout->addWidget(TitleStudentInfo);


    pDroiteLayout->addWidget(push_button);

    /* */
    pDroiteWidget->setLayout(pDroiteLayout);

    this->mainLayout = qobject_cast<QVBoxLayout*>(centre->layout());

    if (mainLayout) {
        mainLayout->addWidget(pDroiteWidget, 0, Qt::AlignTop);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->centre;
}
