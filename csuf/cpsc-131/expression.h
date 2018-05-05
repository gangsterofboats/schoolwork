#ifndef EXPRESSION_H
#define EXPRESSION_H
////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// 800-84-6099                                                                //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <string>

using std::string;

class Expression
{
    public:
        Expression();
        ~Expression();
        void setInfix(string infix);
        string getInfix();
        void setPostfix();
        string getPostfix();
        bool precedence(char firstOperator, char secondOperator);
    private:
        string infx;
        string pfx;
};
#endif