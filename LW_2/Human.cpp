#include "Human.h"
using namespace std;

Human::Human(string name, int age) : name(name), age(age) {}

string Human::getName() { return name; }
void Human::setName(const string& name) { this->name = name; }

int Human::getAge() { return age; }
void Human::setAge(int age) {
	try
	{
		if (age < 0) throw invalid_argument("Age cannot be negative.");
		this->age = age;
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << '\n';
	}
}


