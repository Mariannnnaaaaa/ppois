#pragma once
#include <iostream>
#include <string>

using namespace std;

class CuisineType
{
private:
    string name;
public:
    string getName();
    void setName(const string& name);
};

