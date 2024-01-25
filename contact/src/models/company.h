#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <iostream>
#include <vector>
#include "mds.h"

class Company{
    private:
        int id;
        std::string nom;
        std::string domaine;
        std::vector<Mds*> mdsList;

    public:
        //CONSTRUCTEUR
        Company();
        Company(int id, std::string nom, std::string domaine);

        // Getters
        int getId();
        std::string getNom();
        std::string getDomaine();
        std::vector<Mds*> getMdsList();

        // Setters
        void setId(int id);
        void setNom(std::string nom);
        void setDomaine(std::string domaine);
        void setMdsList(std::vector<Mds*> mdsList);
        void addMds(Mds* mds);
};

#endif // COMPANY_H
