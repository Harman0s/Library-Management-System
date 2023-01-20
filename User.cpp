#include "User.h"
#include <fstream>
#include <sstream>
#include <string>

Reader reader;

//all the initial functions are fairly simple
//they are all either returning or setting values when called
Reader::Reader(){}
User::User(){}
string User::getUsername() {
    return username;
}
string User::getPassword() {
    return password;
}
void User::setData(int theRole, string theName, string thePass){
    role = theRole;
    username = theName;
    password = thePass;
}
int User::getRole() {
    return role;
}
void User::setRole(int theRole) {
    role = theRole;
}
void User::setName(string theName) {
    username = theName;
}
void User::setPass(string thePass) {
    password = thePass;
}
Librarian::Librarian()
{}
void Librarian::setData(std::string username, std::string password) {
    this->username=username;
    this->password=password;
}
/**
 * gets the username of the librarian
 * @return
 */
string Librarian::getUsername() {
    return username;
}
/**
 * gets password of the librarian
 * @return
 */
string Librarian::getPassword() {
    return password;
}
Student::Student() {

}
/**
 * gets the role of the student from the text file
 * @return
 */
int Student::getRole() {
    return role;
}
/**
 * gets student username
 * @return
 */
string Student::getUsername() {
    return username;
}
/**
 * gets student password
 * @return
 */
string Student::getPassword() {
    return password;
}
vector<time_t> Student::getBorrowTime() {
    return borrowTime;
}
/**
 * returns whether the book is overdue
 * @return
 */
vector<bool> Student::getOverdue(){
    return overdue;
}
/**
 * sets a limit for whether a book is overdue
 * @param isOverdue
 * @param index
 */
void Student::setOverdue(bool isOverdue, int index) {
    overdue[index] = isOverdue;
}
/**
 * sets the alotted time that a student has to borrow a book
 * @param timeBorrowed
 * @param index
 */
void Student::setBorrowTime(time_t timeBorrowed, int index) {
    borrowTime[index] = timeBorrowed;
}
void Student::setRole(int theRole) {
    role = theRole;
}
void Student::setUsername(std::string name) {
    username = name;
}
void Student::setPassword(std::string pass) {
    password = pass;
}

//function to display a teachers own info
void Teacher::myInfo(){
    cout<<"Your Info:"<<endl;
    cout<<"Username: "<<username<<endl;
    cout<<"Password: "<<password<<endl;
}

//function to set a students information
void Student::setData(int theRole, string name, string pass){
    role = theRole;
    username = name;
    password = pass;
}

//function to sort
void studentBubbleSort(vector<int>& id, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (id[j] > id[j + 1]) {
                int temp = id[j];
                id[j] = id[j+1];
                id[j+1] = temp;
            }
        }
    }
}
/**
 * binary search is used to search a vector for a certain book by traversing the vector
 * @param bookID
 * @param searchFor
 * @param lower
 * @param upper
 * @return
 */
int studentBinarySearch(vector<int> bookID, int searchFor, int lower, int upper){
    int sizeVec = bookID.size();
    if(sizeVec == 0){
        return -1;
    }
    if(upper>=lower){
        int mid = (lower + upper)/2;
        if(bookID[mid]==searchFor){
            return mid;
        }
        if(bookID[mid]>searchFor){
            return studentBinarySearch(bookID, searchFor, lower, mid - 1);
        }
        return studentBinarySearch(bookID, searchFor, mid + 1, upper);
    }
    return -1;
}

/**
 * function for a student to search for a book based on any parameter
 * @param myBook 
 */
