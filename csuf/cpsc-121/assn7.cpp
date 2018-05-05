/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 7                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Thursday, December 8, 2005                                                  *
 ******************************************************************************/

#include <iostream>
#include <string>
#include "bookdatatype.h"

using namespace std;

int main()
{
    BookDataType inventory[7];
    int isbnNo;
    string choice;
    int index = 0;
    bool testValue;
    float newPrice;

    for(int index = 0; index <= 7; ++index)
        inventory[index].getData(cin);
    inventory[0].printDataTitle(cout);
    for(index = 0; index <= 7; ++index)
        inventory[index].printData(cout);
    cout << "Do you want to change the price of a book?  ";
    cin >> choice;
    if (choice == "Yes" | choice == "yes")
    {
        cout << "Enter the ISBN of the book you want to change.  ";
        cin >> isbnNo;
        do
        {
            testValue = inventory[index].isBookSame(isbnNo);
            ++index;
        } while (!testValue);
        cout << "Enter the new price of the book.  ";
        cin >> newPrice;
        inventory[index - 1].updatePrice(newPrice);
        cout << "Is there another book to be changed?  ";
        cin >> choice;
    }
    else if (choice == "No" | choice == "no")
        ;
    inventory[0].printDataTitle(cout);
    for(index = 0; index <= 7; ++index)
        inventory[index].printData(cout);

    return 0;
}
