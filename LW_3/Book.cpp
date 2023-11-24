#include "Book.h"
using namespace std;

Book::Book(){}
Book::Book(string title, string author, string releaseDate, int pageCount)
    : title(title), author(author), releaseDate(releaseDate), pageCount(pageCount) {}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getReleaseDate() { return releaseDate; }
int Book::getPageCount() { return pageCount; }

void Book::setTitle(string newTitle) { title = newTitle; }
void Book::setAuthor(string newAuthor) { author = newAuthor; }
void Book::setReleaseDate(string newReleaseDate) { releaseDate = newReleaseDate; }
void Book::setPageCount(int newPageCount) { pageCount = newPageCount; }