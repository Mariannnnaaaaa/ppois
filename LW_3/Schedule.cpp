#include "Schedule.h"
using namespace std;

void Schedule::printWeeklyLessons() {
    for (int i = 0; i < lessons.size(); i++) {
        cout << "Day of week: " << lessons[i].getDayOfWeek() << "\n";
        cout << "Time: " << lessons[i].getTime() << "\n";
        cout << "Room: " << lessons[i].getRoom() << "\n";
        cout << "Type: " << lessons[i].getType() << "\n";
    }
}