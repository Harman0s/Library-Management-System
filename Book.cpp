#include "Book.h"
#include <vector>
using namespace std;

Book::Book() {}

//function which sets data into isbn, title, author, etc
void Book::setData(string isbnNum, string name, string bookAuthor, string genre, int numCopies,vector<int> idNum){
    isbn = isbnNum;
    bookName = name;
    author = bookAuthor;
    category = genre;
    copies = numCopies;
    bookID.resize(copies);
    for(int i = 0; i<copies; i++){
        bookID[i]= idNum[i];
    }
}

//functions below simply either get/return or set the information individually when we want

string Book::getIsbn() {
    return isbn;
}
string Book::getName() {
    return bookName;
}
string Book::getAuthor() {
    return author;
}
string Book::getGenre() {
    return category;
}
int Book::getCopies() {
    return copies;
}
vector<int> Book::getID(){
    return bookID;
}
void Book::setIsbn(std::string isbnNum) {
    isbn = isbnNum;
}
void Book::setAuthor(std::string bookAuthor) {
    author = bookAuthor;
}
void Book::setName(std::string name) {
    bookName = name;
}
void Book::setGenre(std::string genre) {
    category = genre;
}
void Book::setCopies(int numCopies) {
    copies = numCopies;
}
void Book::setID(vector<int> idNum)
{
    bookID = idNum;
}
