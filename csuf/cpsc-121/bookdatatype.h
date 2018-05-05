/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 7                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Thursday, December 8, 2005                                                  *
 ******************************************************************************/

#ifndef BOOKDATATYPE_H
#define BOOKDATATYPE_H

#include <iostream>
#include <string>
#include <iomanip>

class BookDataType
{
    public:
        BookDataType();
        void getData(istream& source);
        void updatePrice(float newPrice);
        bool isBookSame(int newIsbn);
        void printDataTitle(ostream& target);
        void printData(ostream& target);
    private:
        int counter;
        string title;
        int noOfAuthors;
        string authorOne, authorTwo, authorThree, authorFour;
        int isbn;
        int year;
        float price;
};

BookDataType::BookDataType()
{
    title = "Lame Computer Book About Java";
    isbn = 187;
    year = 2001;
    price = 76.95;
}

void BookDataType::getData(istream& source)
{
    for (counter = 0; counter < 4; ++counter)
    {
        cout << "Enter the book's title.  ";
        source >> title;
        cout << "Enter the number of authors.  ";
        source >> noOfAuthors;
        switch (noOfAuthors)
        {
            case 1: cout << "Enter the author's name.  ";
                    source >> authorOne;
                    break;
            case 2: cout << "Enter the first author's name.  ";
                    getline(source, '\n') >> authorOne;
                    cout << endl;
                    cout << "Enter the second author's name.  ";
                    getline(source, '\n') >> authorTwo;
                    break;
            case 3: cout << "Enter the first author's name.  ";
                    getline(source, '\n') >> authorOne;
                    cout << endl;
                    cout << "Enter the second author's name.  ";
                    getline(source, '\n') >> authorTwo;
                    cout << endl;
                    cout << "Enter the third author's name.  ";
                    getline(source, '\n') >> authorThree;
                    break;
            case 4: cout << "Enter the first author's name.  ";
                    getline(source, '\n') >> authorOne;
                    cout << endl;
                    cout << "Enter the second author's name.  ";
                    getline(source, '\n') >> authorTwo;
                    cout << endl;
                    cout << "Enter the third author's name.  ";
                    getline(source, '\n') >> authorThree;
                    cout << endl;
                    cout << "Enter the fourth author's name.  ";
                    getline(source, '\n') >> authorFour;
                    break;
        }
        cout << "Enter the ISBN number.  ";
        source >> isbn;
        cout << "Enter the year the book was published.  ";
        source >> year;
        cout << "Enter the price of the book.  ";
        source >> price;
    }
}

void BookDataType::updatePrice(float newPrice)
{
    price = newPrice;
}

bool BookDataType::isBookSame(int newIsbn)
{
    isbn == newIsbn ? return true : return false;
}

void BookDataType::printDataTitle(ostream& target)
{
    int spacesNeeded, spacesPrinted;
    string titleLine = "Inventory For December 2005";

    spacesNeeded = (80 - titleLine.length()) / 2;
    target << endl;
    for(spacesPrinted = 0; spacesPrinted < spacesNeeded; ++spacesPrinted)
        target << " ";
    target << titleLine << endl;
}

void BookDataType::printData(ostream& target)
{
    target << left << setw(50) << "Title" << setfill(".") << right << setw(25)
           << title << endl;
    if (noOfAuthors == 1)
    {
        target << left << setw(57) << "Author" << setfill(".") << right
               << setw(18) << authorOne << endl;
    }
    else if (noOfAuthors == 2)
    {
        target << left << setw(57) << "Authors" << setfill(".") << right
               << setw(18) << authorOne << endl;
        target << right << authorTwo << endl;
    }
    else if (noOfAuthors == 3)
    {
        target << left << setw(57) << "Authors" << setfill(".") << right
               << setw(18) << authorOne << endl;
        target << right << authorTwo << endl << right << authorThree << endl;
    }
    else if (noOfAuthors == 4)
    {
        target << left << setw(57) << "Authors" << setfill(".") << right
               << setw(18) << authorOne << endl;
        target << right << authorTwo << endl << right << authorThree << endl;
        target << right << authorFour << endl;
    }
    target << left << setw(67) << "ISBN" << setfill(".") << right << setw(8)
           << isbn << endl;
    target << left << setw(66) << "Year" << setfill(".") << right << setw(9)
           << year << endl;
    target << left << setw(64) << "Price" << setfill(".") << right << setw(11)
           << "$" << price << endl;
}

#endif
