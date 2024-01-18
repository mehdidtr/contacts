#include "mds.h"

Mds::Mds(/* args */)
{
}

Mds::~Mds()
{
}

std::string Mds::get_email()
{
    return email;
}
int Mds::get_id()
{
    return id;
}
company* Mds::get_company()
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
void Mds::set_company(company *company)
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
