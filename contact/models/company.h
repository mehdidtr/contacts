#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <iostream>

class company{
private:
    int ID_Entreprise;
    std::string Nom;
    std::string Domaine;

public:
    //CONSTRUCTEUR
    company();
    company(int id, std::string nom, std::string domaine);

    // Getters
    int getID_Entreprise();
    std::string getNom();
    std::string getDomaine();

    // Setters
    void setID_Entreprise(int id);
    void setNom(std::string nom);
    void setDomaine(std::string domaine);
};

#endif // COMPANY_H