void Student::searchBooks(Book myBook[]){
    cout << "Searching by:\n\t1-ISBN\n\t2-Title\n\t3-Category" << endl;
    int searchParam, indexGenre = 0, idSearch;
    cin >> searchParam;
    string isbnSearch, titleSearch, genreSearch, genreArr[10];
    int minIndex;
    string minVal;

    //searching for a book based on isbn
    if (searchParam == 1) {
        cout << "Enter ISBN: ";
        cin >> isbnSearch;
        for (int i = 0; i < 20; i++) {
            if (isbnSearch == myBook[i].getIsbn()) {
                cout << "ISBN: " << myBook[i].getIsbn() << endl;
                cout << "Title: " << myBook[i].getName() << endl;
                cout << "Author: " << myBook[i].getAuthor() << endl;
                cout << "Category: " << myBook[i].getGenre() << endl;
                cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;
            }
        }
    }
    //searching for a book based on title
    if (searchParam == 2) {
        cout << "Enter Book Title: ";
        cin >> titleSearch;
        for (int i = 0; i < 20; i++) {
            if (titleSearch == myBook[i].getName()) {
                cout << "ISBN: " << myBook[i].getIsbn() << endl;
                cout << "Title: " << myBook[i].getName() << endl;
                cout << "Author: " << myBook[i].getAuthor() << endl;
                cout << "Category: " << myBook[i].getGenre() << endl;
                cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;
            }
        }
    }
    //searching for a book based on genre
    if (searchParam == 3) {
        cout << "Enter Book Category: ";
        cin >> genreSearch;
        for (int i = 0; i < 19; i++) {
            if (genreSearch == myBook[i].getGenre()) {
                genreArr[indexGenre] = myBook[i].getName();
                indexGenre++;
            }
        }
        for (int i = 0; i < (indexGenre - 1); i++) {
            minIndex = i;
            minVal = genreArr[i];
            for (int j = i + 1; j < indexGenre; j++) {
                if (genreArr[j] < minVal) {
                    minVal = genreArr[j];
                    minIndex = j;
                }
            }
            genreArr[minIndex] = genreArr[i];
            genreArr[i] = minVal;
        }
        for(int i = 0; i<indexGenre; i++){
            for(int j = 0; j<19; j++){
                if(genreArr[i]==myBook[j].getName()){
                    cout << "ISBN: " << myBook[j].getIsbn() << endl;
                    cout << "Title: " << myBook[j].getName() << endl;
                    cout << "Author: " << myBook[j].getAuthor() << endl;
                    cout << "Category: " << myBook[j].getGenre() << endl;
                    cout << "Copies Available: " << myBook[j].getCopies() << endl<<endl;
                }
            }
        }
    }
    //searching for a book based on ID
    if (searchParam == 4) {
        cout << "Enter Book ID: ";
        cin >> idSearch;
        for(int i = 0; i<19; i++){
            int size = myBook[i].getID().size();
            int binSearchResult = studentBinarySearch(myBook[i].getID(), idSearch, 0, size-1);
            if(binSearchResult != -1){
                cout << "ISBN: " << myBook[i].getIsbn() << endl;
                cout << "Title: " << myBook[i].getName() << endl;
                cout << "Author: " << myBook[i].getAuthor() << endl;
                cout << "Category: " << myBook[i].getGenre() << endl;
                cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;
                return;
            }
        }
        cout<<"ID Not Found. Book Not Found."<<endl;
    }
}
/**
 * Function for a student to borrow a book
 * @param myBook 
 */
void Student::borrowBooks(Book *myBook) {
    int idSearch, toReturn = -1;
    vector<bool> overdueCopy = overdue;

    //case for book being overdue, student unable to borrow a new one
    for(int i=0; i<numBorrowed; i++){
        if(overdueCopy[i]){
            cout<<"Book: "<<borrowedTitles[i]<<" (ID: "<<borrowedID[i]<<") is overdue. Return or renew it to borrow another book."<<endl;
            //return;
            toReturn++;
        }
    }
    if(toReturn>-1){
        return;
    }

    //max books borrowed, cannot borrow more
    if (numBorrowed == 5)
    {
        cout << "Maximum amount of books borrowed! Return a book to borrow another." << endl;
        return;
    }

    //searching for ID
    cout << "Enter Book ID: ";
    cin >> idSearch;
    for(int i = 0; i<19; i++){
        int size = myBook[i].getID().size();
        vector<int> idCopy = myBook[i].getID();
        int binSearchResult = studentBinarySearch(myBook[i].getID(), idSearch, 0, size - 1);
        if(binSearchResult != -1){
            cout << "Book found!" << endl;
            cout << "ISBN: " << myBook[i].getIsbn() << endl;
            cout << "Title: " << myBook[i].getName() << endl;
            cout << "Author: " << myBook[i].getAuthor() << endl;
            cout << "Category: " << myBook[i].getGenre() << endl;
            cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;

            //decrement the number of copies stored in book.h
            int copies = myBook[i].getCopies();
            copies--;
            myBook[i].setCopies(copies);
            cout<<"Copies available after borrowing the book: "<<copies<<endl;
            borrowTime[numBorrowed] = time(NULL);
            //storing the borrowed book info
            borrowedID[numBorrowed] = idSearch;
            borrowedTitles[numBorrowed] = myBook[i].getName();
            borrowedISBN[numBorrowed] = myBook[i].getIsbn();
            borrowedAuthor[numBorrowed] = myBook[i].getAuthor();
            borrowedGenre[numBorrowed] = myBook[i].getGenre();

            //increment how many books borrowed
            numBorrowed++;
            cout<<"Student: "<<username<<endl;
            cout << "You have borrowed " << numBorrowed  << " books" << endl;
            //Remove ID from search
            idCopy[binSearchResult] = 1000;
            studentBubbleSort(idCopy, size);
            idCopy.resize((size-1));
            myBook[i].setID(idCopy);

            //Get Borrow Time
            time_t currentTime;
            currentTime = time(NULL);
            setBorrowTime(currentTime,numBorrowed-1);
            return;
        }
    }
    if(idSearch>18){
        cout<<"Book ID not found."<<endl;
    }
    else{
        cout<<"The Book with this ID has already been borrowed."<<endl;
    }
}
/**
 * Function for a student to return a book
 * @param myBook 
 */
