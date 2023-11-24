#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Human.h"
#include "Course.h"
#include "Lesson.h"
#include "Student.h"

using namespace std;
class Teacher :public Human {
private:
    string position;
    vector<Course> courses;
    vector<Lesson> lessons;
    vector<Student> students;
public:
    Teacher();
    Teacher(string name, string surname, string position);

    string getPosition();
    void setPosition(string newPosition);

    void addLesson(string time, string dayOfWeek, string room, string type);

    void editLesson(int lessonIndex, string time, string dayOfWeek, string room, string type);

    void addComment(int lessonIndex, string comment);

    void checkAttendance(Lesson& lesson);

    void markAsMissed(int lessonIndex);

    void addCourse(Course newCourse);

    void gradeStudent(Student& student, Course& course, int gradeValue, string date);
};
