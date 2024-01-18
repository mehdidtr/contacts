#ifndef INTERNSHIP_H
#define INTERNSHIP_H

#include <stdlib.h>
#include <iostream.h>
#include <string.h>
class Students;
class Mds;
class Internship
{
private :
    int idInternship;
    std::string subject;
    std::string timeframe;
    std::string contactsInfo;
    Mds* idMaster;
    Students* idStudents;
public:
    static int get_Internship( void );
    void set_Internship(int idInternship);
    static std::string get_Subject( void );
    static std::string get_timeframe( void );
    static std::string get_contactsInfo( void );
    void set_subject(std::string subject);
    void set_timeframe(std::string timeframe);
    void set_contactsInfo(std::string contactsInfo);
    Internship();
    int getIdInternship() const;
    void setIdInternship(int newIdInternship);
};

#endif // INTERNSHIP_H
