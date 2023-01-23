#include <iostream>
#include "User.h"
#include "Book.h"
#include "Copies.h"
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

Copies myCopies[20];
Book myBook[20];
Student student[20];
Teacher teacher[20];
Librarian librarian[20];
User user[20];

int uniqueID = 1;
int bookIndex= 0;
int copiesIndex = 0;

//function prototypes
void readBook();
void readPerson();
void readCopies();
void setData();
int userAuthentication(string username, string password);
void studentSwitch(int index);
void teacherSwitch(int index);
void librarianSwitch(int index);
void dateCounter(vector<time_t> startTimes, int role, int index);
void userBST();
void bookBST();
void copyBST();

//Function to create a Treenode for a Binary Search Tree
template <typename Type>
struct TreeNode {
    vector<Type> val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(vector<Type> val): val(val), left(NULL), right(NULL){}
};

//Function to insert a vector into a node in a Binary Search Tree
template <typename Type>
void insert(TreeNode<Type>*& root, vector<Type> key)
{
    TreeNode<Type>* node = new TreeNode<Type>(key);
    if (!root) {
        root = node;
        return;
    }
    TreeNode<Type>* prev = NULL;
    TreeNode<Type>* temp = root;
    while (temp) {
        if (temp->val > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->val < key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->val > key)
        prev->left = node;
    else
        prev->right = node;
}

//Function to display the info in a Binary Search Tree in inOrder
template <typename Type>
void inOrder(TreeNode<Type>* root)
{
    TreeNode<Type>* temp = root;
    stack<TreeNode<Type>*> st;
    while (temp != NULL || !st.empty()) {
        if (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        else {
            temp = st.top();
            st.pop();
            cout << temp->val[0] << " ";
            temp = temp->right;
        }
    }
    cout<<endl;
}

int main() {
    //function calls
    readBook();
    readPerson();
    readCopies();
    string username, password;
    
    //inputs for user login information
    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter your password: ";
    cin>>password;
    
    //user login doesn't match any text file logins
    int authentication = userAuthentication(username, password);
    if(authentication==2)
    {
        cout<<"Invalid username/password. Goodbye."<<endl;
        exit(1);
    }

    //user login matched to one from text file
    cout<<"Access Granted"<<endl;
    //If there's a successfull login then create a BST for each text file and its info
    userBST();
    bookBST();
    copyBST();
    
    //function call to the student switch statement function if login matches to a student's login 
    if(authentication<0){
        cout<<"------------------------------------------\n-\t\t\tWelcome to My Library!\t\t -\n------------------------------------------"<<endl;
        cout<<"Welcome Back, Student"<<endl;
        studentSwitch(authentication+100);
    }
    //function call to the teacher switch statement function if login matches to a teachers's login 
    if((authentication>0)&&(authentication<=200)){
        cout<<"------------------------------------------\n-\t\t\tWelcome to My Library!\t\t -\n------------------------------------------"<<endl;
        cout<<"Welcome Back, Teacher"<<endl;
        teacherSwitch(authentication-100);
    }
    //function call to the librarian switch statement function if login matches to a librarian's login
    if(authentication>=200){
        cout<<"------------------------------------------\n-\t\t\tWelcome to My Library!\t\t -\n------------------------------------------"<<endl;
        cout<<"Welcome Back, Librarian"<<endl;
        librarianSwitch(authentication-200);
    }
}

//Function to read in the book.txt file and it's data
void readBook(){
    setData();
    fstream bookFile("book.txt");
    vector<int> bookID = {};

    if(bookFile.fail())
    {
        cerr<<"Error opening input data";
    }
    string isbn, bookName, author, genre;
    int count = 0, copies;
    
    //until the end of the file it reads in each line of data and stores it
    //each book is also given an unique ID because there are multiple of the same books
    while(!bookFile.eof()){
        bookFile>>isbn>>bookName>>author>>genre>>copies;
        bookID.resize(copies);
        for(int i = 0; i<copies; i++){
            bookID[i] = uniqueID;
            uniqueID++;
        }
        myBook[count].setData(isbn,bookName,author,genre,copies, bookID);
        count++;
        bookIndex++;
    }
}

//function that starts a counter from when a book is borrowed and if it becomes overdue
void dateCounter(vector<time_t> startTimes, int role, int index)
{
    time_t currentTime;
    currentTime= time(NULL);
    int size = startTimes.size();
    
    //if the role is 0 then it is a student
    if(role == 0) {
        for (int i = 0; i < size; i++) {
            if((startTimes[i] != 0)) {                          //the timer begins once the book is borrowed 
                if ((currentTime - startTimes[i]) > 30) {       //if the book is not returned within 30 seconds
                    student[index].setOverdue(true, i);         //it becomes overdue since in our system 1 second
                }                                               //is 1 day
            }
        }
    }
    //if the role is 1 then it is a teacher
    if(role==1){
        for (int i = 0; i < size; i++) {
            if((startTimes[i] != 0)) {                          //the time starts and the book becomes
                if ((currentTime - startTimes[i]) > 50) {       //overdue after 50 seconds 
                    teacher[index].setOverdue(true, i);
                }
            }
        }
    }
}

//Function to read in the student.txt file and it's data
void readPerson(){
    fstream studentFile("student.txt");
    if(studentFile.fail())
    {
        cerr<<"Error opening input data";
    }
    int count = 0;
    string username, password;
    int role;
    
    //until the end of the file it reads in each line of data
    while(!studentFile.eof()){
        studentFile>>role>>username>>password;
        //the line of data begins with either a 0, 1, or 2
        //which determines if they are a student teacher or librarian
        //based on the role their role, username, and password is set
        //within that role
        if(role == 0){
            student[count].setData(role,username,password);
        }
        if(role == 1){
            teacher[count].setData(role,username,password);
        }
        if(role == 2){
            librarian[count].setData(username, password);
        }
        
        //new code
        user[count].setData(role, username, password);
        //new code
        
        count++;
    }
}

//Function to read in the copy.txt file and it's data
void readCopies(){
    fstream copiesFile("copy.txt");
    if(copiesFile.fail())
    {
        cerr<<"Error opening input data";
    }
    string isbn;
    int id;
    int count = 0;
    
    //each line reads in an isbn and a book copy number until the end of the file
    while(!copiesFile.eof()){
        copiesFile>>isbn>>id;
        myCopies[count].setData(isbn,id);
        count++;
        copiesIndex++;
    }
}

//Function that authenticates whether a user is a student, teacher or librarian
int userAuthentication(string username, string password){
    for(int i = 0; i<20; i++){
        //if input login info matches, a number less than 0 is returned 
        //it's used in the main function to show it is a student
        if(username==student[i].getUsername()){
            if(password==student[i].getPassword()){
                return i-100;
            }
        }
        //if input login info matches, a number more than 0 and less than 200 is returned 
        //it's used in the main function to show it is a teacher
        if(username==teacher[i].getUsername()){
            if(password==teacher[i].getPassword()){
                return i+100;
            }
        }
        //if input login info matches, a number more than 200 is returned 
        //it's used in the main function to show it is a librarian
        if(username==librarian[i].getUsername()){
            if(password==librarian[i].getPassword())
                return i+200;
        }
    }
    return 2; 
    //if 2 is returned it's used in the main to show it doesn't match
}

//Function that is a switch statement for the student to choose what they would like to do
void studentSwitch(int index){
    int ans=-1;
    string password;
    //the function asks the user to input a number to choose what they will do
    //0 is used to quit
    while(ans!=0){
        cout<<"Please Choose:\n\t1 -- Search Book\n\t2 -- Borrow Book\n\t3 -- Return Book\n\t4 -- Renew Book\n\t5 -- Reserve Book\n\t6 -- Cancel Book\n\t7 -- My Information\n\t8 -- Change Password\n\t0 -- Logout"<<endl;
        cin>>ans;
        switch (ans) {
            case 1:
                student[index].searchBooks(myBook);
                dateCounter(student[index].getBorrowTime(), 0, index);
                break;
            case 2:
                dateCounter(student[index].getBorrowTime(), 0, index);
                student[index].borrowBooks(myBook);
                break;
            case 3:
                student[index].returnBooks(myBook);
                break;
            case 4:
                student[index].renewBooks(myBook);
                dateCounter(student[index].getBorrowTime(), 0, index);
                break;
            case 5:
                student[index].reserveBook(myBook);
                break;
            case 6:
                student[index].cancelReserve(myBook);
                break;
            case 7:
                student[index].myInfo();
                break;
            case 8:
                cout<<"Enter new password"<<endl;
                cin>>password;
                student[index].setPassword(password);
                break;
            case 0:
                cout<<"Logging out goodbye"<<endl;
                exit(0);
                break;
            default:
                continue;
        }
    }
}

//Function that is a switch statement for the teacher to choose what they would like to do
void teacherSwitch(int index){
    int ans = -1;
    string password;
    //the function asks the user to input a number to choose what they will do
    //0 is used to quit
    while(ans!=0){
        cout<<"Please Choose:\n\t1 -- Search Book\n\t2 -- Borrow Book\n\t3 -- Return Book\n\t4 -- Renew Book\n\t5 -- Reserve Book\n\t6 -- Cancel Book\n\t7 -- My Information\n\t8 -- Change Password\n\t0 -- Logout"<<endl;
        cin>>ans;
        switch (ans) {
            case 1:
                teacher[index].searchBooks(myBook);
                dateCounter(teacher[index].getBorrowTime(), 1, index);
                break;
            case 2:
                dateCounter(teacher[index].getBorrowTime(), 1, index);
                teacher[index].borrowBooks(myBook);
                break;
            case 3:
                //Return book
                teacher[index].returnBooks(myBook);
                dateCounter(teacher[index].getBorrowTime(), 1, index);
                break;
            case 4:
                //renew book;
                dateCounter(teacher[index].getBorrowTime(), 1, index);
                teacher[index].renewBooks(myBook);
                break;
            case 5:
                teacher[index].reserveBook(myBook);
                break;
            case 6:
                teacher[index].cancelReserve(myBook);
                break;
            case 7:
                teacher[index].myInfo();
                break;
            case 8:
                cout<<"Enter new password"<<endl;
                cin>>password;
                teacher[index].setPassword(password);
                break;
            case 0:
                cout<<"Logging out goodbye"<<endl;
                exit(0);
            default:
                continue;
        }
    }
}

//Function that is a switch statement for the teacher to choose what they would like to do
void librarianSwitch(int index){
    int ans = -1;
    string password;
    //the function asks the user to input a number to choose what they will do
    //0 is used to quit
    while(ans!=0){
        cout<<"Please Choose:\n\t2 -- Add Book\n\t3 -- Delete Book\n\t4 -- Search User\n\t5 -- Add User\n\t6 -- Delete User\n\t7 -- My Information\n\t8 -- Change Password\n\t0 -- Logout"<<endl;
        cin>>ans;
        switch (ans) {
            case 2:
                librarian[index].requestCopy(myBook,uniqueID,bookIndex);
                break;
            case 3:
                //Return book
                librarian[index].deleteCopy(myBook);
                break;
            case 4:
                //search user;
                librarian[index].searchUser(user, student, teacher);
                break;
            case 5:
                librarian[index].addUser(user);
                readPerson();
                break;
            case 6:
                librarian[index].deleteUser(user);
                break;
            case 7:
                librarian[index].myInfo();
                break;
            case 8:
                cout<<"Enter new password"<<endl;
                cin>>password;
                librarian[index].setPassword(password);
                break;
            case 0:
                cout<<"Logging out goodbye"<<endl;
                exit(0);
            default:
                continue;
        }
    }
}
void userBST(){
    TreeNode<string>* root = NULL;
    vector<string> userVect;
    userVect.resize(3);
    for(int i =0; i<6; i++){
        userVect[0] = user[i].getUsername();
        userVect[1] = user[i].getPassword();
        userVect[2] = user[i].getRole();
        insert(root, userVect);
    }
    //inOrder(root);
}
void setData(){
    fstream bookFile("book.txt");
    if(bookFile.fail())
    {
        cerr<<"Error opening input data";
    }
    string isbnA[6] = {"9781283329705", "9781493938438", "9780134444291", "9780486661032", "9781423421924", "9780439708180"};
    string nameA[6] = {"Mobile_Wireless_Communications", "Pattern_Recognition_and_Machine_Learning", "Engineering_Problem_Solving_with_C++", "Advanced_Calculus"
    ,"First_Lessons_in_Bach", "Harry_Potter_and_the_Sorcerer's_Stone"};
    string authA[6] = {"Mischa_Schwartz", "Christopher_Bishop", "Delores_M_Etter", "David_Widder", "Johann_Sebastian_Bach", "JK_Rowling"};
    string category[6] = {"Computer_science","Computer_science","Computer_science","Math","Music","Fiction"};
    int copie[6] = {3,1,2,5,2,5};
    for(int i = 0; i<6; i++){
        bookFile<<isbnA[i]<<"\t"<<nameA[i]<<"\t"<<authA[i]<<"\t"<<category[i]<<"\t"<<copie[i]<<endl;
    }
    bookFile.close();
}
void bookBST(){
    TreeNode<string>* root = NULL;
    vector<string> bookVect;
    bookVect.resize(3);
    for(int i =0; i<6; i++){
        bookVect[0] = myBook[i].getIsbn();
        bookVect[1] = myBook[i].getName();
        bookVect[2] = myBook[i].getAuthor();
        insert(root, bookVect);
    }
    //inOrder(root);
}

void copyBST(){
    TreeNode<string>* root = NULL;
    vector<string> copyVect;
    copyVect.resize(3);
    for(int i =0; i<19; i++){
        copyVect[0] = to_string(myCopies[i].getId());
        copyVect[1] = myCopies[i].getIsbn();
        insert(root, copyVect);
    }
    //inOrder(root);
}
