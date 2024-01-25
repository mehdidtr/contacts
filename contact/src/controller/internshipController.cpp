#include "internshipController.h"

internshipController::internshipController(/* args */)
{
}
internshipController::~internshipController()
{
}
std::vector<Internship> internshipController::getData(){
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