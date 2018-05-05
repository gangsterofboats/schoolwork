////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include "booktype.h"

using std::cin;    using std::cout;    using std::endl;    using std::string;
using std::vector;

int main()
{
    int itemInInventory;
    vector<BookType> storeInventory(itemInInventory);
    string newTitle;
    unsigned int newNumberOfAuthors;
    string newAuthorOne;
    string newAuthorTwo;
    string newAuthorThree;
    string newAuthorFour;
    string newPublisher;
    unsigned int newIsbn;
    float newPrice;
    unsigned int newAmountInStock;
    bool isThisAnUpdate;


    for (itemInInventory = 0; itemInInventory <= storeInventory.size();
         ++itemInInventory);
    {
        cout << "What is the book title?  ";
        getline(cin, newTitle);
        storeInventory[itemInInventory].setTitle(newTitle);
        cout << "How many authors are there?  ";
        cin >> newNumberOfAuthors;
        if (newNumberOfAuthors == 1)
        {
            cout << "What is the author's name?  ";
            getline(cin, newAuthorOne);
            storeInventory[itemInInventory].setAuthors(newAuthorOne, " ", " ", " ");
        }
        else if (newNumberOfAuthors == 2)
        {
            cout << "What is the first author's name?  ";
            getline(cin, newAuthorOne);
            cout << "What is the second author's name?  ";
            getline(cin, newAuthorTwo);
            storeInventory[itemInInventory].setAuthors(newAuthorOne,
                                                         newAuthorTwo, " ", " ");
        }
        else if (newNumberOfAuthors == 3)
        {
            cout << "What is the first author's name?  ";
            getline(cin, newAuthorOne);
            cout << "What is the second author's name?  ";
            getline(cin, newAuthorTwo);
            cout << "What is the third author's name?  ";
            getline(cin, newAuthorThree);
            storeInventory[itemInInventory].setAuthors(newAuthorOne,
                                                         newAuthorTwo,
                                                         newAuthorThree, " ");
        }
        else if (newNumberOfAuthors == 4)
        {
            cout << "What is the first author's name?  ";
            getline(cin, newAuthorOne);
            cout << "What is the second author's name?  ";
            getline(cin, newAuthorTwo);
            cout << "What is the third author's name?  ";
            getline(cin, newAuthorThree);
            cout << "What is the fourth author's name?  ";
            getline(cin, newAuthorFour);
            storeInventory[itemInInventory].setAuthors(newAuthorOne,
                                                         newAuthorTwo,
                                                         newAuthorThree,
                                                         newAuthorFour);
        }
        cout << "What is the publisher's name?  ";
        getline(cin, newPublisher);
        storeInventory[itemInInventory].setPublisher(newPublisher);
        cout << "What is the ISBN?  ";
        cin >> newIsbn;
        storeInventory[itemInInventory].setIsbn(newIsbn);
        cout << "What is the price?  ";
        cin >> newPrice;
        storeInventory[itemInInventory].setPrice(newPrice);
        cout << "How many are in stock?  ";
        cin >> newAmountInStock;
        isThisAnUpdate = false;
        storeInventory[itemInInventory].setAmountInStock(newAmountInStock,
                                                           isThisAnUpdate);
    }

    return 0;
}