void Student::returnBooks(Book myBook[])
{
    int idSearch, index;

    //case for student not having any books borrowed
    if(numBorrowed==0){
        cout<<"You don't have any books borrowed to return"<<endl;
        return;
    }
    cout << "Enter the idSearch of the book you would like to return: ";
    cin >> idSearch;

    //checking if the book student is trying to return is borrowed
    int notFound = 0;
    for (int i= 0; i < 5; i++)
    {
        if (idSearch == borrowedID[i])
        {
            cout << "The book you're returning is: " << borrowedTitles[i] << endl;
            index = i;
            //break;
        }
        if (idSearch != borrowedID[i])
        {
            notFound++;
        }
    }
    if (notFound == 5)
    {
        cout << "You did not borrow this book";
        return;
    }

    //finding book object the returned book belongs to
    int count;

    for (int j = 0; j < 5; j++)
    {
        for(int k=0; k<6; k++)
            if (borrowedTitles[j] == myBook[k].getName())
            {
                count = j;
            }
    }

    //increment the number of copies in the library
    vector<int> IDNum;
    int copies;
    copies = myBook[count].getCopies();
    copies++;
    myBook[count].setCopies(copies);

    //adding the idSearch number back into library

    IDNum = myBook[count].getID();
    IDNum.resize(copies);

    int size = copies;

    IDNum[size - 1] = idSearch;
    //Sort Here
    studentBubbleSort(IDNum, copies);
    myBook[count].setID(IDNum);

    //decrement the number of borrowed books
    numBorrowed--;
    cout << "You have " << numBorrowed << " books borrowed right now" << endl;
    borrowedTitles[index] = "";
    borrowTime[index] = 0;
    borrowedID[index] = 0;
    overdue[index] = false;
}


/**
 * Function for a student to renew a book
 * @param myBook 
 */
void Student::renewBooks(Book myBook[])
{
    int ID;
    cout << "Enter the ID of the book you would like to renew: ";
    cin >> ID;

    //checking to see if the book is actually borrowed
    int i, notFound = 0, index;

    for (i = 0; i < 5; i++)
    {
        if (ID == borrowedID[i])
        {
            index = i;
            break;
        }
        else if (ID != borrowedID[i])
        {
            notFound++;
        }
    }

    //case for user not having borrowed the book
    if (notFound == 5)
    {
        cout << "You did not borrow this book"<<endl;
        return;
    }

    //setting the borrow time to current time
    time_t currentTime;
    currentTime = time(NULL);
    setBorrowTime(currentTime, index);

    //set it so that its not label as overdue now

    //setOverdue(overdue, i);
    overdue[index] = false;

    cout << "You have successfully renewed the book: " << borrowedTitles[index] << endl;
    cout << "You have " << numBorrowed << " books borrowed right now" << endl;
}

/**
 * Function to display students own info
 */
