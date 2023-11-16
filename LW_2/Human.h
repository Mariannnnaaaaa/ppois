#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Human
{
private:
    string name;
    int age;

public:
    Human(string name, int age);

    string getName();
    void setName(const string& name);

    int getAge();
    void setAge(int age);
};