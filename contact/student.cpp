#include "student.h"

student::student(){}

int student::getIdStudent() const
{
    return idStudent;
}

void student::setIdStudent(int newIdStudent)
{
    idStudent = newIdStudent;
}

std::string student::getPrenom()
{
    return prenom;
}

void student::setPrenom(std::string newPrenom)
{
    prenom = newPrenom;
}

std::string student::getNom()
{
    return nom;
}

void student::setNom(std::string newNom)
{
    nom = newNom;
}

std::string student::getMail()
{
    return mail;
}

void student::setMail(std::string newMail)
{
    mail = newMail;
}

std::string student::getPromotion()
{
    return promotion;
}

void student::setPromotion(std::string newPromotion)
{
    promotion = newPromotion;
}