void Student::myInfo() {
    cout<<"Your Info:"<<endl;
    cout<<"Username: "<<username<<endl;
    cout<<"Password: "<<password<<endl;
}

//Some of the following functions are fairly simple
//they are either returning or setting values when called
Teacher::Teacher() {}
int Teacher::getRole() {
    return role;
}
string Teacher::getUsername() {
    return username;
}
string Teacher::getPassword() {
    return password;
}
void Teacher::setRole(int theRole) {
    role = theRole;
}
void Teacher::setPassword(std::string pass) {
    password = pass;
}
void Teacher::setUsername(std::string name) {
    username = name;
}
void Teacher::setData(int theRole, std::string name, std::string pass) {
    role = theRole;
    username = name;
    password = pass;
}
vector<time_t> Teacher::getBorrowTime() {
    return borrowTime;
}
vector<bool> Teacher::getOverdue(){
    return overdue;
}
void Teacher::setOverdue(bool isOverdue, int index) {
    overdue[index] = isOverdue;
}
void Teacher::setBorrowTime(time_t timeBorrowed, int index) {
    borrowTime[index] = timeBorrowed;
}
/**
 * uses bubble sort by indexing through a vector
 * uses the size parameter to set a limit for the size
 * @param id 
 * @param size 
 */
void teacherBubbleSort(vector<int>& id, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (id[j] > id[j + 1]) {
                int temp = id[j];
                id[j] = id[j+1];
                id[j+1] = temp;
            }
        }
    }
}
/**
 * uses binary search to find a specific book using the book id
 * @param bookID 
 * @param searchFor 
 * @param lower 
 * @param upper 
 * @return 
 */
int teacherBinarySearch(vector<int> bookID, int searchFor, int lower, int upper){
    //int top = bookID.size() - 1;
    int sizeVec = bookID.size();
    if(sizeVec == 0){
        return -1;
    }
    if(upper>=lower){
        int mid = (lower+upper)/2;
        if(bookID[mid]==searchFor){
            return mid;
        }
        if(bookID[mid]>searchFor){
            return teacherBinarySearch(bookID, searchFor, lower, mid - 1);
        }
        return teacherBinarySearch(bookID, searchFor, mid + 1, upper);
    }
    return -1;
}

/**
 * function for a student to search for a book based on any parameter
 * @param myBook 
 */
void Teacher::searchBooks(Book myBook[]) {
    cout << "Searching by:\n\t1-ISBN\n\t2-Title\n\t3-Category" << endl;
    int searchParam, indexGenre = 0, idSearch;
    cin >> searchParam;
    string isbnSearch, titleSearch, genreSearch, genreArr[10];
    int minIndex;
    string minVal;

    //searching based on isbn
    if (searchParam == 1) {
        cout << "Enter ISBN: ";
        cin >> isbnSearch;
        for (int i = 0; i < 20; i++) {
            if (isbnSearch == myBook[i].getIsbn()) {
                cout << "ISBN: " << myBook[i].getIsbn() << endl;
                cout << "Title: " << myBook[i].getName() << endl;
                cout << "Author: " << myBook[i].getAuthor() << endl;
                cout << "Category: " << myBook[i].getGenre() << endl;
                cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;
            }
        }
    }
    //searching based on title
    if (searchParam == 2) {
        cout << "Enter Book Title: ";
        cin >> titleSearch;
        for (int i = 0; i < 20; i++) {
            if (titleSearch == myBook[i].getName()) {
                cout << "ISBN: " << myBook[i].getIsbn() << endl;
                cout << "Title: " << myBook[i].getName() << endl;
                cout << "Author: " << myBook[i].getAuthor() << endl;
                cout << "Category: " << myBook[i].getGenre() << endl;
                cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;
            }
        }
    }
    //searching based on genre
    if (searchParam == 3) {
        cout << "Enter Book Category: ";
        cin >> genreSearch;
        for (int i = 0; i < 19; i++) {
            if (genreSearch == myBook[i].getGenre()) {
                genreArr[indexGenre] = myBook[i].getName();
                indexGenre++;
            }
        }
        for (int i = 0; i < (indexGenre - 1); i++) {
            minIndex = i;
            minVal = genreArr[i];
            for (int j = i + 1; j < indexGenre; j++) {
                if (genreArr[j] < minVal) {
                    minVal = genreArr[j];
                    minIndex = j;
                }
            }
            genreArr[minIndex] = genreArr[i];
            genreArr[i] = minVal;
        }
        for(int i = 0; i<indexGenre; i++){
            for(int j = 0; j<19; j++){
                if(genreArr[i]==myBook[j].getName()){
                    cout << "ISBN: " << myBook[j].getIsbn() << endl;
                    cout << "Title: " << myBook[j].getName() << endl;
                    cout << "Author: " << myBook[j].getAuthor() << endl;
                    cout << "Category: " << myBook[j].getGenre() << endl;
                    cout << "Copies Available: " << myBook[j].getCopies() << endl<<endl;
                }
            }
        }
    }
    //searching based on ID
    if (searchParam == 4) {
        cout << "Enter Book ID: ";
        cin >> idSearch;
        for(int i = 0; i<19; i++){
            int size = myBook[i].getID().size();
            int binSearchResult = teacherBinarySearch(myBook[i].getID(), idSearch, 0, size - 1);
            if(binSearchResult != -1){
                cout << "ISBN: " << myBook[i].getIsbn() << endl;
                cout << "Title: " << myBook[i].getName() << endl;
                cout << "Author: " << myBook[i].getAuthor() << endl;
                cout << "Category: " << myBook[i].getGenre() << endl;
                cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;
                return;
            }
        }
        cout<<"ID Not Found. Book Not Found."<<endl;
    }
}

