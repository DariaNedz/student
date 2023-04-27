#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "person.hpp"
#include "fileDB.hpp"
// #include "fileDB.cpp"

using namespace std;

vector<Person> PeopleVector;

int main()
{
    FileDB fileDB;
    fileDB.LoadPerson(PeopleVector);

    // bool invalidAge;
    string function;
    string choice;

    for (int i = 0; i < 15; i++) {
        FileDB saved;
        Person student{};
        int number;
        string name;
        int age;

        ofstream file("c:\\tmp\\NewStudent.txt");
        cout << "Enter: add    - add student\n";
        cout << "       delete - delete student\n";
        cout << "       edit   - edit student\n";
        cout << "       find   - find student\n";
        cout << "       exit   - save and exit the programme\n";
        cout << "\n! all will be saved to file after enter EXIT !\n";

        cout << "\n- ";
        cin >> function;
        if (function == "add") {
            FileDB added;
            added.AddPerson();
            saved.SavePerson(PeopleVector);
        }

        if (function == "delete") {
            FileDB deleted;
            deleted.DeletePerson(number, PeopleVector);
            cout << "Deleted. Enter EXIT to check.\n";
            saved.SavePerson(PeopleVector);
        }

        if (function == "edit") {
            FileDB edited;
            edited.EditPerson(PeopleVector);
            saved.SavePerson(PeopleVector);
        }

        if (function == "find") {
            cout << "By what you want to find (id/name/age)?\n";
            cout << "By ";
            cin >> choice;
            if (choice == "id") {
                cout << "Enter id : ";
                cin >> number;
                cout << "\n";
                FileDB f1;
                auto ret = f1.FindPersonByNumber(number, PeopleVector);
                cout << ": " << ret.getNumber() << " :" << endl;
                cout << "- " << ret.getName() << " -" << endl;
                cout << "- " << ret.getAge() << " -" << "\n" << endl;
            }
            if (choice == "name") {
                cout << "Enter name : ";
                cin >> name;
                cout << "\n";
                FileDB f1;
                auto ret = f1.FindPersonByName(name, PeopleVector);
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
                auto ret = f1.FindPersonByAge(age, PeopleVector);
                for (auto p : ret) {
                    cout << ": " << p.getNumber() << " :" << endl;
                    cout << "- " << p.getName() << " -" << endl;
                    cout << "- " << p.getAge() << " -" << "\n" << endl;
                }
            }
            saved.SavePerson(PeopleVector);
        }

        if (function == "exit") {
            saved.SavePerson(PeopleVector);
            break;
        }
    }
    return 0;
}
