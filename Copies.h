#include <iostream>
#include <string>
#pragma once
using namespace std;

class Copies {
private:
    string isbn;
    int id;
    string bookName;
public:
    Copies();
    void setData(string isbn, int id);
    string getIsbn();
    int getId();
    void setIsbn(string isbn);
    void setId(int id);
    string getBookName();
};