/**
 * Function for a teacher to borrow a book
 * @param myBook 
 */
void Teacher::borrowBooks(Book *myBook) {
    int idSearch, toReturn = -1;
    vector<bool> overdueCopy = overdue;

    //case for a book being overdue, student unable to borrow a new one
    for(int i=0; i<numBorrowed; i++){
        if(overdueCopy[i]){
            cout<<"Book: "<<borrowedTitles[i]<<" (ID: "<<borrowedID[i]<<") is overdue. Return or renew it to borrow another book."<<endl;
            //return;
            toReturn++;
        }
    }
    if(toReturn>-1){
        return;
    }

    //if the teacher have already borrowed the max amount of books
    if (numBorrowed == 10)
    {
        cout << "Maximum amount of books borrowed! Return a book to borrow another." << endl;
        return;
    }

    //searching for ID
    cout << "Enter Book ID: ";
    cin >> idSearch;
    for(int i = 0; i<19; i++){
        int size = myBook[i].getID().size();
        vector<int> idCopy = myBook[i].getID();
        int binSearchResult = teacherBinarySearch(myBook[i].getID(), idSearch, 0, size - 1);
        if(binSearchResult != -1){
            cout << "Book found!" << endl;
            cout << "ISBN: " << myBook[i].getIsbn() << endl;
            cout << "Title: " << myBook[i].getName() << endl;
            cout << "Author: " << myBook[i].getAuthor() << endl;
            cout << "Category: " << myBook[i].getGenre() << endl;
            cout << "Copies Available: " << myBook[i].getCopies() << endl<<endl;

            //decrement the number of copies stored in book.h
            int copies = myBook[i].getCopies();
            copies--;
            myBook[i].setCopies(copies);
            cout<<"Copies available after borrowing the book: "<<copies<<endl;
            borrowTime[numBorrowed] = time(NULL);
            //storing the borrowed book info
            borrowedID[numBorrowed] = idSearch;
            borrowedTitles[numBorrowed] = myBook[i].getName();
            borrowedISBN[numBorrowed] = myBook[i].getIsbn();
            borrowedAuthor[numBorrowed] = myBook[i].getAuthor();
            borrowedGenre[numBorrowed] = myBook[i].getGenre();

            //increment how many books borrowed
            numBorrowed++;
            cout<<"Teacher: "<<username<<endl;
            cout << "You have borrowed " << numBorrowed  << " books" << endl;
            //Remove ID from search
            idCopy[binSearchResult] = 1000;
            teacherBubbleSort(idCopy, size);
            idCopy.resize((size-1));
            myBook[i].setID(idCopy);

            //Get Borrow Time
            time_t currentTime;
            currentTime = time(NULL);
            setBorrowTime(currentTime,numBorrowed-1);
            return;
        }
    }
    if(idSearch>18){
        cout<<"Book ID not found."<<endl;
    }
    else{
        cout<<"The Book with this ID has already been borrowed."<<endl;
    }
}

