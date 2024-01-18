#include "student.h"

Student::Student(){}

int Student::getIdStudent() const
{
    return idStudent;
}

void Student::setIdStudent(int newIdStudent)
{
    idStudent = newIdStudent;
}

std::string Student::getPrenom()
{
    return prenom;
}

void Student::setPrenom(std::string newPrenom)
{
    prenom = newPrenom;
}

std::string Student::getNom()
{
    return nom;
}

void Student::setNom(std::string newNom)
{
    nom = newNom;
}

std::string Student::getMail()
{
    return mail;
}

void Student::setMail(std::string newMail)
{
    mail = newMail;
}

std::string Student::getPromotion()
{
    return promotion;
}

void Student::setPromotion(std::string newPromotion)
{
    promotion = newPromotion;
}
