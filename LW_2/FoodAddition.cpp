#include "FoodAddition.h"
using namespace std;

string FoodAddition::getName() { return name; }
void FoodAddition::setName(const string& name) { this->name = name; }

void FoodAddition::printFoodAdditionDetails() { cout << "Food Addition Name: " << name << "\n"; }