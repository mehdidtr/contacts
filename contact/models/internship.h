#ifndef INTERNSHIP_H
#define INTERNSHIP_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "student.h"
#include "mds.h"

class Internship
{
    private :
        int idInternship;
        std::string subject;
        std::string timeframe;
        std::string contactsInfo;
        Student* idStudents;
        Mds* idMaster;
    public:
        Internship();

        int getIdInternship() const;
        void setIdInternship(int newIdInternship);
        std::string getSubject() const;
        void setSubject(const std::string &newSubject);
        std::string getTimeframe() const;
        void setTimeframe(const std::string &newTimeframe);
        std::string getContactsInfo() const;
        void setContactsInfo(const std::string &newContactsInfo);
        Student *getIdStudents() const;
        void setIdStudents(Student *newIdStudents);
        Mds *getIdMaster() const;
        void setIdMaster(Mds *newIdMaster);
};

#endif // INTERNSHIP_H
