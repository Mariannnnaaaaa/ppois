#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Course.h"

using namespace std;
class Grade {
private:
    int grade;
    string date;
    Course course;

public:
    int getGrade();
    string getDate();
    Course getCourse();

    void setGrade(int newGrade);
    void setDate(string newDate);
    void setCourse(Course newCourse);
};

