#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Lesson {
private:
    string time;
    string dayOfWeek;
    string room;
    string type; // lecture, practice, laboratory work, exam, consultation
    string comments;
    bool isMissed;

public:
    Lesson();
    Lesson(string time, string dayOfWeek, string room, string type);

    string getTime();
    string getDayOfWeek();
    string getRoom();
    string getType();
    string getComments();
    bool getIsMissed();

    void setTime(string newTime);
    void setDayOfWeek(string newDayOfWeek);
    void setRoom(string newRoom);
    void setType(string newType);
    void setComments(string newComments);
    void setIsMissed(bool newIsMissed);

    bool operator==(const Lesson& other);
};

