#ifndef FORMULAIREAJOUTCONTACT_H
#define FORMULAIREAJOUTCONTACT_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

class FormulaireAjoutContact : public QDialog
{
    Q_OBJECT

public:
    FormulaireAjoutContact(QWidget *parent);
    ~FormulaireAjoutContact();

private:
    QLineEdit *nomContact;
    QLineEdit *prenomContact;
    QLineEdit *positionContact;
    QComboBox *entrepriseComboBox;
    QLineEdit *mailContact;
    QLineEdit *telContact;
    QPushButton *validerButton;

private slots:
    void validerButtonClicked();
};

#endif // FORMULAIREAJOUTCONTACT_H
