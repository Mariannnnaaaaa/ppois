#include "Lesson.h"
using namespace std;

Lesson::Lesson(){}
Lesson::Lesson(string time, string dayOfWeek, string room, string type)
    : time(time), dayOfWeek(dayOfWeek), room(room), type(type), comments(""), isMissed(false) {}

string Lesson::getTime() { return time; }
string Lesson::getDayOfWeek() { return dayOfWeek; }
string Lesson::getRoom() { return room; }
string Lesson::getType() { return type; }
string Lesson::getComments() { return comments; }
bool Lesson::getIsMissed() { return isMissed; }

void Lesson::setTime(string newTime) { time = newTime; }
void Lesson::setDayOfWeek(string newDayOfWeek) { dayOfWeek = newDayOfWeek; }
void Lesson::setRoom(string newRoom) { room = newRoom; }
void Lesson::setType(string newType) { type = newType; }
void Lesson::setComments(string newComments) { comments = newComments; }
void Lesson::setIsMissed(bool newIsMissed) { isMissed = newIsMissed; }

bool Lesson::operator==(const Lesson& other) {
    return time == other.time &&
        dayOfWeek == other.dayOfWeek &&
        room == other.room &&
        type == other.type &&
        comments == other.comments &&
        isMissed == other.isMissed;
}