#include "Menu.h"
using namespace std;

vector<Dish> Menu:: getDishes() { return dishes; }
void Menu::setDishes(const vector<Dish>& dishes) { this->dishes = dishes; }