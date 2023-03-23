#include <iostream>
#include "person.hpp"

using namespace std;

class FileDB {
public:
	Person FindPersonByNumber (int number, vector<Person>& people);
	vector<Person> FindPersonByName (string name, vector<Person>& people);
	vector<Person> FindPersonByAge (int age, vector<Person>& people);

	void DeletePerson (string name, int age, vector<Person>& people);
};
