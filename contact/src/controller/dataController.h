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
        public:
            dataController();
            ~dataController();
            std::string static DateTime(std::chrono::system_clock::time_point& timePoint);
            std::chrono::system_clock::time_point static GFG(std::string& datetimeString);
            template <typename T> static std::vector<T> getData( );
            template <typename T> static void setData(std::vector<T> list);
    };

#endif // DATACONTROLLER
