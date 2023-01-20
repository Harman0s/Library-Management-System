#include <string>
#include <iostream>
#include "Book.h"
#include <vector>
#include "Copies.h"
#include <list>
using namespace std;

//Base Class User
class User {
private:
    int role;
    string username;
    string password;
public:
    User();
    string getUsername();
    string getPassword();
    int getRole();
    void setRole(int theRole);
    void setName(string theName);
    void setPass(string thePass);
    void setData(int theRole, string theName, string thePass);
};

//Derived class Reader inherits from base class User
class Reader: public User{
private:
    string username = getUsername();
    string password = getPassword();
    list<string> borrowedCopies;
    list<string> reservedCopies;
public:
    Reader();
    void searchBooks(Book myBook[],Copies myCopies[]);
};
class Node
{
public:
    string data;
    Node *next;
};
//Derived class Student inherits from derived class Reader
class Student:public Reader {
private:
    int role;
    string username, password;
    vector<string> borrowedTitles={"","","","",""}, borrowedAuthor={"","","","",""}, borrowedGenre={"","","","",""}, borrowedISBN={"","","","",""};
    vector<int> borrowedID= {0,0,0,0,0,};
    //borrowedID.resize(5);
    int numBorrowed = 0;
    vector<bool> overdue = {false,false,false,false,false};
    vector<time_t> borrowTime = {0,0,0,0,0};
    Node* reserveHead = NULL;
public:
    Student();
    int getRole();
    string getUsername();
    string getPassword();
    void setRole(int theRole);
    void setUsername(string name);
    void setPassword(string pass);
    void setData(int theRole, string name, string pass);
    void searchBooks(Book myBook[]);
    void borrowBooks(Book myBook[]);
    void returnBooks(Book myBook[]);
    void renewBooks(Book myBook[]);
    void myInfo();
    //void changePass(string word);
    vector<time_t> getBorrowTime();
    vector<bool> getOverdue();
    void setBorrowTime(time_t timeBorrowed, int index);
    void setOverdue(bool isOverdue, int index);
    vector<int> getBorrowedID();
    void reserveBook(Book myBook[]);
    void cancelReserve(Book myBook[]);
};

//Derived class Teacher inherits from derived class Reader
class Teacher: public Reader {
private:
    int role;
    string username, password;
    vector<string> borrowedTitles={"","","","","","","","","",""}, borrowedAuthor={"","","","","","","","","",""},
            borrowedGenre={"","","","","","","","","",""}, borrowedISBN={"","","","","","","","","",""};
    vector<int> borrowedID= {0,0,0,0,0,0,0,0,0,0};
    int numBorrowed = 0;
    vector<bool> overdue = {false,false,false,false,false,false,false,false,false,false};
    vector<time_t> borrowTime = {0,0,0,0,0,0,0,0,0,0};
    Node* reserveHead = NULL;
public:
    Teacher();
    int getRole();
    string getUsername();
    string getPassword();
    void setRole(int theRole);
    void setUsername(string name);
    void setPassword(string pass);
    void setData(int theRole, string name, string pass);
    void searchBooks(Book myBook[]);
    void borrowBooks(Book myBook[]);
    void myInfo();
    void returnBooks(Book myBook[]);
    void renewBooks(Book myBook[]);
    vector<time_t> getBorrowTime();
    vector<bool> getOverdue();
    void setBorrowTime(time_t timeBorrowed, int index);
    void setOverdue(bool isOverdue, int index);
    vector<int> getBorrowedID();
    void reserveBook(Book myBook[]);
    void cancelReserve(Book myBook[]);
};

//Derived class Librarian inherits from base class User
class Librarian: public User{
private:
    string username = getUsername();
    string password = getPassword();
public:
    Librarian();
    void setData(string username, string password);
    string getUsername();
    string getPassword();
    void requestCopy(Book myBook[], int &uniqueId, int &bookIndex);
    void deleteCopy(Book myBook[]);
    void addUser(User user[]);
    void deleteUser(User user[]);
    void myInfo();  
    void setPassword(string pass);
    void searchUser(User user[], Student student[], Teacher teacher[]);
};
