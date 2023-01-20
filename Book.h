#pragma once
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string isbn, bookName, author, category;
    int copies;
    vector<int> bookID;
public:
    Book();
    string getIsbn();
    string getName();
    string getAuthor();
    string getGenre();
    vector<int> getID();
    int getCopies();
    void setIsbn(string isbnNum);
    void setName(string name);
    void setAuthor(string bookAuthor);
    void setGenre(string genre);
    void setCopies(int numCopies);
    void setID(vector<int> idNum);
    void setData(string isbnNum, string name, string bookAuthor, string genre, int numCopies,vector<int> idNum);
};
