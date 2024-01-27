#if !defined(MDSCONTROLLER)
#define MDSCONTROLLER
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
#include "../models/mds.h"
class mdsController
{
private:
    /* data */
public:
    mdsController(/* args */);
    ~mdsController();
    static std::vector<Mds> getData();
    static void setData(std::vector<Mds> list);
    static std::vector<Mds> searchMdsByName(std::string name);
};



#endif // MDSCONTROLLER
