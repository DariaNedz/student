#include <iostream>
#include "person.hpp"

using namespace std;

class FileDB {
  public:
	Person FindPersonByNumber(int number, vector<Person>& PeopleVector);
	vector<Person> FindPersonByName(string name, vector<Person>& PeopleVector);
	vector<Person> FindPersonByAge(int age, vector<Person>& PeopleVector);

	void LoadPerson(vector<Person>& people);
	void SavePerson(vector<Person>& people);
	Person AddPerson();
	void DeletePerson(int number, vector<Person>& people);
	void EditPerson(vector<Person>& people);
};
