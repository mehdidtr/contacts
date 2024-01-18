#include "company.h"

//Constructeur
Company::Company(int id, std::string nom, std::string domaine) : ID_Entreprise(id), Nom(nom), Domaine(domaine) {

}

// Getters
int Company::getID_Entreprise() {
    return ID_Entreprise;
}

std::string Company::getNom() {
    return Nom;
}

std::string Company::getDomaine() {
    return Domaine;
}

// Setters
void Company::setID_Entreprise(int id) {
    ID_Entreprise = id;
}

void Company::setNom(std::string nom) {
    Nom = nom;
}

void Company::setDomaine(std::string domaine) {
    Domaine = domaine;
}
