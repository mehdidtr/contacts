#include "company.h"

//Constructeur
Company::Company(int id, std::string nom, std::string domaine) : id(id), nom(nom), domaine(domaine) {
    this->id = id;
    this->nom = nom;
    this->domaine = domaine;
    this->mdsList = std::vector<Mds*>();
}

// Getters
int Company::getId(){
    return id;
}

std::string Company::getNom(){
    return nom;
}

std::string Company::getDomaine(){
    return domaine;
}

// Setters
void Company::setId(int id) {
    this->id = id;
}

void Company::setNom(std::string nom) {
    this->nom = nom;
}

void Company::setDomaine(std::string domaine) {
    this->domaine = domaine;
}
std::vector<Mds*> Company::getMdsList() {
    return mdsList;
}
void Company::setMdsList(std::vector<Mds*> mdsList) {
    this->mdsList = mdsList;
}
void Company::addMds(Mds* mds) {
    this->mdsList.push_back(mds);
}