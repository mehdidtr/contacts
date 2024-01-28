#include "formulaireajoutcontact.h"
#include "../controller/mdsController.h"
#include "../controller/companyController.h"
#include "../models/mds.h"
#include <QFormLayout>
#include <QDebug>

FormulaireAjoutContact::FormulaireAjoutContact(QWidget *parent): QDialog(parent)
{
    setWindowTitle("Ajout d'un contact");

    nomContact = new QLineEdit();
    prenomContact = new QLineEdit();
    positionContact = new QLineEdit();
    entrepriseComboBox = new QComboBox();
    mailContact = new QLineEdit();
    telContact = new QLineEdit();
    validerButton = new QPushButton("Valider");

    std::vector<Company> CompanyList = companyController::getData();
    foreach (Company company, CompanyList) {
        entrepriseComboBox->addItem(QString::fromStdString(company.getNom()), QVariant(QString::fromStdString(company.getNom())));
    }

    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("Nom du contact :", nomContact);
    formLayout->addRow("Prénom du contact :", prenomContact);
    formLayout->addRow("Position du contact :", positionContact);
    formLayout->addRow("Entreprise :", entrepriseComboBox);
    formLayout->addRow("Mail du contact :", mailContact);
    formLayout->addRow("Téléphone du contact :", telContact);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(validerButton);

    connect(validerButton, &QPushButton::clicked, this, &FormulaireAjoutContact::validerButtonClicked);
}

FormulaireAjoutContact::~FormulaireAjoutContact()
{
    // Destruction des widgets
}

void FormulaireAjoutContact::validerButtonClicked()
{
    QString nom = nomContact->text();
    QString prenom = prenomContact->text();
    QString position = positionContact->text();
    QVariant entrepriseData = entrepriseComboBox->currentData();
    QString entreprise = entrepriseData.toString();
    QString mail = mailContact->text();
    QString tel = telContact->text();

    std::vector<Company> companyList = companyController::getData();
    Company company = companyList[entrepriseComboBox->currentIndex()];
    std::vector<Mds> mdsList = mdsController::getData();
    mdsList.push_back(Mds(mdsList.size(),nom.toStdString(), prenom.toStdString(), mail.toStdString(), tel.toStdString(),position.toStdString(), company.getId()));
    mdsController::setData(mdsList);
    qDebug() << "Nom: " << nom << ", Prenom: " << prenom << ", Position: " << position
             << ", Entreprise: " << entreprise << ", Mail: " << mail << ", Tel: " << tel;

    accept();
}
