#pragma once
#include <iostream>
#include <string>

using namespace std;

class Restaurant
{
private:
    string name;
public:
    string getName();
    void setName(const string& name);
};

