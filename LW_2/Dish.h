#pragma once
#include <iostream>
#include <string>

using namespace std;
class Dish
{
private:
    string name;
    double price;
public:
    Dish(string name, double price);
    string getName();
    void setName(const string& name);

    double getPrice();
    void setPrice(double price);

    bool operator==(const Dish& other);

    void printDishDetails();
};

