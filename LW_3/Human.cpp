#include "Human.h"
using namespace std;

Human::Human(string name, string surname) : name(name), surname(surname) {}

string Human::getName() { return name; }
void Human::setName(const string& name) { this->name = name; }

string Human::getSurname() { return surname; }
void Human::setSurname(const string& surname) { this->surname = surname; }