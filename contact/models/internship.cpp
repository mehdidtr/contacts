#include "internship.h"

internship::internship() {}

std::string Internship::getSubject() const
{
    return subject;
}

void Internship::setSubject(const std::string &newSubject)
{
    subject = newSubject;
}

std::string Internship::getTimeframe() const
{
    return timeframe;
}

void Internship::setTimeframe(const std::string &newTimeframe)
{
    timeframe = newTimeframe;
}

std::string Internship::getContactsInfo() const
{
    return contactsInfo;
}

void Internship::setContactsInfo(const std::string &newContactsInfo)
{
    contactsInfo = newContactsInfo;
}

int Internship::getIdInternship() const
{
    return idInternship;
}

void Internship::setIdInternship(int newIdInternship)
{
    idInternship = newIdInternship;
}
