#if !defined(DATACONTROLLER)
#define DATACONTROLLER

#include <iostream>
#include <string>
#include <vector>
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
};


#endif // DATACONTROLLER
