#include "dataController.h"

dataController::dataController(/* args */)
{
}

dataController::~dataController()
{
}

template<> std::vector<Mds> dataController::getData(){
}

template<> std::vector<Student> dataController::getData()
{
    QFile file ("../../ressources/Etudiant.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return 1;
    }
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList liste = line.split(";");
        std::cout << liste[0].toStdString() << " " << liste[1].toStdString() << " " << liste[2].toStdString() << " " << liste[3].toStdString() << std::endl;
    }

    file.close();
    return 0;
}
