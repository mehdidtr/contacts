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
    void setPrenom(std::string prenom);
    void setNom(std::string nom);
    void setMail(std::string mail);
    void setPromotion(std::string promotion);
};

#endif // STUDENT_H
