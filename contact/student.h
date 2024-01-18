#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <stdlib.h>
class internship;

class student
{
private:
    int idStudent;
    std::string prenom;
    std::string nom;
    std::string mail;
    std::string promotion;
    internship* idInternship;

public:
    student();
    int getIdStudent() const;
    void setIdStudent(int newIdStudent);

    std::string getPrenom( void );
    std::string getNom( void );
    std::string getMail( void );
    std::string getPromotion( void );
    void setPrenom(const std::string newPrenom);
    void setNom(std::string newNom);
    void setMail(std::string newMail);
    void setPromotion(std::string newPromotion);
};

#endif // STUDENT_H
