#include "Grade.h"
using namespace std;

int Grade::getGrade() { return grade; }
string Grade::getDate() { return date; }
Course Grade::getCourse() { return course; }

void Grade::setGrade(int newGrade) { grade = newGrade; }
void Grade::setDate(string newDate) { date = newDate; }
void Grade::setCourse(Course newCourse) { course = newCourse; }