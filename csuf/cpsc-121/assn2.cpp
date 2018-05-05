/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 2                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Tuesday, September 20, 2005                                                 *
 ******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void main()
{
    struct data
    {
        string name;
        int idno;
        float avalue;
        float rate;
        float tamount;
        float ptax;
    };
    data hollingsworth;
    data stormer;
    data allworth;
    data ziggler;
    data anderson;
    data jenkins;
    bool programRunning = true;
    string testname;
    string choice;
    void title();
    
    cout << fixed << showpoint;

    while (programRunning == true)
    {
        cout << "About whom is the data to be entered?  ";
        cin >> testname;
        if (testname == "Hollingsworth")
        {
            cout << "What is the data?  ";
            cin >> hollingsworth.name >> hollingsworth.idno 
                >> hollingsworth.avalue >> hollingsworth.rate;
            hollingsworth.tamount = hollingsworth.avalue * 0.92;
            hollingsworth.ptax = hollingsworth.tamount * hollingsworth.rate
               / 100;
            title();
            cout << left << setw(66) << "Property owner" << right << setw(13)
                 << hollingsworth.name << endl;
            cout << left << setw(72) << "Property identification no." << right
                 << setw(7) << hollingsworth.idno << endl;
            cout << left << setw(70) << "Assessed value" << right << setw(8)
                 << setprecision(2) << hollingsworth.avalue << endl;
            cout << left << setw(70) << "Taxable amount" << right << setw(8)
                 << setprecision(2) << hollingsworth.tamount << endl;
            cout << left << setw(75) << "Tax rate per $100" << right << setw(3)
                 << setprecision(2) << hollingsworth.rate << endl;
            cout << left << setw(71) << "Property tax" << right << setw(8)
                 << setprecision(2) << hollingsworth.ptax << endl;
            cout << "\nIs there more data to be entered?  ";
            cin >> choice;
        }
        else if (testname == "Stormer")
        {
            cout << "What is the data?  ";
            cin >> stormer.name >> stormer.idno 
                >> stormer.avalue >> stormer.rate;
            stormer.tamount = stormer.avalue * 0.92;
            stormer.ptax = stormer.tamount * stormer.rate / 100;
            title();
            cout << left << setw(72) << "Property owner" << right << setw(7)
                 << stormer.name << endl;
            cout << left << setw(71) << "Property identification no." << right
                 << setw(8) << stormer.idno << endl;
            cout << left << setw(70) << "Assessed value" << right << setw(8)
                 << setprecision(2) << stormer.avalue << endl;
            cout << left << setw(70) << "Taxable amount" << right << setw(8)
                 << setprecision(2) << stormer.tamount << endl;
            cout << left << setw(75) << "Tax rate per $100" << right << setw(3)
                 << setprecision(2) << stormer.rate << endl;
            cout << left << setw(72) << "Property tax" << right << setw(6)
                 << setprecision(2) << stormer.ptax << endl;
            cout << "\nIs there more data to be entered?  ";
            cin >> choice;
        }
        else if (testname == "Allworth")
        {
            cout << "What is the data?  ";
            cin >> allworth.name >> allworth.idno 
                >> allworth.avalue >> allworth.rate;
            allworth.tamount = allworth.avalue * 0.92;
            allworth.ptax = allworth.tamount * allworth.rate / 100;
            title();
            cout << left << setw(71) << "Property owner" << right << setw(8)
                 << allworth.name << endl;
            cout << left << setw(72) << "Property identification no." << right
                 << setw(7) << allworth.idno << endl;
            cout << left << setw(69) << "Assessed value" << right << setw(8)
                 << setprecision(2) << allworth.avalue << endl;
            cout << left << setw(70) << "Taxable amount" << right << setw(8)
                 << setprecision(2) << allworth.tamount << endl;
            cout << left << setw(75) << "Tax rate per $100" << right << setw(3)
                 << setprecision(2) << allworth.rate << endl;
            cout << left << setw(71) << "Property tax" << right << setw(8)
                 << setprecision(2) << allworth.ptax << endl;
            cout << "\nIs there more data to be entered?  ";
            cin >> choice;
        }
        else if (testname == "Ziggler")
        {
            cout << "What is the data?  ";
            cin >> ziggler.name >> ziggler.idno 
                >> ziggler.avalue >> ziggler.rate;
            ziggler.tamount = ziggler.avalue * 0.92;
            ziggler.ptax = ziggler.tamount * ziggler.rate / 100;
            title();
            cout << left << setw(72) << "Property owner" << right << setw(7)
                 << ziggler.name << endl;
            cout << left << setw(72) << "Property identification no." << right
                 << setw(7) << ziggler.idno << endl;
            cout << left << setw(70) << "Assessed value" << right << setw(8)
                 << setprecision(2) << ziggler.avalue << endl;
            cout << left << setw(70) << "Taxable amount" << right << setw(8)
                 << setprecision(2) << ziggler.tamount << endl;
            cout << left << setw(75) << "Tax rate per $100" << right << setw(3)
                 << setprecision(2) << ziggler.rate << endl;
            cout << left << setw(71) << "Property tax" << right << setw(8)
                 << setprecision(2) << ziggler.ptax << endl;
            cout << "\nIs there more data to be entered?  ";
            cin >> choice;
        }
        else if (testname == "Anderson")
        {
            cout << "What is the data?  ";
            cin >> anderson.name >> anderson.idno 
                >> anderson.avalue >> anderson.rate;
            anderson.tamount = anderson.avalue * 0.92;
            anderson.ptax = anderson.tamount * anderson.rate / 100;
            title();
            cout << left << setw(71) << "Property owner" << right << setw(7)
                 << anderson.name << endl;
            cout << left << setw(72) << "Property identification no." << right
                 << setw(7) << anderson.idno << endl;
            cout << left << setw(69) << "Assessed value" << right << setw(8)
                 << setprecision(2) << anderson.avalue << endl;
            cout << left << setw(69) << "Taxable amount" << right << setw(8)
                 << setprecision(2) << anderson.tamount << endl;
            cout << left << setw(75) << "Tax rate per $100" << right << setw(3)
                 << setprecision(2) << anderson.rate << endl;
            cout << left << setw(71) << "Property tax" << right << setw(8)
                 << setprecision(2) << anderson.ptax << endl;
            cout << "\nIs there more data to be entered?  ";
            cin >> choice;
        }
        else if (testname == "Jenkins")
        {
            cout << "What is the data?  ";
            cin >> jenkins.name >> jenkins.idno 
                >> jenkins.avalue >> jenkins.rate;
            jenkins.tamount = jenkins.avalue * 0.92;
            jenkins.ptax = jenkins.tamount * jenkins.rate / 100;
            title();
            cout << left << setw(72) << "Property owner" << right << setw(7)
                 << jenkins.name << endl;
            cout << left << setw(72) << "Property identification no." << right
                 << setw(7) << jenkins.idno << endl;
            cout << left << setw(70) << "Assessed value" << right << setw(8)
                 << setprecision(2) << jenkins.avalue << endl;
            cout << left << setw(70) << "Taxable amount" << right << setw(8)
                 << setprecision(2) << jenkins.tamount << endl;
            cout << left << setw(75) << "Tax rate per $100" << right << setw(3)
                 << setprecision(2) << jenkins.rate << endl;
            cout << left << setw(71) << "Property tax" << right << setw(8)
                 << setprecision(2) << jenkins.ptax << endl;
            cout << "\nIs there more data to be entered?  ";
            cin >> choice;
        }
        if (choice == "no" || choice == "n" || choice == "No" || choice == "N")
        {
            cout << "Have a nice day.\n";
            programRunning = false;
        }
        else if (choice == "yes" || choice == "y" || choice == "Yes"
                 || choice == "Y")
        {
            cout << "\n";
            cout << "**********************************************************"
                 << "**********************";
            cout << "\n";
            programRunning = true;
        }
    }
}

void title()
{
    short int spacesNeeded;
    short int spacesPrinted;
    string titleLine1 = "Office of the O.C. Tax Assessor";
    string titleLine2 = "Tuesday, September 20, 2005";

    spacesNeeded = (80 - titleLine1.length()) / 2;
    
    cout << "\n";
    for(spacesPrinted = 0; spacesPrinted < spacesNeeded; spacesPrinted++)
    {
        cout << " ";
    }
    cout << titleLine1 << endl;

    spacesNeeded = (80 - titleLine2.length()) / 2;
    for(spacesPrinted = 0; spacesPrinted < spacesNeeded; spacesPrinted++)
    {
        cout << " ";
    }
    cout << titleLine2 << "\n" << endl;
}
