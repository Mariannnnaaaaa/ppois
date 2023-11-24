#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Lesson.h"

using namespace std;
class Schedule {
private:
    vector<Lesson> lessons;

public:
    void printWeeklyLessons();
};

