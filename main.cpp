#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "person.hpp"

using namespace std;

int main()
{
    vector<Person> people;
    bool invalidAge;
    for (int i = 0; i < 15; i++) {
        Person student{};
        string number;
        string name;
        int age;

        cout << "--- enter number or END ---\n";
        cin >> number;
        if (number == "END") {
            break;
        }
        student.setNumber(number);

        cout << "------- enter NAME --------\n";
        cin >> name;
        student.setName(name);

        do {
            invalidAge = false;
            cout << "------- enter AGE ---------\n";
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
    } //for
    for (auto person : people) {
        person.print();
    }
    return 0;
}