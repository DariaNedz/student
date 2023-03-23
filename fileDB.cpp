#include "fileDB.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

Person FileDB::FindPersonByNumber(int number, vector<Person>& people)
{
    // Load Data => vector

    for (auto& person : people) {
        if (person.getNumber() == number)
            return person;
    }
    return Person();
}

vector<Person> FileDB::FindPersonByName(string name, vector<Person>& people)
{
    // Load Data => vector

    for (auto& person : people) {
        if (person.getName() == name)
            return people;
    }
    return vector<Person>();
}

vector<Person> FileDB::FindPersonByAge(int age, vector<Person>& people)
{
    // Load Data => vector

    for (auto& person : people) {
        if (person.getAge() == age)
            return people;
    }
    return vector<Person>();
}