/**
 * Function for teacher to return a book
 * @param myBook 
 */
void Teacher::returnBooks(Book myBook[])
{
    int idSearch, index;
    if(numBorrowed==0){
        cout<<"You don't have any books borrowed to return"<<endl;
        return;
    }
    cout << "Enter the idSearch of the book you would like to return: ";
    cin >> idSearch;

    //checking if the book teacher is trying to return is borrowed
    int notFound = 0;
    for (int i= 0; i < 10; i++)
    {
        if (idSearch == borrowedID[i])
        {
            cout << "The book you're returning is: " << borrowedTitles[i] << endl;
            index = i;
            //break;
        }
        if (idSearch != borrowedID[i])
        {
            notFound++;
        }
    }

    if (notFound == 10)
    {
        cout << "You did not borrow this book";
        return;
    }

    //finding book object the returned book belongs to
    int count;

    for (int j = 0; j < 10; j++)
    {
        for(int k=0; k<20; k++)
            if (borrowedTitles[j] == myBook[k].getName())
            {
                count = j;
            }
    }

    //increment the number of copies in the library
    vector<int> IDNum;
    int copies;
    copies = myBook[count].getCopies();
    copies++;
    myBook[count].setCopies(copies);

    //adding the idSearch number back into library

    IDNum = myBook[count].getID();
    IDNum.resize(copies);

    int size = copies;

    IDNum[size - 1] = idSearch;
    //Sort Here
    teacherBubbleSort(IDNum, copies);
    myBook[count].setID(IDNum);

    //decrement the number of borrowed books
    numBorrowed--;
    cout << "You have " << numBorrowed << " books borrowed right now" << endl;
    borrowedTitles[index] = "";
    borrowTime[index] = 0;
    borrowedID[index] = 0;
    overdue[index] = false;
}

/**
 * Function to renew a book for a teacher
 * @param myBook 
 */
void Teacher::renewBooks(Book myBook[])
{
    int ID,index;
    cout << "Enter the ID of the book you would like to renew: ";
    cin >> ID;

    //checking to see if the book is actually borrowed
    int i, notFound = 0;
    for (i = 0; i < 10; i++)
    {
        if (ID == borrowedID[i])
        {
            index=i;
            break;
        }
        else if (ID != borrowedID[i])
        {
            notFound++;
        }
    }
    if (notFound == 10)
    {
        cout << "You did not borrow this book"<<endl;
        return;
    }

    //setting the borrow time to current time
    time_t currentTime;
    currentTime = time(NULL);
    setBorrowTime(currentTime, index);

    //set it so that its not label as overdue now

    overdue[index] = false;

    cout << "You have successfully renewed the book: " << borrowedTitles[index] << endl;
    cout << "You have " << numBorrowed << " books borrowed right now" << endl;
}

/**
 * Function for Librarian to request and add new book
 * @param myBook 
 * @param uniqueId 
 * @param bookIndex 
 */
void Librarian::requestCopy(Book *myBook, int& uniqueId, int& bookIndex) {
    string isbn, title, author, category;
    vector<int> id;
    id.resize(1);
    cout<<"Enter ISBN For New Book Copy: ";
    cin>>isbn;
    cout<<"Enter Title For New Book Copy: ";
    cin>>title;
    cout<<"Enter Author For New Book Copy: ";
    cin>>author;
    cout<<"Enter Category For New Book Copy: ";
    cin>>category;

    //Librarian inputs all book information and it is set and stored
    myBook[bookIndex].setIsbn(isbn);
    myBook[bookIndex].setName(title);
    myBook[bookIndex].setAuthor(author);
    myBook[bookIndex].setGenre(category);
    myBook[bookIndex].setCopies(1);
    cout<<"Book Copy Requested!"<<endl;
    id[0] = uniqueId;
    myBook[bookIndex].setID(id);
    bookIndex++;
    uniqueId++;
}

/**
 * Function for librariran to delete a book
 * @param myBook 
 */
