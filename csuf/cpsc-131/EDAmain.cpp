////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman
// 800-84-6099
// CPSC-131
// TR 10 - 11:15 am
////////////////////////////////////////////////////////////////////////////////
// Bush 62,028,285; Kerry 59,028,109, Cobb (G) 117,477; Badnarik (L) 396,859
#include <iostream>
#include <vector>
#include <iomanip>
#include "candidate.h"

using std::cout;    using std::cin;     using std::endl;    using std::vector;
using std::left;    using std::fixed;   using std::setprecision;
using std::setw;    using std::right;

int main()
{
    Candidate *ballot;
    int numberOfCandidates;
    int totalNumberOfVotes = 0;
    vector<string> ordinalNumbers;
    int counter;
    int max = 1;

    cout << fixed << setprecision(2);

    ordinalNumbers.push_back("first");
    ordinalNumbers.push_back("second");
    ordinalNumbers.push_back("third");
    ordinalNumbers.push_back("fourth");
    ordinalNumbers.push_back("fifth");
    ordinalNumbers.push_back("sixth");

    cout << "How many candidates are in this election?  ";
    cin >> numberOfCandidates;
    ballot = new Candidate[numberOfCandidates];

    for (counter = 0; counter < numberOfCandidates; ++counter)
    {
        cout << "Enter the " << ordinalNumbers[counter] << " candidate's name"
             << " and the number of votes for the candidate.  ";
        cin >> ballot[counter];
        totalNumberOfVotes += ballot[counter].getNumberOfVotes();
    }
    for (counter = 0; counter < numberOfCandidates; ++counter)
    {
        ballot[counter].setPercentageOfVote((static_cast<float>(ballot[counter].getNumberOfVotes())/static_cast<float>(totalNumberOfVotes)) * 100.0);
        if (ballot[max].getNumberOfVotes() < ballot[counter].getNumberOfVotes())
            max = counter;
    }
    cout << endl;
    cout << setw(20) << left << "Name" << setw(20) << left << "Number of Votes"
         << setw(20) << left << "Percentage of Total Votes" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (counter = 0; counter < numberOfCandidates; ++counter)
        cout << setw(20) << left << ballot[counter].getName() << setw(20)
             << left << ballot[counter].getNumberOfVotes() << setw(20)
             << left << ballot[counter].getPercentageOfVote() << "%" << endl;
    cout << endl;
    cout << "The winner of the election is " << ballot[max].getName() << "." << endl;

    return 0;
}
