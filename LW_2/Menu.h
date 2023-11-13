#pragma once
#include <iostream>
#include <vector>

#include "Dish.h"

using namespace std;
class Menu
{
private:
    vector <Dish> dishes;
public:
    vector<Dish> getDishes();
    void setDishes(const vector<Dish>& dishes);
};

