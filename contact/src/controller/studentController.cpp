#include "studentController.h"

std::vector<Student> studentController::getData(){
    std::cout << "studentController" << std::endl;
    std::vector <Student> listStudent = std::vector<Student>();
    QFile file("../contact/ressources/Etudiant.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return listStudent;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList liste = line.split(";");
        Student student = Student(liste[0].toInt(), liste[1].toStdString(), liste[2].toStdString(), liste[3].toStdString(), liste[4].toStdString());
        listStudent.push_back(student);
    }
    file.close();
    return listStudent;
}

void studentController::setData(std::vector<Student> list){
    QFile file("../contact/ressources/Etudiants.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;

    QTextStream out(&file);
    for (int i = 0; i < list.size(); i++){
        out << list[i].getIdStudent() << ";" << list[i].getNom().c_str() << ";" << list[i].getPrenom().c_str() << ";" << list[i].getMail().c_str() << ";" << list[i].getPromotion().c_str() << "\n";
    }
    file.close();
}

std::vector<Student> studentController::searchStudentByName(std::string name = ""){
    std::vector<Student> listStudent = getData();
    if(name == "") return listStudent;
    std::vector<Student> listStudentSearch = std::vector<Student>();
    for (int i = 0; i < listStudent.size(); i++){
        if (listStudent[i].getNom().find(name) != std::string::npos){
            listStudentSearch.push_back(listStudent[i]);
        }
        if (listStudent[i].getPrenom().find(name) != std::string::npos){
            listStudentSearch.push_back(listStudent[i]);
        }
        if(listStudent[i].getNom().find(name) != std::string::npos && listStudent[i].getPrenom().find(name) != std::string::npos){
            listStudentSearch.push_back(listStudent[i]);
        }
    }
    return listStudentSearch;
}