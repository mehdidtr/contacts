#include "dataController.h"

dataController::dataController(/* args */)
{
}
dataController::~dataController()
{
}

template<> std::vector<Mds> dataController::getData(){
}

template<> std::vector<Company> dataController::getData(){

    std::vector <Company> listCompany = std::vector<Company>();
    QFile file("../../ressources/Entreprise.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return listCompany;

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
