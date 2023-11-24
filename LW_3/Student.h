#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Human.h"
#include "Certificate.h"
#include "Grade.h"
#include "Lesson.h"
#include "Book.h"
#include "Course.h"
#include "Schedule.h"

using namespace std;
class Student :public Human {
private:
    int studentID;
    string course;
    string speciality;
    string password;
    string login;
    vector<string> skills;
    vector<string> links;
    vector<Grade> grades;
    vector<string> documents;
    bool loggedIn = false;
    string information;
    vector<Certificate> certificates;
    vector<Lesson> lessons;
    vector<Lesson> attendedLessons;
    vector<Book> books;
    bool isOnSickLeave;
    bool isAccommodated;
    bool isForDiplomaProject;
    bool isPresent;
    vector<Course> courses;
    vector<Schedule> favoriteSchedules;

public:
    Student();
    Student(string name, string surname, string speciality);

    int getStudentID();
    string getCourse();
    string getSpeciality();
    vector<string> getSkills();
    vector<string> getLinks();
    vector<string> getDocuments();
    bool getIsPresent();

    void setStudentID(int newStudentID);
    void setCourse(string newCourse);
    void setSpeciality(string newSpeciality);
    void setSkills(vector<string> newSkills);
    void setLinks(vector<string> newLinks);
    void setDocuments(vector<string> newDocuments);
    void setIsPresent(bool present);

    void logIn(string enteredLogin, string enteredPassword);

    void addInformation(string info);

    void addSkill(string skill);

    void addLink(string link);

    void viewGrades();

    void orderCertificate(string documentType, string startDate, string endDate, string notes);

    //заказать ведомость
    void orderStatement();

    void viewCertificateHistory();

    void viewSchedule();

    double calculateAverageGrade();

    void applyForSickLeave();

    void viewMissedClasses();

    void orderBook(string title, string author, string releaseDate, int pageCount);

    void applyForDiplomaProject();

    void applyForAccommodation();

    void reportError(string error);

    //the ability of students to enroll in the course themselves
    void enrollCourse(Course newCourse);

    void attendLesson(Lesson& lesson);

    bool isPresentAtLesson(Lesson& lesson);

    void addGrade(Grade newGrade);

    void addFavoriteSchedule(Schedule schedule);

    vector<Schedule> getFavoriteSchedules();
};

