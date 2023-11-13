#include "Dish.h"
using namespace std;

Dish::Dish(string name, double price) : name(""), price(0) {}
string Dish::getName() { return name; }
void Dish::setName(const string& name) { this->name = name; }

double Dish::getPrice() { return price; }
void Dish::setPrice(double price) { this->price = price; }

bool Dish::operator==(const Dish& other) { return name == other.name && price == other.price; }

void Dish::printDishDetails() {
    cout << "Dish Name: " << name << "\n";
    cout << "Price: " << price << "\n";
}