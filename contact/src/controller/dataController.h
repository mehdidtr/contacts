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
        std::string DateTime(const chrono::system_clock::time_point& timePoint);
        std::chrono::system_clock::time_point GFG(const std::string& datetimeString);
        template <typename T> static std::vector<T> getData( );
        template <typename T> static void setData(std::vector<T> list);
    };


#endif // DATACONTROLLER
