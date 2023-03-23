#include "fileDB.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

Person FileDB::FindPersonByNumber (int number, vector<Person>& people)
{
    for (auto& person : people) {
        if (person.getNumber() == number)
            return person;
    }
    return Person();
}

vector<Person> FileDB::FindPersonByName (string name, vector<Person>& people)
{
    vector<Person> p;
    for (auto& person : people) {
        if (person.getName() == name)
            p.push_back(person);
    }
    return p;
}

vector<Person> FileDB::FindPersonByAge (int age, vector<Person>& people)
{
    vector<Person> p;
    for (auto& person : people) {
        if (person.getAge() == age)
            p.push_back(person);
    }
    return p;
}

vector <Person> FileDB::DeletePerson(string name, int age, vector<Person>& people)
{
    vector<Person> p;
    vector<Person>::iterator it;
    p.erase(it);
    for (auto& person : people) {
        if (person.getName() == name && person.getAge() == age)
            p.erase(it);
    }
    return p;
}
