/*
    Author: Romain Dzeinse
    Released Date: 9/26/24 
    Today's Date: 9/26/24
    Due Date: 10/10/24 at 8:59pm
    Points Worth: 80
    Objective: Design a system that navigates the the UMBC library and allows for book accessing and adding
    Project Name: UMBC Library
*/

#include "Library.h"
#include "Book.h"
#include <istream>


void Library::LoadCatalog(string filename){
    ifstream inputStream;
    string theLine, year, title, author, score;
    inputStream.open(filename);    // opens the file
    
    while(inputStream.is_open()){    // while the 
        for(int i=0; i<NUM_BOOKS; i++){
            // we first need to put all the values in their appropriate variables
            // we're storing the year first, DELIMETER then the title, DELIMETER
            // then the author(s), DELIMETER and then the rating
            getline(inputStream, year, DELIMETER);
            getline(inputStream, title, DELIMETER);
            getline(inputStream, author, DELIMETER);
            getline(inputStream, score);
            // Now we want populate the book with these variables, not forgetting to 
            // cast the appropraite variables to their appropriate value types
            m_bookCatalog[i].SetYear(stoi(year));
            m_bookCatalog[i].SetTitle(title);
            m_bookCatalog[i].SetAuthor(author);
            m_bookCatalog[i].SetScore(stod(score));
        }
	inputStream.close();   // now we close out file
    }
}

Library::Library(){
    m_waitCount = 0;
}

Library::Library(string filename){
    LoadCatalog(filename);
    m_waitCount = 0;
}

void Library::MainMenu(){
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Books " << endl;
    cout << "2. Search Catalog for Book Title " << endl; 
    cout << "3. Add Book to Waitlist " << endl; 
    cout << "4. Display Waitlist " << endl; 
    cout << "5. Quit " << endl; 
    int choice;
    cout << ">>> ";
    cin >> choice;
    int countForAddingBook = 0;
    while(choice != 5){
        switch (choice){
            case 1:
                DisplayBooks();    // we display the books
		        cout << endl;
                break;
            case 2:
                SearchCatalog();   // search the catalog
		        cout << endl;
                break;
            case 3:
                if(countForAddingBook < 5){   // if the user types in 3 more than 5 times stop them from being able to do it again
                    AddBook();
                }
                else{
                    cout << "\033[31mMaximum number of books on waitlist\033[0m" << endl;
                }
                countForAddingBook++;
		        cout << endl;
                break;
            case 4:
                DisplayWaitList();   // we display the waitlist and then exit if they type in 5
		        cout << endl;
                break;
        }
        cout << "What would you like to do?" << endl;
        cout << "1. Display All Books " << endl;
        cout << "2. Search Catalog for Book Title " << endl; 
        cout << "3. Add Book to Waitlist " << endl; 
        cout << "4. Display Waitlist " << endl; 
        cout << "5. Quit " << endl; 
        cout << ">>> ";
        cin >> choice;
    }
    cout << endl << "\033[31mProgram has been exited\033[0m" << endl;
    cout << "Thank you for using the UMBC Library" << endl;

}

void Library::DisplayBooks(){
    Book myBook;   // create a new book and later populate it with the values of the catalog in the for loop
    cout << "\033[31m**********DISPLAYING BOOKS**********\033[0m" << endl;
    string quit;
    int counter = 0;
    
    
    while(quit != "Q" && quit != "q"){
      for(int i=0; i<INCR; i++){
        myBook = m_bookCatalog[counter];     // we populate every value in the
        // book from defaults and 0s to the values from catalog
        cout << counter+1 << ": \033[32m";
        myBook.DisplayBook();    // then we display it  
        cout << "\033[0m";
        ++counter;
      }
      cout << "Type N for next and Q to quit" << endl;   // we ask again until the user enters q or Q for quit
      cout << ">>> ";
      cin >> quit;   // then we take in the value
      cout << endl;
    }
    cout << "\033[31m**********DONE DISPLAYING BOOKS**********\033[0m" << endl;   // formatting
}

void Library::SearchCatalog(){
    // this is the word that the user will enter
    string searchWord;
    cout << "What title would you like to search for?" << endl;
    cout << ">>> ";
    // We ask the user for that value
    cin >> searchWord;
    cout << "\033[31m**********DISPLAYING ALL RELATED BOOKS**********\033[0m" << endl;
    int myCount = 0;
    // Then we iterate through the catalog and cout every title that has that word in it
    for(int i=0; i<NUM_BOOKS; i++){
        if((int)m_bookCatalog[i].GetTitle().find(searchWord) != -1){    // checks all the titles that have the word in them
	        cout << "\033[32m" << m_bookCatalog[i].GetTitle() << "\033[0m" << endl;
	        ++myCount;    // we increment the count for this to make sure the if statement below works correctly
        }
    }
    cout << "\033[31m**********DONE DISPLAYING RELATED BOOKS**********\033[0m" << endl;   // formatting
    // if the myCount is zero, we say no books found
    if(myCount == 0){
      cout << "\033[31mNo books with that title found.\033[0m" << endl;
    }
}

void Library::AddBook(){

    int toAdd;
    cout << "Which book would you like to add? (-1 for list)" << endl;
    cout << ">>> ";
    cin >> toAdd;
    // here I check if it's -1 so I can later display it in here
    while((toAdd == -1) || (toAdd < 0 || toAdd > NUM_BOOKS)){
      if(toAdd == -1){
	    DisplayBooks();    // I display it here
      }
      else if((toAdd < 0 || toAdd > NUM_BOOKS) && (toAdd != -1)){
	    cout << "\033[31mInvalid Number\033[0m" << endl;    // I print invalid number if the number is not correct, per the documentation
      }
      cout << "Which book would you like to add? (-1 for list)" << endl;
      cout << ">>> ";   // then we ask again
      cin >> toAdd;
    }

    if(BookExist(m_bookCatalog[toAdd-1])) {
      cout << "\033[33mBook already exists in waitlist\033[0m" << endl;     // If the book already exists, we let the user know
    }
    // if it doesn't already exist we add it and then add value of m_waitcount so we can later iterate 
    // through it in the DIsplay Waitlist function below
    else if(toAdd != -1 && !BookExist(m_bookCatalog[toAdd-1])){
        m_waitList[m_waitCount] = m_bookCatalog[toAdd-1];
        ++m_waitCount;
    }
}
bool Library::BookExist(Book book){
    // This function checks if the value is valid or not by checking for the title, author, year and the score
    // returning true if it finds a match of all 4 and false if it doesn't find a match of either in the size 
    // of the waitlist
  for(int i=0; i<MAX_WAIT; i++){
      if(book.GetTitle() == m_waitList[i].GetTitle() && book.GetAuthor() == m_waitList[i].GetAuthor() && book.GetYear() == m_waitList[i].GetYear() && book.GetScore() == m_waitList[i].GetScore()){
            return true;
        }
    }
    return false;
}
void Library::DisplayWaitList(){
    // this function displays the waitliat based on the value of waitcount
    cout << "\033[31m**********DISPLAYING WAITLIST**********\033[0m" << endl;
    for(int i=0; i<m_waitCount; i++){
      cout << "\033[32m";
      m_waitList[i].DisplayBook();
      cout << "\033[0m";
    }
    // if the size is 0, then the waitlist is empty and therefore nothing outputs but this statement below
    if(m_waitCount == 0){
      cout << "There's nothing in the waitlist" << endl;
    }
    // this line below is just for formatting
    cout << "\033[31m**********DONE DISPLAYING WAITLIST**********\033[0m" << endl;
}
