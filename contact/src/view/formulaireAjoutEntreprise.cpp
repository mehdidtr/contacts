#include "formulaireAjoutEntreprise.h"

FormulaireAjoutEntreprise::FormulaireAjoutEntreprise (QWidget* parent) : QMainWindow (parent){
    this->setWindowTitle("Ma fenêtre Qt");
    this->setGeometry(100, 100, 800, 600);
    this->init_components();
    this->init_layout();
}

void FormulaireAjoutEntreprise::init_components (void){
    this->centre = new QWidget();
    this->label = new QLabel ("Ceci est un label");
}

void FormulaireAjoutEntreprise::init_layout (void){
    this->setCentralWidget(this->centre);
    this->vboxlayout = new QVBoxLayout();
    this->centre->setLayout(this->vboxlayout);
    this->vboxlayout->addWidget(this->label);
}

FormulaireAjoutEntreprise::~FormulaireAjoutEntreprise(){
    delete this->label;
    delete this->vboxlayout;
    delete this->centre;
}
