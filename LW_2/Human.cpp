#include "Human.h"
using namespace std;

Human::Human(string name, int age) : name(name), age(age) {}

string Human::getName() { return name; }
void Human::setName(const string& name) { this->name = name; }

int Human::getAge() { return age; }
void Human::setAge(int age) { this->age = age; }