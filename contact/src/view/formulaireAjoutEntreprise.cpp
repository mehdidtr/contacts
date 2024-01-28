// #include "formulaireAjoutEntreprise.h"

// FormulaireAjoutEntreprise::FormulaireAjoutEntreprise(QWidget *parent)
// {

// }

// FormulaireAjoutEntreprise::~FormulaireAjoutEntreprise()
// {
// }

#include "formulaireajoutentreprise.h"
#include <QFormLayout>
#include <QDebug>

FormulaireAjoutEntreprise::FormulaireAjoutEntreprise(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Ajout d'une entreprise");

    nomEntreprise = new QLineEdit();
    domaineEntreprise = new QLineEdit();
    validerButton = new QPushButton("Valider");

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Nom de l'entreprise :", nomEntreprise);
    formLayout->addRow("Domaine de l'entreprise :", domaineEntreprise);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(validerButton);

    connect(validerButton, &QPushButton::clicked, this, &FormulaireAjoutEntreprise::validerButtonClicked);
}

FormulaireAjoutEntreprise::~FormulaireAjoutEntreprise()
{
    // Destruction des widgets
}

void FormulaireAjoutEntreprise::validerButtonClicked()
{
    QString nom = nomEntreprise->text();
    QString domaine = domaineEntreprise->text();

    qDebug() << "Nom: " << nom << ", Domaine: " << domaine;

    accept();
}
