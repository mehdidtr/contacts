#include "formulaireajoutetudiant.h"
#include <QFormLayout>
#include <QDebug>

FormulaireAjoutEtudiant::FormulaireAjoutEtudiant(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Ajout d'un étudiant");

    nomEtudiant = new QLineEdit();
    prenomEtudiant = new QLineEdit();
    promotionEtudiant = new QLineEdit();
    mailEtudiant = new QLineEdit();
    validerButton = new QPushButton("Valider");

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Nom de l'étudiant :", nomEtudiant);
    formLayout->addRow("Prénom de l'étudiant :", prenomEtudiant);
    formLayout->addRow("Promotion de l'étudiant :", promotionEtudiant);
    formLayout->addRow("Mail de l'étudiant :", mailEtudiant);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(validerButton);

    connect(validerButton, &QPushButton::clicked, this, &FormulaireAjoutEtudiant::validerButtonClicked);
}

FormulaireAjoutEtudiant::~FormulaireAjoutEtudiant()
{
    // Destruction des widgets
}

void FormulaireAjoutEtudiant::validerButtonClicked()
{
    QString nom = nomEtudiant->text();
    QString prenom = prenomEtudiant->text();
    QString promotion = promotionEtudiant->text();
    QString mail = mailEtudiant->text();

    qDebug() << "Nom: " << nom << ", Prenom: " << prenom << ", Promotion: " << promotion << ", Mail: " << mail;

    accept();
}
