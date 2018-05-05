////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// 800-84-6099                                                                //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <string>

using std::string;      using std::ostream;     using std::istream;

class Candidate
{
    friend ostream& operator<<(ostream& output, const Candidate& testCandidate);
    friend istream& operator>>(istream& input, Candidate& currentCandidate);
    public:
        Candidate(string name="", int numberOfVotes = 0, float percentageOfVote = 0.0);
        bool operator<(const Candidate& otherCandidate) const;
        bool operator>(const Candidate& otherCandidate) const;
        string getName() const;
        void setName(string newName);
        int getNumberOfVotes() const;
        void setNumberOfVotes(int newNumberOfVotes);
        float getPercentageOfVote() const;
        void setPercentageOfVote(float newPercentageOfVote);
    private:
        string name;
        int numberOfVotes;
        float percentageOfVote;
};
#endif
