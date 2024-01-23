#include "mds.h"

Mds::Mds(int id, std::string name, std::string firstname, std::string email, std::string phone, std::string position)
{
    this->id = id;
    this->name = name;
    this->firstname = firstname;
    this->email = email;
    this->phone = phone;
    this->position = position;
}


Mds::~Mds()
{
}
std::string Mds::get_firstname()
{
    return firstname;
}
void Mds::set_firstname(std::string firstname)
{
    this->firstname = firstname;
}
std::string Mds::get_email()
{
    return email;
}
int Mds::get_id()
{
    return id;
}
Company* Mds::get_company()
{
    return company_mds;
}
std::string Mds::get_name()
{
    return name;
}
std::string Mds::get_phone()
{
    return phone;
}
std::string Mds::get_position()
{
    return position;
}
void Mds::set_email(std::string email)
{
    this->email = email;
}
void Mds::set_id(int id)
{
    this->id = id;
}
void Mds::set_company(Company *company)
{
    this->company_mds = company;
}
void Mds::set_name(std::string name)
{
    this->name = name;
}

void Mds::set_phone(std::string phone)
{
    this->phone = phone;
}
void Mds::set_position(std::string position)
{
    this->position = position;
}
