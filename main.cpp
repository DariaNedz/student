#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "person.hpp"
#include "fileDB.hpp"

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
        string choice;

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
            cout << "Enter name : ";
            cin >> name;
            cout << "Enter age : ";
            cin >> age;
            FileDB f2;
            auto ret = f2.DeletePerson(name, age, people);
            cout << "Deleted. Enter EXIT to check.\n";
        }

        if (function == "edit") {
            cout << " - \n";
        }

        if (function == "search") {
            cout << "By what you want to find (number/name/age)?\n";
            cout << "By ";
            cin >> choice;
            if (choice == "number") {
                cout << "Enter number : ";
                cin >> number;
                cout << "\n";
                FileDB f1;
                auto ret = f1.FindPersonByNumber(number, people);
                cout << ": " << ret.getNumber() << " :" << endl;
                cout << "- " << ret.getName() << " -" << endl;
                cout << "- " << ret.getAge() << " -" << "\n" << endl;
            }
            if (choice == "name") {
                cout << "Enter name : ";
                cin >> name;
                cout << "\n";
                FileDB f1;
                auto ret = f1.FindPersonByName(name, people);
                for (auto p : ret) {
                    cout << ": " << p.getNumber() << " :" << endl;
                    cout << "- " << p.getName() << " -" << endl;
                    cout << "- " << p.getAge() << " -" << "\n" << endl;
                }
            }

            if (choice == "age") {
                cout << "Enter age : ";
                cin >> age;
                cout << "\n";
                FileDB f1;
                auto ret = f1.FindPersonByAge(age, people);
                for (auto p : ret) {
                    cout << ": " << p.getNumber() << " :" << endl;
                    cout << "- " << p.getName() << " -" << endl;
                    cout << "- " << p.getAge() << " -" << "\n" << endl;
                }
            }
            }

            if (function == "exit") {
                for (auto person : people) {
                    file << "\n: " << person.getNumber() << " :" << endl;
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
