#include "Copies.h"
using namespace std;


Copies::Copies() {}

/* function to set data into isbn and id from the copy.txt
but we also include if statements for each isbn to relate
it to its book name */ 
void Copies::setData(string isbn, int id) {
    this->isbn = isbn;
    this->id = id;
    if(isbn == "9781283329705"){
        bookName = "Mobile_Wireless_Communications";
    }
    if(isbn == "9781493938438"){
        bookName = "Pattern_Recognition_and_Machine_Learning";
    }
    if(isbn == "9780134444291"){
        bookName = "Engineering_Problem_Solving_with_C++";
    }
    if(isbn == "9780486661032"){
        bookName = "Advanced_Calculus";
    }
    if(isbn == "9781423421924"){
        bookName = "First_Lessons_in_Bach";
    }
    if(isbn == "9780439708180"){
        bookName = "Harry_Potter_and_the_Sorcerer's_Stone";
    }
}
string Copies::getBookName() {
    return bookName;
}
string Copies::getIsbn(){
    return isbn;
}
int Copies::getId() {
    return id;
}
void Copies::setIsbn(std::string isbn) {
    this->isbn = isbn;
}
void Copies::setId(int id) {
    this->id = id;
}
