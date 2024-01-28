#include "internshipController.h"

internshipController::internshipController(/* args */)
{
}
internshipController::~internshipController()
{
}
std::vector<Internship> internshipController::getData(){
    std::cout << "internshipController" << std::endl;
    std::vector<Internship> internships;

    QFile file("../contact/ressources/Stage.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return internships;
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList liste = line.split(";");
        Internship newInternship(liste[0].toInt(), liste[1].toStdString(), liste[2].toStdString(), liste[3].toStdString());
        internships.push_back(newInternship);
    }

    file.close();
    return internships;
}
void internshipController::setData(std::vector<Internship> list){
    QFile file("../contact/ressources/Stage.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;

    QTextStream out(&file);
    for (int i = 0; i < list.size(); i++){
        out << list[i].getIdInternship() << ";" << list[i].getSubject().c_str() << ";" << list[i].getTimeBegin().c_str() << ";" << list[i].getTimeEnd().c_str() << "\n";
    }

    file.close();
}

std::vector<Internship> internshipController::searchInternshipBySubject(std::string subject = ""){
    std::vector<Internship> listInternship = getData();
    if(subject == "") return listInternship;
    std::vector<Internship> listInternshipSearch = std::vector<Internship>();
    for (int i = 0; i < listInternship.size(); i++){
        if (listInternship[i].getSubject().find(subject) != std::string::npos){
            listInternshipSearch.push_back(listInternship[i]);
        }
    }
    return listInternshipSearch;
}
std::vector<Internship> internshipController::searchInternshipByMds(std::string mds = ""){
    std::vector<Internship> listInternship = getData();
    if(mds == "") return listInternship;
    std::vector<Internship> listInternshipSearch = std::vector<Internship>();
    for (int i = 0; i < listInternship.size(); i++){
        if (listInternship[i].getIdMaster()->get_name().find(mds) != std::string::npos){
            listInternshipSearch.push_back(listInternship[i]);
        }
        if (listInternship[i].getIdMaster()->get_firstname().find(mds) != std::string::npos){
            listInternshipSearch.push_back(listInternship[i]);
        }
        if(listInternship[i].getIdMaster()->get_name().find(mds) != std::string::npos && listInternship[i].getIdMaster()->get_firstname().find(mds) != std::string::npos){
            listInternshipSearch.push_back(listInternship[i]);
        }
    }
    return listInternshipSearch;
}