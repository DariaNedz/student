#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person();
    Person(int pnumber, string pname, int page);

    int getNumber();
    void setNumber(int number);

    string getName();
    void setName(string name);

    int getAge();
    void setAge(int age);

    void SearchByNumber();
    void SearchByName();
    void SearchByAge();

private:
    int number;
    string name;
    int age; // 0 - unknown.
};

#endif
