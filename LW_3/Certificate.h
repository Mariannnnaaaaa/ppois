#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Certificate {
private:
    string documentType;
    string startDate;
    string endDate;
    string notes;

public:
    Certificate();
    Certificate(string documentType, string startDate, string endDate, string notes);

    string getDocumentType();
    string getStartDate();
    string getEndDate();
    string getNotes();

    void setDocumentType(string newDocumentType);
    void setStartDate(string newStartDate);
    void setEndDate(string newEndDate);
    void setNotes(string newNotes);
};
