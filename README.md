# This project reads in a library file and then performs operations on it. 

## Some operations include:
1. finding a book by title
2. displaying all the books
    - only displays 10 books at a time with the title, author, rating and publish year
    - to continue displying the remaining books, user must press anything but "Q" or "q" (it's supposed to be "N", but anything besides "q" or "Q" works)
3. add a book to the waitlist (max number of books on waitlist is 5)
4. display waitlist
   - displays all the books in the waitlist (since it's less than 5, user won't have to worry about pressing "N" or "Q" to continue or quit)

## Another thing to NOTE
The books are stored in an array called m_bookCatalog and it stores Book objects.
Book is an object with, book title, author name, book rating, and year it was published


