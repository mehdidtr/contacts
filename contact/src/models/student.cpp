#include "student.h"
#include "internship.h"
Student::Student(){}

Student::Student(int idStudent, std::string nom, std::string prenom, std::string mail, std::string promotion)
{
    this->idStudent = idStudent;
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->promotion = promotion;
    this->idInternship = new std::vector<Internship>();
}

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

std::vector<Internship>* Student::getIdInternship()
{
    return idInternship;
}
void Student::setIdInternship(std::vector<Internship>* newIdInternship)
{
    idInternship = newIdInternship;
}
void Student::add_internship(Internship internship)
{
    idInternship->push_back(internship);
}
