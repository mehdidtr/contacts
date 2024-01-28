#ifndef FORMULAIREAJOUTETUDIANT_H
#define FORMULAIREAJOUTETUDIANT_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class FormulaireAjoutEtudiant : public QDialog
{
    Q_OBJECT

public:
    FormulaireAjoutEtudiant(QWidget *parent);
    ~FormulaireAjoutEtudiant();

private:
    QLineEdit *nomEtudiant;
    QLineEdit *prenomEtudiant;
    QLineEdit *promotionEtudiant;
    QLineEdit *mailEtudiant;
    QPushButton *validerButton;

private slots:
    void validerButtonClicked();
};

#endif // FORMULAIREAJOUTETUDIANT_H