void Librarian::deleteCopy(Book *myBook) {
    int idSearch;
    cout << "Enter Book ID: ";
    cin >> idSearch;
    for(int i = 0; i<19; i++){
        int size = myBook[i].getID().size();
        vector<int> idCopy = myBook[i].getID();
        int binSearchResult = teacherBinarySearch(myBook[i].getID(), idSearch, 0, size - 1);
        if(binSearchResult != -1){
            idCopy[binSearchResult] = 1000;
            teacherBubbleSort(idCopy, size);
            idCopy.resize((size-1));
            myBook[i].setID(idCopy);
            myBook[i].setCopies((myBook[i].getCopies()-1));
            cout<<"Book Copy Deleted!"<<endl;
            return;
        }
    }
    cout<<"ID Not Found. Book Not Found."<<endl;
}

/**
 * Function for librian to add a new user's information
 * @param user 
 */
void Librarian::addUser(User user[])
{
    string username, password;
    int role;
    //asking for account information
    cout << "Would you like to create an account for a student(0), teacher(1), or librarian(2)" << endl;
    cin >> role;

    //inputs username and password for the chosen role
    cout << "Please enter the username: " << endl;
    cin >> username;
    cout << "Please enter the password: " << endl;
    cin >> password;

    //output the new user info to student,.txt
    std::ofstream outfile;

    outfile.open("student.txt", std::ios_base::app); // append instead of overwrite
    outfile << role << "\t" << username << "\t" << password << endl;
}

/**
 * Function to display the librarians username and password
 */
void Librarian::myInfo()
{
    cout<<"Your Info:"<<endl;
    cout<<"Username: "<<username<<endl;
    cout<<"Password: "<<password<<endl;
}

void Librarian::setPassword(std::string pass)
{
    password = pass;
}

/**
 * Function for librarian to delete all of the user's info
 * @param user 
 */
void Librarian::deleteUser(User user[])
{
    //input the username
    string USERNAME;
    cout << "Enter the username of the account you would like to delete: " << endl;
    cin >> USERNAME;

    int i, deleted = 0;

    for (i = 0; i < 20; i++)
    {
        //if username match, delete the login info
        if (USERNAME == user[i].getUsername())
        {
            string newUsername = "";
            string newPassword = "";
            user[i].setData(0, newUsername, newPassword);
            deleted = 1;
        }
    }
    //if username not found
    if (deleted == 0)
    {
        cout << "User not found!" << endl;
    }
}

vector<int> Teacher::getBorrowedID()
{
    return borrowedID;
}
vector<int> Student::getBorrowedID()
{
    return borrowedID;
}

/**
 * Function for the librarian to search for a user
 * @param user 
 * @param student 
 * @param teacher 
 */
void Librarian::searchUser(User user[], Student student[], Teacher teacher[])
{
    int found = 0;
    int i;

    //input the username
    string username;
    cout << "Enter the username: " << endl;
    cin >> username;

    for (i = 0; i < 10; i++)
    {
        //comparing the input username to the stored usernames
        if (username == user[i].getUsername())
        {
            cout << "User Found!" << endl;
            found = 1;
            break;
        }
    }

    //it doesn't match any
    if (found == 0)
    {
        cout << "User not found!" << endl;
        return;
    }

    //if the input username is of a librarian
    if (user[i].getRole() == 2)
    {
        cout << "The user is a librarian" << endl;
        cout << "Username: " << user[i].getUsername() << endl;
        cout << "Password: " << user[i].getPassword() << endl;
    }

    int j;
    vector<int> bookID;

    //if the input username is of a teacher
    if (user[i].getRole() == 1)
    {
        //finding the index of the object in teacher[]
        for (j = 0; j < 20; j++)
        {
            if (username == teacher[j].getUsername())
            {
                break;
            }
        }

        bookID = teacher[j].getBorrowedID();

        cout << "The user is a teacher" << endl;
        cout << "Username: " << user[i].getUsername() << endl;
        cout << "Password: " << user[i].getPassword() << endl;

        //checking is the person has any books borrowed
        int IDCheck = 0;

        for (int index = 0; index < 10; index++)
        {
            IDCheck = IDCheck + bookID[index];
        }

        //if the user has no books borrowed
        if (IDCheck == 0)
        {
            cout << "This user does not have any borrowed books" << endl;
        }
        //if the user has borrowed books
        else
        {
            cout << "This user has borrowed books with the following ID (ID 0 means availiable book borrowing slots)" << endl;
            for (int index = 0; index < 10; index++)
            {
                cout << bookID[index] << endl;
            }
        }
    }

    //if the user is a student
    if (user[i].getRole() == 0)
    {
        //finding the index of the object in teacher[]
        for (j = 0; j < 20; j++)
        {
            if (username == student[j].getUsername())
            {
                break;
            }
        }

        bookID = student[j].getBorrowedID();

        cout << "The user is a student" << endl;
        cout << "Username: " << user[i].getUsername() << endl;
        cout << "Password: " << user[i].getPassword() << endl;

        //checking is the person has any books borrowed
        int IDCheck = 0;

        for (int index = 0; index < 5; index++)
        {
            IDCheck = IDCheck + bookID[index];
        }

        //if the user has no books borrowed
        if (IDCheck == 0)
        {
            cout << "This user does not have any borrowed books" << endl;
        }
        //if the user has borrowed books
        else
        {
            cout << "This user has borrowed books with the following ID (ID 0 means availiable book borrowing slots)" << endl;
            for (int index = 0; index < 5; index++)
            {
                cout << bookID[index] << endl;
            }
        }
    }
}
void append(Node** head_ref, string new_data)
{
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}
void deleteNode(Node** head_ref, int position)
{

    if (*head_ref == NULL)
        return;

    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    Node* next = temp->next->next;
    free(temp->next); // Free memory
    temp->next = next;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data<<",";
        node = node->next;
    }
}

