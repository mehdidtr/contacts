// #ifndef FORMULAIREAJOUTEENTREPRISE_H
// #define FORMULAIREAJOUTEENTREPRISE_H

// #include <QMainWindow>
// #include <QLabel>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QPushButton>
// #include <QLineEdit>

// #include "src/controller/dataController.h"


// class FormulaireAjoutEntreprise
// {

// private:


// public:
//     FormulaireAjoutEntreprise(QWidget *parent = nullptr);
//     ~FormulaireAjoutEntreprise();

// private:

// };
// #endif // FORMULAIREAJOUTEENTREPRISE_H

#ifndef FORMULAIREAJOUTENTREPRISE_H
#define FORMULAIREAJOUTENTREPRISE_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class FormulaireAjoutEntreprise : public QDialog
{
    Q_OBJECT

public:
    FormulaireAjoutEntreprise(QWidget *parent);
    ~FormulaireAjoutEntreprise();

private:
    QLineEdit *nomEntreprise;
    QLineEdit *domaineEntreprise;
    QPushButton *validerButton;

private slots:
    void validerButtonClicked();
};

#endif // FORMULAIREAJOUTENTREPRISE_H












