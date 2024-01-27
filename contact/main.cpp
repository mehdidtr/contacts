#include "mainwindow.h"
#include "src/controller/dataController.h"
#include "src/controller/mdsController.h"
#include "src/controller/studentController.h"
#include "src/controller/internshipController.h"
#include "src/controller/companyController.h"
#include <QApplication>
#include <iostream>
#include <cassert>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}



