#ifndef FORMULAIREAJOUTENTREPRISE_H
#define FORMULAIREAJOUTENTREPRISE_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>

class FormulaireAjoutEntreprise : public QMainWindow {

    Q_OBJECT

private :
    QWidget* centre;
    QLabel* label;
    QVBoxLayout* vboxlayout;

public :
    FormulaireAjoutEntreprise(QWidget *parent = nullptr);
    ~FormulaireAjoutEntreprise( );

private :
    void init_components ( void );
    void init_layout ( void );
};

#endif // FORMULAIREAJOUTENTREPRISE_H
