////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <vector>
#include <string>

using std::string;

class BookType
{
    public:
        BookType(unsigned int numberOfAuthors = 0, string authorOne = " ", 
                 string authorTwo = " ", string authorThree = " ",
                 string authorFour = " ", string publisher = " ",
                 unsigned int isbn = 0, float price = 0.0,
                 unsigned int amountInStock = 0, bool isAnUpdate = false);
        string getTitle() const;
        void setTitle(string newTitle);
        unsigned int getNumberOfAuthors() const;
        void setNumberOfAuthors(int newNumberOfAuthors);
        string getAuthors() const;
        void setAuthors(string newAuthorOne, string newAuthorTwo,
                        string newAuthorThree, string newAuthorFour);
        string getPublisher() const;
        void setPublisher(string newPublisher);
        int getIsbn() const;
        void setIsbn(int newIsbn);
        float getPrice() const;
        void setPrice(float newPrice);
        unsigned int getAmountInStock() const;
        void setAmountInStock(unsigned int newAmountInStock, bool isAnUpdate);
    private:
        string title;
        unsigned int numberOfAuthors;
        string authorOne;
        string authorTwo; 
        string authorThree; 
        string authorFour;
        string publisher;
        unsigned int isbn;
        float price;
        unsigned int amountInStock;
        bool isAnUpdate;
};
#endif
