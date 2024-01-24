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
    // listMds2.push_back(Mds(1,"test","test","test","test","test","test"));
    // listMds2.push_back(Mds(2,"test","test","test","test","test","test"));
    // data->setData<Mds>(listMds2);
    // Test Connexion Mds/Company
    // std::vector<Company> listCompany = data->getData<Company>();
    // data->connectCompanyMds(&listCompany, &listMds);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
