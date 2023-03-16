#include "person.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

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
    if (page >= 0 && page < 100) {
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
    if (age >= 0 && age < 100) {
        this->age = age;
    }
}
void Search() {
    /*
    vector <Person> ::iterator it = find(people.begin(), people.end(), 1);
    if (it != people.end())
        cout << "- element found -" << endl;
    else
        cout << "- element NOT found -" << endl;
    */
}
