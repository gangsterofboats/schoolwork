////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// 800-84-6099                                                                //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "candidate.h"

using std::cout;    using std::cin;     using std::endl;    using std::string;

Candidate::Candidate(string name, int numberOfVotes, float percentageOfVote)
{
    name = "";
    numberOfVotes = 0;
    percentageOfVote = 0.0;
}

bool Candidate::operator<(const Candidate& otherCandidate) const
{
    return (numberOfVotes < otherCandidate.numberOfVotes);
}

bool Candidate::operator>(const Candidate& otherCandidate) const
{
    return (numberOfVotes > otherCandidate.numberOfVotes);
}

ostream& operator<<(ostream& output, const Candidate& testCandidate)
{
    output << testCandidate.name << testCandidate.numberOfVotes;

    return output;
}

istream& operator>>(istream& input, Candidate& currentCandidate)
{
    input >> currentCandidate.name >> currentCandidate.numberOfVotes;

    return input;
}

string Candidate::getName() const
{
    return name;
}

void Candidate::setName(string newName)
{
    name = newName;
}

int Candidate::getNumberOfVotes() const
{
    return numberOfVotes;
}

void Candidate::setNumberOfVotes(int newNumberOfVotes)
{
    numberOfVotes = newNumberOfVotes;
}

float Candidate::getPercentageOfVote() const
{
    return percentageOfVote;
}

void Candidate::setPercentageOfVote(float newPercentageOfVote)
{
    percentageOfVote = newPercentageOfVote;
}
