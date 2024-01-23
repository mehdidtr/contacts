#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <iostream>

class Company{
    private:
        int id;
        std::string nom;
        std::string domaine;

    public:
        //CONSTRUCTEUR
        Company();
        Company(int id, std::string nom, std::string domaine);

        // Getters
        int getId();
        std::string getNom();
        std::string getDomaine();

        // Setters
        void setId(int id);
        void setNom(std::string nom);
        void setDomaine(std::string domaine);
};

#endif // COMPANY_H
