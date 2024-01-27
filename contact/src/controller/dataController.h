#if !defined(DATACONTROLLER)
#define DATACONTROLLER

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
#include "../models/student.h"
#include "../models/mds.h"
#include "../models/internship.h"


class dataController
{
private:
    /* data */
public:
    dataController(/* args */);
    ~dataController();
    template <typename T> static std::vector<T> getData( );
    template <typename T> static void setData(std::vector<T> list);
    void connectCompanyMds(std::vector<Company>* listCompany, std::vector<Mds>* listMds);
    void connectMdstoInternship(std::vector<Mds>* listMds, std::vector<Internship>* listInternship);
    void connectStudentToInternship(std::vector<Student>* listStudent, std::vector<Internship>* listInternship);
};

#endif // DATACONTROLLER
