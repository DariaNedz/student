#include "person.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Person::Person()
{
    number = 0;
    name = "";
    age = 0;
}


Person::Person(int pnumber, string pname, int page)
{
    number = pnumber;
    name = pname;
    if (page >= 0 && page <= 150) {
        age = page;
    }
}

int Person::getNumber()
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

void Person::setNumber(int number)
{
        this->number = number;
}
void Person::setName(string name)
{
    this->name = name;
}
void Person::setAge(int age)
{
    if (age >= 0 && age <= 150) {
        this->age = age;
    }
}
