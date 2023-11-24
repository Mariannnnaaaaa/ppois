#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Teacher.h"

using namespace std;
class University {
private:
    vector<Student> students;
    vector<Teacher> teachers;

public:

    void viewStudentRank(Student& student);

    void viewStudentsInfo();

    void viewTeachersInfo();
};
