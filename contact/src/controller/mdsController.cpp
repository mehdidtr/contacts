#include "mdsController.h"

mdsController::mdsController(/* args */)
{
}
mdsController::~mdsController()
{
}
std::vector<Mds> mdsController::getData(){
    std::cout << "mdsController" << std::endl;
    std::cout << QDir::currentPath().toStdString()<<std::endl;
    std::vector <Mds> listMds = std::vector<Mds>();
    QFile file ("../contact/ressources/MDS.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return listMds;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (fields.size() >= 7) {
            std::cout << fields[3].toInt() << std::endl;
            Mds mds = Mds(fields[0].toInt(),fields[1].toStdString(),fields[2].toStdString(),fields[4].toStdString(),fields[5].toStdString(),fields[6].toStdString(),fields[3].toInt());
            listMds.push_back(mds);
        }
    }
    file.close();
    return listMds;
}

void mdsController::setData(std::vector<Mds> list){
    QFile file("../contact/ressources/MDS.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;

    QTextStream out(&file);
    for (int i = 0; i < list.size(); i++){
        out << list[i].get_id() << ";" << list[i].get_name().c_str() << ";" << list[i].get_firstname().c_str() << ";" << list[i].get_id_company() << ";" << list[i].get_email().c_str() << ";" << list[i].get_phone().c_str() << ";" << list[i].get_position().c_str() << "\n";
    }
    file.close();
}

std::vector<Mds> mdsController::searchMdsByName(std::string name = ""){
    std::vector<Mds> listMds = getData();
    if(name == "") return listMds;
    std::vector<Mds> listMdsSearch = std::vector<Mds>();
    for (int i = 0; i < listMds.size(); i++){
        if (listMds[i].get_name().find(name) != std::string::npos){
            listMdsSearch.push_back(listMds[i]);
        }
        if (listMds[i].get_firstname().find(name) != std::string::npos){
            listMdsSearch.push_back(listMds[i]);
        }
        if(listMds[i].get_name().find(name) != std::string::npos && listMds[i].get_firstname().find(name) != std::string::npos){
            listMdsSearch.push_back(listMds[i]);
        }
    }
    return listMdsSearch;
}