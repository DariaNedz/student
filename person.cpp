#include "person.hpp"
#include <iostream>

using namespace std;

Person::Person()
{
    number = "";
    name = "";
    age = 0;
}
Person::Person(string pnumber, string pname, int page)
{
    number = pnumber;
    name = pname;
    if (page >= 0 && page < 100) {
        age = page;
    }
}
string Person::getNumber()
{
    return number;
}
string Person::getName()
{
    return name;
}
int Person::getAge()
{
    return age;
}
void Person::print()
{
    cout << "\n- " << number << " -" << endl;
    cout << "- Name : " << name << "." << endl;
    cout << "- Age : " << age << "." << endl;
}
void Person::setNumber(string number)
{
    this->number = number;
}
void Person::setName(string name)
{
    this->name = name;
}
void Person::setAge(int age)
{
    if (age >= 0 && age < 100) {
        this->age = age;
    }
}