#if !defined(STUDENTCONTROLLER)
#define STUDENTCONTROLLER
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
#include "../models/student.h"
class studentController
{
private:
    /* data */
public:
    studentController(/* args */);
    ~studentController();
    static std::vector<Student> getData();
    static void setData(std::vector<Student> list);
    static std::vector<Student> searchStudentByName(std::string name);
};


#endif // STUDENTCONTROLLER
