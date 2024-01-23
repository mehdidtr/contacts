#include "dataController.h"

dataController::dataController(/* args */)
{
}
dataController::~dataController()
{
}
//Permet de parse les données du fichier csv et de les stocker dans un vecteur de la classe MDS avec QT
template<> std::vector<Mds> dataController::getData(){
    std::vector <Mds> listMds = std::vector<Mds>();
    QFile file ("../../ressources/MDS.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return listMds;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        Mds mds = Mds(fields[0].toInt(),fields[1].toStdString(),fields[2].toStdString(),fields[4].toStdString(),fields[5].toStdString(),fields[6].toStdString());
        listMds.push_back(mds);
    }
    file.close();
    return listMds;
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
