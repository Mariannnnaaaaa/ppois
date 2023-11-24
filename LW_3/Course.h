#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
private:
    string courseName;
    string description;

public:
    string getCourseName();
    string getDescription();

    void setCourseName(string newCourseName);
    void setDescription(string newDescription);

};

