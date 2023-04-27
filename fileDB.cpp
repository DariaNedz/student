#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "fileDB.hpp"

using namespace std;

Person FileDB::FindPersonByNumber(int number, vector<Person>& PeopleVector)
{
    for (auto& person : PeopleVector) {
        if (person.getNumber() == number)
            return person;
    }
    return Person();
}

vector<Person> FileDB::FindPersonByName(string name, vector<Person>& PeopleVector)
{
    vector<Person> p;
    for (auto& person : PeopleVector) {
        if (person.getName() == name)
            p.push_back(person);
    }
    return p;
}

vector<Person> FileDB::FindPersonByAge (int age, vector<Person>& PeopleVector)
{
    vector<Person> p;
    for (auto& person : PeopleVector) {
        if (person.getAge() == age)
            p.push_back(person);
    }
    return p;
}

void FileDB::LoadPerson(vector<Person>& people)
{
    ifstream file("c:\\tmp\\NewStudent.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string number_str, name, age_str;
            getline(ss, number_str, ';');
            getline(ss, name, ';');
            getline(ss, age_str, ';');
            int number = stoi(number_str);
            int age = stoi(age_str);
            people.push_back(Person(number, name, age));
        }
        file.close();
    }
}

void FileDB::SavePerson(vector<Person>& PeopleVector)
{
    ofstream file("c:\\tmp\\Student.txt");
    if (file.is_open()) {
        for (auto& person : PeopleVector) {
            file << ": " << person.getNumber() << " :" << endl;
            file << "- " << person.getName() << " -" << endl;
            file << "- " << person.getAge() << " -" << "\n" << endl;
        }
        file.close();
    }
}

Person FileDB::AddPerson()
{
    int number, age;
    string name;

    Person student{};
    cout << "\n: enter number : ";
    cin >> number;
    student.setNumber(number);

    cout << ": enter name : ";
    cin >> name;
    student.setName(name);

    cout << ": enter age : ";
    cin >> age;
    cout << "\n";

    return student;
}

void FileDB::DeletePerson(int number, vector<Person>& people)
{
    vector<Person> p;
    vector<Person>::iterator it;
    cout << "Enter student's ID to delete : ";
    cin >> number;
    for (it = p.begin(); it != p.end(); it++) {
        if (it -> getNumber() == number) {
            p.erase(it);
            SavePerson(people);
            cout << "Student is deleted.\n";
        }
    }
    cout << "Student not found.\n";
}

void FileDB::EditPerson(vector<Person>& people)
{
    int number;
    cout << "Enter student ID to edit : ";
    cin >> number;
    for (auto& person : people) {
        if (person.getNumber() == number) {
            string name;
            int age;
            cout << "Enter new name : ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new age : ";
            cin >> age;
            person.setName(name);
            person.setAge(age);
            SavePerson(people);
            cout << "List has been updated.\n";
        }
    }
    cout << "Student not found.\n";
    // return ;
}
