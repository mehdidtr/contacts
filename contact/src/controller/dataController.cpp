#include "dataController.h"

dataController::dataController(/* args */)
{
}
dataController::~dataController()
{
}

void dataController::connectCompanyMds(std::vector<Company>* listCompany, std::vector<Mds>* listMds){
    for (int i = 0; i < listMds->size(); i++){
        for (int j = 0; j < listCompany->size(); j++){
            if (listMds->at(i).get_id_company() == listCompany->at(j).getId()){
                listMds->at(i).set_company(&listCompany->at(j));
                listCompany->at(j).addMds(&listMds->at(i));
            }
        }
    }
}
void dataController::connectMdstoInternship(std::vector<Mds>* listMds, std::vector<Internship>* listInternship){
    QFile file("../contact/ressources/TableMDSSta.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList liste = line.split(";");
        for (int i = 0; i < listMds->size(); i++){
            if (listMds->at(i).get_id() == liste[0].toInt()){
                for (int j = 0; j < listInternship->size(); j++){
                    if (listInternship->at(j).getIdInternship() == liste[1].toInt()){
                        listMds->at(i).add_internship(*(&listInternship->at(j)));
                        listInternship->at(j).setIdMaster(&listMds->at(i));
                    }
                }
            }
        }
    }
    file.close();
}
void dataController::connectStudentToInternship(std::vector<Student>* listStudent, std::vector<Internship>* listInternship){
    QFile file("../contact/ressources/TableEtuSta.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList liste = line.split(";");
        for (int i = 0; i < listStudent->size(); i++){
            if (listStudent->at(i).getIdStudent() == liste[0].toInt()){
                for (int j = 0; j < listInternship->size(); j++){
                    if (listInternship->at(j).getIdInternship() == liste[1].toInt()){
                        listStudent->at(i).add_internship(*(&listInternship->at(j)));
                        listInternship->at(j).setIdStudents(&listStudent->at(i));
                    }
                }
            }
        }
    }
    file.close();
}
