#include "internship.h"

std::string Internship::getTimeBegin() const
{
    return timeBegin;
}

void Internship::setTimeBegin(const std::string &newTimeBegin)
{
    timeBegin = newTimeBegin;
}

std::string Internship::getTimeEnd() const
{
    return timeEnd;
}

void Internship::setTimeEnd(const std::string &newTimeEnd)
{
    timeEnd = newTimeEnd;
}

Internship::Internship(int idInternship, std::string subject, std::string timeBegin , std::string timeEnd) {
    this->idInternship = idInternship;
    this->subject = subject;
    this->timeBegin = timeBegin;
    this->timeEnd = timeEnd;
}

std::string Internship::getSubject() const
{
    return subject;
}

void Internship::setSubject(const std::string &newSubject)
{
    subject = newSubject;
}

Student *Internship::getIdStudents() const
{
    return idStudents;
}

void Internship::setIdStudents(Student *newIdStudents)
{
    idStudents = newIdStudents;
}

Mds *Internship::getIdMaster() const
{
    return idMaster;
}

void Internship::setIdMaster(Mds *newIdMaster)
{
    idMaster = newIdMaster;
}

int Internship::getIdInternship() const
{
    return idInternship;
}

void Internship::setIdInternship(int newIdInternship)
{
    idInternship = newIdInternship;
}
