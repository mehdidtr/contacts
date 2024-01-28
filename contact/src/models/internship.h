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
    std::string timeBegin;
    std::string timeEnd;
    Student* idStudents;
    Mds* idMaster;

public:
    Internship(int idInternship, std::string subject, std::string timeBegin, std::string timeEnd);
    int getIdInternship() const;
    void setIdInternship(int newIdInternship);
    std::string getSubject() const;
    void setSubject(const std::string &newSubject);

    Student *getIdStudents() const;
    void setIdStudents(Student *newIdStudents);
    Mds *getIdMaster() const;
    void setIdMaster(Mds *newIdMaster);
    std::string getTimeBegin() const;
    void setTimeBegin(const std::string &newTimeBegin);
    std::string getTimeEnd() const;
    void setTimeEnd(const std::string &newTimeEnd);
};

#endif // INTERNSHIP_H
