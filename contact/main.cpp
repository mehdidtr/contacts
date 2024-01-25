#include "mainwindow.h"
#include "src/controller/dataController.h"
#include <QApplication>
#include <iostream>
#include <cassert>

void testDataController()
{
    dataController* data = new dataController();

    // Test getData
    std::vector<Mds> listMds = data->getData<Mds>();
    assert(listMds.size() > 0 && "getData<Mds> test failed: listMds is empty");
    std::cout << "getData<Mds> test passed" << std::endl;

    std::vector<Internship> listInternship = data->getData<Internship>();
    assert(listInternship.size() > 0 && "getData<Internship> test failed: listInternship is empty");
    std::cout << "getData<Internship> test passed" << std::endl;

    std::vector<Company> listCompany = data->getData<Company>();
    assert(listCompany.size() > 0 && "getData<Company> test failed: listCompany is empty");
    std::cout << "getData<Company> test passed" << std::endl;

    // Test setData
    std::vector<Mds> listMds2;
    listMds2.push_back(Mds(1, "test", "test", "test", "test", "test", 1));
    listMds2.push_back(Mds(2, "test", "test", "test", "test", "test", 1));
    data->setData<Mds>(listMds2);
    std::vector<Mds> updatedListMds = data->getData<Mds>();
    assert(updatedListMds.size() == listMds2.size() && "setData<Mds> test failed: updatedListMds size does not match listMds2 size");
    std::cout << "setData<Mds> test passed" << std::endl;

    // Test connectCompanyMds
    data->connectCompanyMds(&listCompany, &listMds);
    assert(listCompany[0].getMdsList().size() > 0 && "connectCompanyMds test failed: listCompany[0].getMdsList() is empty");
    std::cout << "connectCompanyMds test passed" << std::endl;
}
int main(int argc, char *argv[])
{
    // Test des fonction du dataController
    // dataController *data = new dataController();
    // std::vector<Mds> listMds = data->getData<Mds>();
    // std::cout << listMds[0].get_name() << std::endl;
    // std::vector<Mds> listMds2 = std::vector<Mds>();
    // listMds2.push_back(Mds(1,"test","test","test","test","test", 1));
    // listMds2.push_back(Mds(2, "test", "test", "test", "test", "test", 1));
    // data->setData<Mds>(listMds2);
    // Test des fonction du dataController avec les stages
    // std::vector<Internship> listInternship = data->getData<Internship>();
    // std::cout << listInternship[0].getIdInternship() << std::endl;
    // listInternship.push_back(Internship(3,"Uber", "17-07-2023","26-07-2023"));
    // data->setData<Internship>(listInternship);
    // Test Connexion Mds/Company
    // std::vector<Company> listCompany = data->getData<Company>();
    // data->connectCompanyMds(&listCompany, &listMds);
    //testDataController();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
