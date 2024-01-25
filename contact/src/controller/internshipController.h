#if !defined(INTERNSHIPCONTROLLER)
#define INTERNSHIPCONTROLLER
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
#include "../models/internship.h"
class internshipController
{
private:
    /* data */
public:
    internshipController(/* args */);
    ~internshipController();
    static std::vector<Internship> getData();
    static void setData(std::vector<Internship> list);
};


#endif // INTERNSHIPCONTROLLER
