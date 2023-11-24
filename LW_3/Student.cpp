#include "Student.h"
using namespace std;

Student::Student() : Human("", ""), speciality("") {}
Student::Student(string name, string surname, string speciality)
    : Human(name, surname), speciality(speciality) {}

int Student::getStudentID() { return studentID; }
string Student::getCourse() { return course; }
string Student::getSpeciality() { return speciality; }
vector<string> Student::getSkills() { return skills; }
vector<string> Student::getLinks() { return links; }
vector<string> Student::getDocuments() { return documents; }
bool Student::getIsPresent() { return isPresent; }

void Student::setStudentID(int newStudentID) { studentID = newStudentID; }
void Student::setCourse(string newCourse) { course = newCourse; }
void Student::setSpeciality(string newSpeciality) { speciality = newSpeciality; }
void Student::setSkills(vector<string> newSkills) { skills = newSkills; }
void Student::setLinks(vector<string> newLinks) { links = newLinks; }
void Student::setDocuments(vector<string> newDocuments) { documents = newDocuments; }
void Student::setIsPresent(bool present) { isPresent - present; }

void Student::logIn(string enteredLogin, string enteredPassword) {
    if (login == enteredLogin && password == enteredPassword) loggedIn = true;
    else cout << "ERROR. CHECK YOUR LOGIN AND PASSWORD AND TRY AGAIN\n";
}

void Student::addInformation(string info) {information += info;}

void Student::addSkill(string skill) {skills.push_back(skill);}

void Student::addLink(string link) {links.push_back(link);}

void Student::viewGrades() {
    cout << "Student`s grades:\n";
    for (int i = 0; i < grades.size(); i++) {
        cout << "Grade: " << grades[i].getGrade() << "\n";
        cout << "Date: " << grades[i].getDate() << "\n";
        cout << "Course: " << grades[i].getCourse().getCourseName() << "\n";
        cout << "------------------\n";
    }
}

void Student::orderCertificate(string documentType, string startDate, string endDate, string notes) {
    cout << "Order a certificate...\n";
    Certificate newCertificate(documentType, startDate, endDate, notes);
    certificates.push_back(newCertificate);
    cout << "A certificate ordered.\n";
}

//заказать ведомость
void Student::orderStatement() {
    cout << "Order a statement...\n";
    documents.push_back("Statement");
    cout << "Statement ordered.\n";
}

void Student::viewCertificateHistory() {
    cout << "History of certificates: \n";
    for (int i = 0; i < certificates.size(); i++) {
        cout << "Document type: " << certificates[i].getDocumentType() << "\n";
        cout << "Start date: " << certificates[i].getStartDate() << "\n";
        cout << "End date: " << certificates[i].getEndDate() << "\n";
        cout << "Notes: " << certificates[i].getNotes() << "\n";
        cout << "------------------\n";
    }
}
void Student::viewSchedule() {
    for (int i = 0; i < lessons.size(); i++) {
        cout << lessons[i].getDayOfWeek() << ", " << lessons[i].getTime() << ": " << lessons[i].getType() << " in " << lessons[i].getRoom() << "\n";
        if (!lessons[i].getComments().empty()) {
            cout << "Comments: " << lessons[i].getComments() << "\n";
        }
        if (lessons[i].getIsMissed()) {
            cout << "Missed\n";
        }
        cout << "------------------\n";
    }
}

double Student::calculateAverageGrade() {
    if (grades.empty()) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i].getGrade();
    }

    return sum / grades.size();
}


void Student::applyForSickLeave() {
    cout << "Applying for sick leave...\n";
    isOnSickLeave = true;
    cout << "The application for sick leave has been submitted.\n";
}

void Student::viewMissedClasses() {
    cout << "Missed classes: " << endl;
    for (int i = 0; i < lessons.size(); i++) {
        if (lessons[i].getIsMissed()) {
            cout << lessons[i].getDayOfWeek() << ", " << lessons[i].getTime() << ": " << lessons[i].getType() << " in " << lessons[i].getRoom() << "\n";
        }
    }
}

void Student::orderBook(string title, string author, string releaseDate, int pageCount) {
    cout << "Order a book...\n";
    Book newBook(title, author, releaseDate, pageCount);
    books.push_back(newBook);
    cout << "Book \"" << title << "\" successfully ordered.\n";
}

void Student::applyForDiplomaProject() {
    if (course == "final") {
        cout << "Submitting an application for a graduation project...\n";
        isForDiplomaProject = true;
        cout << "The application for the diploma project has been submitted.\n";
    }
    else cout << "Mistake: applying for a diploma project is possible only in the final year.\n";
}

void Student::applyForAccommodation() {
    cout << "Submission of an application for accommodation...\n";
    isAccommodated = true;
    cout << "The application for settlement has been submitted.\n";
}

void Student::reportError(string error) {cout << "Error Message: " << error << "\n";}

//the ability of students to enroll in the course themselves
void Student::enrollCourse(Course newCourse) {courses.push_back(newCourse);}

void Student::attendLesson(Lesson& lesson) {attendedLessons.push_back(lesson);}

bool Student::isPresentAtLesson(Lesson& lesson) {
    for (int i = 0; i < attendedLessons.size(); i++) {
        if (attendedLessons[i] == lessons[i]) return true;
    }
    return false;
}

void Student::addGrade(Grade newGrade) {grades.push_back(newGrade);}

void Student::addFavoriteSchedule(Schedule schedule) {favoriteSchedules.push_back(schedule);}

vector<Schedule> Student::getFavoriteSchedules() { return favoriteSchedules; }
