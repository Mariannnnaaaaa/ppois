#include "Teacher.h"
using namespace std;

Teacher::Teacher() : Human("", ""), position("") {}
Teacher::Teacher(string name, string surname, string position)
    : Human(name, surname), position(position) {}

string Teacher::getPosition() { return position; }
void Teacher::setPosition(string newPosition) { position = newPosition; }

void Teacher::addLesson(string time, string dayOfWeek, string room, string type) {
    Lesson newLesson(time, dayOfWeek, room, type);
    lessons.push_back(newLesson);
}
void Teacher::editLesson(int lessonIndex, string time, string dayOfWeek, string room, string type) {
    if (lessonIndex >= 0 && lessonIndex < lessons.size()) {
        lessons[lessonIndex].setTime(time);
        lessons[lessonIndex].setDayOfWeek(dayOfWeek);
        lessons[lessonIndex].setRoom(room);
        lessons[lessonIndex].setType(type);
    }
}

void Teacher::addComment(int lessonIndex, string comment) {
    if (lessonIndex >= 0 && lessonIndex < lessons.size()) {
        string oldComments = lessons[lessonIndex].getComments();
        lessons[lessonIndex].setComments(oldComments + " " + comment);
    }
}

void Teacher::checkAttendance(Lesson& lesson) {
    for (int i = 0; i < lessons.size(); i++) {
        cout << students[i].getName() << (students[i].isPresentAtLesson(lesson) ? " is present\n" : " is absent\n");
    }
}

void Teacher::markAsMissed(int lessonIndex) {
    if (lessonIndex >= 0 && lessonIndex < lessons.size()) lessons[lessonIndex].setIsMissed(true);
}

void Teacher::addCourse(Course newCourse) {courses.push_back(newCourse);}

void Teacher::gradeStudent(Student& student, Course& course, int gradeValue, string date) {
    Grade grade;
    grade.setGrade(gradeValue);
    grade.setCourse(course);
    grade.setDate(date);
    student.addGrade(grade);
}