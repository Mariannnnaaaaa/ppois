#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Book {
private:
    string title;
    string author;
    string releaseDate;
    int pageCount;
public:
    Book();
    Book(string title, string author, string releaseDate, int pageCount);

    string getTitle();
    string getAuthor();
    string getReleaseDate();
    int getPageCount();

    void setTitle(string newTitle);
    void setAuthor(string newAuthor);
    void setReleaseDate(string newReleaseDate);
    void setPageCount(int newPageCount);
};
