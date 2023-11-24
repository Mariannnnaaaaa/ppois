#include "University.h"
using namespace std;

void University:: viewStudentRank(Student& student) {
    double studentAverage = student.calculateAverageGrade();
    int rank = 1;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].calculateAverageGrade() > studentAverage) {
            rank++;
        }
    }
    cout << "Student rating by average score: " << rank << "\n";
}

void University::viewStudentsInfo() {
    for (int i = 0; i < students.size(); i++) {
        cout << "Student name: " << students[i].getName() << "\n";
        cout << "Student surname: " << students[i].getSurname() << "\n";
        cout << "Student speciality: " << students[i].getSpeciality() << "\n";
        cout << "Student averrage grade: " << students[i].calculateAverageGrade() << "\n";
        cout << "Student skills: ";
        for (int j = 0; j < students[i].getSkills().size(); j++) {
            cout << students[i].getSkills()[j] << ", ";
        }
        cout << "\n";

        cout << "Student links: ";
        for (int j = 0; j < students[i].getLinks().size(); j++) {
            cout << students[i].getLinks()[j] << ", ";
        }
        cout << "\n";
    }
}

void University::viewTeachersInfo() {
    for (int i = 0; i < teachers.size(); i++) {
        cout << "Teacher name: " << teachers[i].getName() << "\n";
        cout << "Teacher surname: " << teachers[i].getSurname() << "\n";
        cout << "Teacher position: " << teachers[i].getPosition() << "\n";
    }
}