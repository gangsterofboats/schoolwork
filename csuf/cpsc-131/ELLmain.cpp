////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman
// 800-84-6099
// CPSC-131
// TR 10 - 11:15 am
////////////////////////////////////////////////////////////////////////////////
// Bush 62,028,285; Kerry 59,028,109, Cobb (G) 117,477; Badnarik (L) 396,859
#include <iostream>
#include <iomanip>
#include <list>
#include "candidate.h"

using std::cout;    using std::cin;     using std::endl;
using std::left;    using std::fixed;   using std::setprecision;
using std::setw;    using std::right;   using std::list;

typedef list<Candidate>::iterator iterator;

int main()
{
    list<Candidate> ballot;
    Candidate temp;
    iterator current;
    int totalNumberOfVotes = 0;

    cout << fixed << setprecision(2);

    cout << "Type \"End 0\" when finished.\n\n";
    do
    {
        cout << "Enter the candidate's name and the number of votes for the candidate.  ";
        cin >> temp;
        ballot.push_front(temp);
        current = ballot.begin();
        totalNumberOfVotes += current->getNumberOfVotes();
    }
    while (temp.getName() != "End"  && temp.getNumberOfVotes() != 0);
    for (current = ballot.begin(); current != NULL; ++current)
        current->setPercentageOfVote((static_cast<float>(current->getNumberOfVotes())/static_cast<float>(totalNumberOfVotes)) * 100.0);
    ballot.sort();
    cout << endl;
    cout << setw(20) << left << "Name" << setw(20) << left << "Number of Votes"
         << setw(20) << left << "Percentage of Total Votes" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (current = ballot.begin(); current != NULL; ++current)
        cout << setw(20) << left << current->getName() << setw(20)
             << left << current->getNumberOfVotes() << setw(20)
             << left << current->getPercentageOfVote() << "%" << endl;
    cout << endl;
    current = ballot.end();
    cout << "The winner of the election is " << current->getName() << "." << endl;

    return 0;
}
