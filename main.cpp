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

        cout << "Enter: add    - add student\n";
        cout << "       delete - delete student\n";
        cout << "       edit   - edit student\n";
        cout << "       search - search for a student\n";
        cout << "       exit   - exit the programme\n";
        cout << "\n! all will be saved to file after enter EXIT !\n";

        cout << "\n- ";
        cin >> function;
        if (function == "add") {
            cout << "\n: enter number : ";
            cin >> number;
            student.setNumber(number);

            cout << ": enter name : ";
            cin >> name;
            student.setName(name);

            do {
                invalidAge = false;
                cout << ": enter age : ";
                cin >> age;
                cout << "\n";
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
            cout << "By what you want to find?\n";
            cout << "By ";
        }

        if (function == "exit") {
            for (auto person : people) {
                file << ": " << person.getNumber() << " :" << endl;
                file << "- " << person.getName() << " -" << endl;
                file << "- " << person.getAge() << " -" << "\n" << endl;
            }
            file.close();
            break;
        }
    }
    file.close();
    return 0;
}
