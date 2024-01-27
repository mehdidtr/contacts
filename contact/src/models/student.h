#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <stdlib.h>
#include <vector>

class Internship;

class Student
{
private:
    int idStudent;
    std::string prenom;
    std::string nom;
    std::string mail;
    std::string promotion;
    std::vector<Internship>* idInternship;


public:
    Student();
    Student(int idStudent, std::string nom, std::string prenom, std::string mail, std::string promotion);

    //GETTER
    int getIdStudent() const;
    std::string getPrenom( void );
    std::string getNom( void );
    std::string getMail( void );
    std::string getPromotion( void );
    std::vector<Internship>* getIdInternship( void );

    //SETTER
    void setIdStudent(int newIdStudent);
    void setPrenom(const std::string newPrenom);
    void setNom(std::string newNom);
    void setMail(std::string newMail);
    void setPromotion(std::string newPromotion);
    void setIdInternship(std::vector<Internship>* newIdInternship);
    void add_internship(Internship internship);
};

#endif // STUDENT_H
