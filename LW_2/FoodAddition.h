#pragma once
#include <iostream>
#include <string>
using namespace std;
class FoodAddition
{
private:
    string name;
public:
    string getName();
    void setName(const string& name);

    void printFoodAdditionDetails();
};

