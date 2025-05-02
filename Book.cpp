/*
    Author: Romain Dzeinse
    Released Date: 9/26/24 
    Today's Date: 9/26/24
    Due Date: 10/10/24 at 8:59pm
    Points Worth: 80
    Objective: Design a system that navigates the the UMBC library and allows for book accessing and adding
    Project Name: UMBC Library
*/

#include "Book.h"
#include <string>

using namespace std; 

Book::Book(){
    SetYear(0);
    SetTitle("default");
    SetAuthor("default");
    SetScore(0.00);
}

Book::Book(int year, string title, string author, double score){
    SetYear(year);
    SetTitle(title);
    SetAuthor(author);
    SetScore(score);
}

int Book::GetYear(){
    return m_year;
}
string Book::GetTitle(){
    return m_title;
}
string Book::GetAuthor(){
    return m_author;
}
double Book::GetScore(){
    return m_score;
}

void Book::SetYear(int year){
    m_year = year;
}
void Book::SetTitle(string title){
    m_title = title;
}
void Book::SetAuthor(string author){
    m_author = author;
}
void Book::SetScore(double score){
    m_score = score;
}

void Book::DisplayBook(){
    cout << GetTitle() << " (" << GetYear() << ") by " + GetAuthor() << " with a score of " << GetScore() << endl;
}