/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 3                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Tuesday, October 4, 2005                                                    *
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void centerAlign(string line);

int main()
{
    short int startVerse;
    short int endVerse;
    short int spacesNeeded;
    short int spacesPrinted;
    bool programRunning = true;
    string choice;
    short int titleCount;
    short int lineCount;
    const string lyricsStartLineTwo = "My true love gave to me:";
    const string songlyrics[12] = {"And a partidge in a pear tree.",
                                   "Two turtle doves,",
                                   "Three French hens,",
                                   "Four calling birds,",
                                   "Five golden rings,",
                                   "Six geese a laying,",
                                   "Seven swans a swimming,",
                                   "Eight maids a milking,",
                                   "Nine ladies dancing,",
                                   "Ten lords a leaping,",
                                   "Eleven pipers piping,",
                                   "Twelve drummers drumming,"};
    const string lyricsStart[12] = {"On the first day of Christmas",
                                    "On the second day of Christmas",
                                    "On the third day of Christmas",
                                    "On the fourth day of Christmas",
                                    "On the fifth day of Christmas",
                                    "On the sixth day of Christmas",
                                    "On the seventh day of Christmas",
                                    "On the eighth day of Christmas",
                                    "On the ninth day of Christmas",
                                    "On the tenth day of Christmas",
                                    "On the eleventh day of Christmas",
                                    "On the twelfth day of Christmas"};

    while (programRunning == true)
    {
        cout << "What set of verses from \"Twelve Days Of Christmas\""
             << " do you want to see?  ";
        cin >> startVerse >> endVerse;
        if (startVerse <= endVerse && endVerse <= 12 && startVerse >= 1)
        {
            lineCount = endVerse;
            titleCount = endVerse;
            do
            {
                cout << "\n";
                centerAlign(lyricsStart[titleCount - 1]);
                centerAlign(lyricsStartLineTwo);
                titleCount--;

                do
                {
                    centerAlign(songlyrics[lineCount - 1]);
                    lineCount--;
                }
                while (lineCount > 0);

                if (lineCount == 0);
                    lineCount = titleCount;
            }
            while (titleCount >= startVerse);

			cout << "\nWould you like to see another set of verses?  ";
            cin >> choice;
        }
        else if (startVerse > endVerse)
        {
            cout << "Please enter your selection in order.\n" << endl;
            programRunning = true;
        }
        else if (startVerse <= 0 || endVerse <= 0 || startVerse > 12
                 || endVerse > 12)
        {
            cout << "Please choose a number between 1 and 12.\n" << endl;
            programRunning = true;
        }

        if (choice == "no" || choice == "n" || choice == "No" || choice == "N")
        {
            cout << "Goodbye!\n";
            programRunning = false;
        }
        else if (choice == "yes" || choice == "y" || choice == "Yes"
                 || choice == "Y")
        {
            cout << "\n";
            cout << "***********************************************************"
                 << "*********************";
            cout << "\n";
            programRunning = true;
        }
    }

    return 0;
}

void centerAlign(string line)
{
    int spacesNeeded;
    int spacesPrinted;

    spacesNeeded = (80 - line.length()) / 2;
    for(spacesPrinted = 0; spacesPrinted < spacesNeeded; spacesPrinted++)
    {
        cout << " ";
    }
    cout << line << endl;
}
