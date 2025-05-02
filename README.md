# This project reads in a library file and then performs operations on it. 

## Some operations include:
1. _finding a book by title_
2. _displaying all the books_
    - only displays 10 books at a time with the title, author, rating and publish year
    - to continue displying the remaining books, user must press anything but "Q" or "q" (it's supposed to be "N", but anything besides "q" or "Q" works)
3. _add a book to the waitlist (max number of books on waitlist is 5)_
4. _display waitlist_
   - displays all the books in the waitlist (since it's less than 5, user won't have to worry about pressing "N" or "Q" to continue or quit)

## Another thing to note
The books are stored in an array called m_bookCatalog and it stores Book objects.
Book is an object with, book title, author name, book rating, and year it was published


