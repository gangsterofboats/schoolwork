////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include "booktype.h"

using std::cin;    using std::cout;    using std::endl;    using std::string;
using std::vector;

typedef vector<string>::size_type vectorSize;

BookType::BookType(unsigned int numberOfAuthors = 0, string authorOne = " ", 
                   string authorTwo = " ", string authorThree = " ",
                   string authorFour = " ", string publisher = " ",
                   unsigned int isbn = 0, float price = 0.0,
                   unsigned int amountInStock = 0, bool isAnUpdate = false)
{
    numberOfAuthors = 0;
    authorOne = " ";
    authorTwo = " ";
    authorThree = " ";
    authorFour = " ";
    publisher = " ";
    isbn = 0;
    price = 0.0;
    amountInStock = 0;
    isAnUpdate = false;
}

string BookType::getTitle() const
{
    return title;
}

void BookType::setTitle(string newBookTitle)
{
    title = newBookTitle;
}

int BookType::getNumberOfAuthors() const
{
    return numberOfAuthors;
}

void BookType::setNumberOfAuthors(int newNumberOfAuthors)
{
    numberOfAuthors = newNumberOfAuthors;
}

string BookType::getAuthors()
{
    if (numberOfAuthors == 1)
        return authorOne;
    else if (numberOfAuthors == 2)
        return (authorOne + " " + authorTwo);
    else if (numberOfAuthors == 3)
        return (authorOne + " " + authorTwo + " " + authorThree);
    else if (numberOfAuthors == 4)
        return (authorOne + " " + authorTwo + " " + authorThree + " " + authorFour);
}

void BookType::setAuthors(string newAuthorOne, string newAuthorTwo,
                string newAuthorThree, string newAuthorFour)
{
    authorOne = newAuthorOne;
    authorTwo = newAuthorTwo;
    authorThree = newAuthorThree;
    authorFour = newAuthorFour;
}

string BookType::getPublisher() const
{
    return publisher;
}

void BookType::setPublisher(string newPublisher)
{
    publisher = newPublisher;
}

int BookType::getIsbn() const
{
    return isbn;
}

void BookType::setIsbn(int newIsbn)
{
    isbn = newIsbn;
}

float BookType::getPrice() const
{
    return price;
}

void BookType::setPrice(float newPrice)
{
    price = newPrice;
}

unsigned int BookType::getAmountInStock() const
{
    return amountInStock;
}

void BookType::setAmountInStock(unsigned int newAmountInStock, bool isAnUpdate)
{
    if (!isAnUpdate)
        amountInStock = newAmountInStock;
    else
        --amountInStock;
}
