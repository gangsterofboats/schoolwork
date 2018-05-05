////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// 800-84-6099                                                                //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include "expression.h"

using std::cout;    using std::cin;     using std::endl;    using std::string;
using std::map;     using std::stack;

Expression::Expression()
{
    infx = "";
    pfx = "";
}

Expression::~Expression()
{

}

void Expression::setInfix(string infix)
{
    infx = infix;
}

string Expression::getInfix()
{
    return infx;
}

void Expression::setPostfix()
{
    stack<char> operators;
    string ops = "+-*/()";

    for (unsigned int counter = 0; counter < infx.length(); ++counter)
    {
        switch (infx[counter])
        {
        case '(': operators.push(infx[counter]);
                  break;
        case ')': while (operators.top() != ops[4])
				  {
                      pfx += operators.top();
                      operators.pop();
                  }
                  operators.pop();
                  break;
        case '+':
        case '-':
        case '*':
        case '/': while (operators.empty() != true && operators.top() != ops[4]
                         && precedence(operators.top(), infx[counter]))
                  {
                      pfx += operators.top();
                      operators.pop();
                  }
                  operators.push(infx[counter]);
                  break;
        default: pfx += infx[counter];
                 break;
        }
    }
    while (operators.empty() != true)
    {
        pfx += operators.top();
        operators.pop();
    }
}

string Expression::getPostfix()
{
    return pfx;
}

bool Expression::precedence(char firstOperator, char secondOperator)
{
    map<char,int> opPrecedence;
    map<char,int>::iterator currentOne;
    map<char,int>::iterator currentTwo;

    opPrecedence['+'] = 0;
    opPrecedence['-'] = 0;
    opPrecedence['*'] = 1;
    opPrecedence['/'] = 1;
    currentOne = opPrecedence.begin();
    currentTwo = opPrecedence.begin();

    while (currentOne->first != firstOperator && currentTwo->first != secondOperator)
    {
        ++currentOne;
        ++currentTwo;
    }

    if (currentOne->second >= currentTwo->second)
        return true;
    else
        return false;
}
