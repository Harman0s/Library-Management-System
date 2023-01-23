# Library Management System C++

In this project, I designed a Library Management System, which is used to maintain the record of the library. It is able to display different types of information such as the number of available books in the library, late penalty record, the number of books that are issued, etc. It also has many functions such as borrwing books, returning books, renewing books, changing a users password to the system, and many more. This project can help to maintain a database that is useful to enter new books and record books borrowed by the members. 

This project allows the librarian to be able to maintain library resources in a more efficient and convenient way, helping save their time.
However, it is also beneficial for readers because they can keep track of the availability of all books in a store. In this project, a user will be able to use his own username and password to access the system and perform corresponding operations according to his user type – reader or librarian. 

A reader, which is either a student or teacher can login in the system, search books, borrow, reserve, renew and return books. A librarian has the most functions since they can also add/delete both books or users.


The format of stduent.txt
Role(0=student, 1=teacher, 2=librarian)  user_name   password

The format of book.txt
ISBN    Title  Author  Category 

The format of copy.txt
ISBN ID
