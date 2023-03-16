#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person();
    Person(string pnumber, string pname, int page);

    string getNumber();
    void setNumber(string number);

    string getName();
    void setName(string name);

    int getAge();
    void setAge(int age);

    void print();

private:
    string number;
    string name;
    int age; // 0 - unknown.
};
#endif