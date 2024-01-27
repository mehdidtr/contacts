#include "formulaireajoutcontact.h"
#include <QFormLayout>
#include <QDebug>

FormulaireAjoutContact::FormulaireAjoutContact(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Ajout d'un contact");

    nomContact = new QLineEdit();
    prenomContact = new QLineEdit();
    positionContact = new QLineEdit();
    entrepriseComboBox = new QComboBox();
    mailContact = new QLineEdit();
    telContact = new QLineEdit();
    validerButton = new QPushButton("Valider");

    // Simulation de données d'entreprises (à remplacer par vos données réelles)
    entrepriseComboBox->addItem("Entreprise 1", QVariant("Entreprise 1"));
    entrepriseComboBox->addItem("Entreprise 2", QVariant("Entreprise 2"));
    entrepriseComboBox->addItem("Entreprise 3", QVariant("Entreprise 3"));

    QFormLayout *formLayout = new QFormLayout();
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

    qDebug() << "Nom: " << nom << ", Prenom: " << prenom << ", Position: " << position
             << ", Entreprise: " << entreprise << ", Mail: " << mail << ", Tel: " << tel;

    accept();
}
