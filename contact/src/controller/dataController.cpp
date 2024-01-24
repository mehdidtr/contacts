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
    QFile file ("ressources/MDS.csv");
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
    QFile file("ressources/Entreprise.csv");
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

template<> std::vector<Student> dataController::getData(){
    std::vector <Student> listStudent = std::vector<Student>();
    QFile file("ressources/Etudiants.csv");
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

//Permet d'ajouter les données dans le fichier csv avec QT
template<> void dataController::setData(std::vector<Mds> list){
    QFile file("ressources/MDS.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;

    QTextStream out(&file);
    for (int i = 0; i < list.size(); i++){
        out << list[i].get_id() << ";" << list[i].get_name().c_str() << ";" << list[i].get_firstname().c_str() << ";" << list[i].get_email().c_str() << ";" << list[i].get_phone().c_str() << ";" << list[i].get_position().c_str() << "\n";
    }
    file.close();
}

template<> void dataController::setData(std::vector<Company> list){
    QFile file("ressources/Entreprise.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;

    QTextStream out(&file);
    for (int i = 0; i < list.size(); i++){
        out << list[i].getId() << ";" << list[i].getNom().c_str() << ";" << list[i].getDomaine().c_str() << "\n";
    }
    file.close();
}

template<> void dataController::setData(std::vector<Student> list){
    QFile file("ressources/Etudiants.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;

    QTextStream out(&file);
    for (int i = 0; i < list.size(); i++){
        out << list[i].getIdStudent() << ";" << list[i].getNom().c_str() << ";" << list[i].getPrenom().c_str() << ";" << list[i].getMail().c_str() << ";" << list[i].getPromotion().c_str() << "\n";
    }
    file.close();
}
