#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "person.hpp"

using namespace std;

int main()
{
    ofstream file("c:\\tmp\\Student.txt");
    vector<Person> people;
    bool invalidAge;
    for (int i = 0; i < 15; i++) {
        Person student{};
        int number;
        string name;
        int age;
        string function;

        cout << "----- enter function -----\n";
        cout << "-----      add       -----" << endl;
        cout << "-----     delete     -----" << endl;
        cout << "-----      edit      -----" << endl;
        cout << "-----     search     -----" << endl;
        cout << "-----      exit      -----" << endl;
        cout << "--------------------------\n";

        cin >> function;
        if (function == "add") {
            cout << "------ enter number ------\n";
            cin >> number;
            student.setNumber(number);

            cout << "------- enter name -------\n";
            cin >> name;
            student.setName(name);

            do {
                invalidAge = false;
                cout << "------- enter age --------\n";
                cin >> age;
                try {
                    student.setAge(age);
                }
                catch (invalid_argument invalidArg) {
                    cerr << "\nError: " << invalidArg.what() << endl;
                    invalidAge = true;
                }
            } //do
            while (invalidAge);
            people.push_back(student);
        }

        if (function == "delete") {
            cout << " - ";
        }

        if (function == "edit") {
            cout << " - ";
        }

        if (function == "search") {
            cout << " - ";
        }

        if (function == "exit") {
            for (auto person : people) {
                file << "- " << person.getNumber() << " -" << endl;
                file << ": " << person.getName() << " :" << endl;
                file << ": " << person.getAge() << " :" << "\n" << endl;
            }
            file.close();
            break;
        }
    }
    file.close();
    return 0;
}