//Function for student to reserve a burrowed book
void Student::reserveBook(Book *myBook) {
    //input book isbn
    cout<<"Enter the ISBN of the book you want to reserve: ";
    string isbnSearch;
    cin>>isbnSearch;
    int found = 0, index;
    for (int i = 0; i < 20; i++) {
        //case for book not needing to be reserved
        if (isbnSearch == myBook[i].getIsbn()) {
            found++;
            index = i;
            if(myBook[i].getCopies()>0){
                cout<<myBook[i].getName()<<" still has "<<myBook[i].getCopies()<<" copies left for you to borrow, no need to reserve it."<<endl;
                return;
            }
        }
    }
    //case for book needing to be reserved
    if(found>0){
        append(&reserveHead,myBook[index].getName());
    }
    cout<<"The book: "<<myBook[index].getName()<<" has been reserved."<<endl;
}

/**
 * Function for teacher to reserve a book
 * @param myBook 
 */
void Teacher::reserveBook(Book *myBook){
    cout<<"Enter the ISBN of the book you want to reserve: ";
    string isbnSearch;
    cin>>isbnSearch;
    int found = 0, index;
    for (int i = 0; i < 20; i++) {
        //case for book not needing to be reserved
        if (isbnSearch == myBook[i].getIsbn()) {
            found++;
            index = i;
            if(myBook[i].getCopies()>0){
                cout<<myBook[i].getName()<<" still has "<<myBook[i].getCopies()<<" copies left for you to borrow, no need to reserve it."<<endl;
                return;
            }
        }
    }
    //case for book needing to be reserved
    if(found>0){
        append(&reserveHead,myBook[index].getName());
    }
    cout<<"The book: "<<myBook[index].getName()<<" has been reserved."<<endl;
}

/**
 * Function for student canceling a reservation
 * @param myBook 
 */
void Student::cancelReserve(Book *myBook) {
    cout<<"Current List of reserved books:"<<endl;
    printList(reserveHead);
    cout<<"\nWhich reservation do you want to cancel? (Enter 1,2,3,etc... where leftmost book title is 1): ";
    int position;
    cin>>position;
    position = position -1;
    deleteNode(&reserveHead, position);
    cout<<"Reserved Books after canceling reservation: "<<endl;
    printList(reserveHead);
}

/**
 * Function for teacher canceling a reservation
 * @param myBook 
 */
void Teacher::cancelReserve(Book *myBook) {
    cout<<"Current List of reserved books:"<<endl;
    printList(reserveHead);
    cout<<"\nWhich reservation do you want to cancel? (Enter 1,2,3,etc... where leftmost book title is 1): ";
    int position;
    cin>>position;
    position = position -1;
    deleteNode(&reserveHead, position);
    cout<<"Reserved Books after canceling reservation: "<<endl;
    printList(reserveHead);
}
