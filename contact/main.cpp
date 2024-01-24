#include "mainwindow.h"
#include "src/controller/dataController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Test des fonction du dataController
    // dataController *data = new dataController();
    // std::vector<Mds> listMds = data->getData<Mds>();
    // std::cout << listMds[0].get_name() << std::endl;
    // std::vector<Mds> listMds2 = std::vector<Mds>();
    // listMds2.push_back(Mds(1,"test","test","test","test","test"));
    // listMds2.push_back(Mds(2,"test","test","test","test","test"));
    // data->setData<Mds>(listMds2);
    // Test des fonction du dataController avec les stages
    // std::vector<Internship> listInternship = data->getData<Internship>();
    // std::cout << listInternship[0].getIdInternship() << std::endl;
    // listInternship.push_back(Internship(3,"Uber", "17-07-2023","26-07-2023"));
    // data->setData<Internship>(listInternship);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
