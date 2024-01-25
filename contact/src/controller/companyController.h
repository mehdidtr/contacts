#if !defined(COMPANYCONTROLLER)
#define COMPANYCONTROLLER
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include "../models/company.h"
class companyController
{
private:
    /* data */
public:
    companyController(/* args */);
    ~companyController();
    static std::vector<Company> getData();
    static void setData(std::vector<Company> list);
};



#endif // COMPANYCONTROLLER
