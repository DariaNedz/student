#include <iostream>
#include "person.hpp"

using namespace std;

class FileDB {

	// Person FindPersonByNumber(int number);
	Person FindPersonByNumber (int number, vector<Person>& people);
	vector<Person> FindPersonByName (string name, vector<Person>& people);
	vector<Person> FindPersonByAge (int age, vector<Person>& people);

};
