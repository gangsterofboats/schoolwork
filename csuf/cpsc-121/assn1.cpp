/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 1                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Tuesday, September 6, 2005                                                  *
 ******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void main()
{
    float ctemp;
    float ftemp;
    string scale;
    string choice;
    bool programRunning = true;
    // C = 5/9 (F - 32); F = 9/5 C + 32

    cout << fixed;
    cout << "Hello, there!" << endl;
    while (programRunning == true)
    {
        cout << "What is the temperature scale you want to convert from?  ";
        cin >> scale;
        if (scale == "Celsius")
        {
            cout << "What is the temperature?  ";
            cin >> ctemp;
            ftemp = 9.0 / 5.0 * ctemp + 32.0;
            cout << "The temperature in Fahrenheit is " << setprecision(2) << ftemp << " Degrees." << endl;
            cout << "Would you like to convert another temperature?  ";
            cin >> choice;
        }
        else if (scale == "Fahrenheit")
        {
            cout << "What is the temperature?  ";
            cin >> ftemp;
            ctemp = 5.0 / 9.0 * ( ftemp - 32.0 );
            cout << "The temperature in Celsius is " << setprecision(2) << ctemp << " Degrees." << endl;
            cout << "Would you like to convert another temperature?  ";
            cin >> choice;
        }
        else
        {
            cout << "YOU'RE IDIOT!" << endl;
            cout << "YOUR FIRED!" << endl;
            programRunning = false;
        }
        if (choice == "no" || choice == "n" || choice == "No" || choice == "N")
        {
            cout << "Goodbye!\n";
            programRunning = false;
        }
        else if (choice == "yes" || choice == "y" || choice == "Yes" || choice == "Y")
        {
            cout << "\n";
            cout << "-----------------------------------------------------------"
                 << "---------------------";
            cout << "\n";
            programRunning = true;
        }
    }
}
