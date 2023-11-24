#include "Course.h"
using namespace std;

string Course::getCourseName() { return courseName; }
string Course::getDescription() { return description; }

void Course::setCourseName(string newCourseName) { courseName = newCourseName; }
void Course::setDescription(string newDescription) { description = newDescription; }
