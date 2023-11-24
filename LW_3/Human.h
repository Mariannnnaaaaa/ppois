#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
private:
    string name;
    string surname;
public:
    Human(string name, string surname);

    string getName();
    void setName(const string& name);

    string getSurname();
    void setSurname(const string& surname);
};
