#include "company.h"
#include <iostream>

//Constructeur
company::company(int id, std::string nom, std::string domaine) : ID_Entreprise(id), Nom(nom), Domaine(domaine) {

}

// Getters
int company::getID_Entreprise() {
    return ID_Entreprise;
}

std::string company::getNom() {
    return Nom;
}

std::string company::getDomaine() {
    return Domaine;
}

// Setters
void company::setID_Entreprise(int id) {
    ID_Entreprise = id;
}

void company::setNom(std::string nom) {
    Nom = nom;
}

void company::setDomaine(std::string domaine) {
    Domaine = domaine;
}
