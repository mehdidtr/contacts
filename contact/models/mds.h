#if !defined(MDS)
#define MDS

#include <iostream>
#include <stdlib.h>
#include <string>
#include "company.h"

class Mds
{
private:
    std::string name;
    std::string phone;
    std::string email;
    std::string position;
    int id;
    Company *company_mds;
public:
    Mds(/* args */);
    ~Mds();
    void set_name(std::string name);
    void set_phone(std::string phone);
    void set_email(std::string email);
    void set_position(std::string position);
    void set_id(int id);
    void set_company(Company *company);
    std::string get_name();
    std::string get_phone();
    std::string get_email();
    std::string get_position();
    int get_id();
    Company* get_company();
};



#endif // MDS
