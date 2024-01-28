#include "companyController.h"

companyController::companyController(/* args */)
{
}
companyController::~companyController()
{
}

std::vector<Company> companyController::getData(){
    std::cout << "companyController" << std::endl;
    std::vector <Company> listCompany = std::vector<Company>();
    QFile file("../contact/ressources/Entreprise.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return listCompany;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList liste = line.split(";");
        Company company = Company(liste[0].toInt(), liste[1].toStdString(), liste[2].toStdString());
        listCompany.push_back(company);
    }
    file.close();
    return listCompany;
}

void companyController::setData(std::vector<Company> list){
    QFile file("../contact/ressources/Entreprise.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;

    QTextStream out(&file);
    for (int i = 0; i < list.size(); i++){
        out << list[i].getId() << ";" << list[i].getNom().c_str() << ";" << list[i].getDomaine().c_str() << "\n";
    }
    file.close();
}

std::vector<Company> companyController::searchCompanyByName(std::string name = ""){
    std::vector<Company> listCompany = getData();
    if(name == "") return listCompany;
    std::vector<Company> listCompanySearch = std::vector<Company>();
    for (int i = 0; i < listCompany.size(); i++){
        if (listCompany[i].getNom().find(name) != std::string::npos){
            listCompanySearch.push_back(listCompany[i]);
        }
    }
    return listCompanySearch;
}
