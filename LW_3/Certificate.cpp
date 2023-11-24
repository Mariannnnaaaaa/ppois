#include "Certificate.h"
using namespace std;

Certificate::Certificate(){}
Certificate::Certificate(string documentType, string startDate, string endDate, string notes)
    : documentType(documentType), startDate(startDate), endDate(endDate), notes(notes) {}

string Certificate::getDocumentType() { return documentType; }
string Certificate::getStartDate() { return startDate; }
string Certificate::getEndDate() { return endDate; }
string Certificate::getNotes() { return notes; }

void Certificate::setDocumentType(string newDocumentType) { documentType = newDocumentType; }
void Certificate::setStartDate(string newStartDate) { startDate = newStartDate; }
void Certificate::setEndDate(string newEndDate) { endDate = newEndDate; }
void Certificate::setNotes(string newNotes) { notes = newNotes; }