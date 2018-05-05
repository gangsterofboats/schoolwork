////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// 800-84-6099                                                                //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "expression.h"

using std::cout;    using std::cin;     using std::endl;    using std::string;

int main()
{
    Expression formula;
    string input;

    cout << "What is the expression?  ";
    cin >> input;
    cout << endl;
    formula.setInfix(input);
    formula.setPostfix();
    cout << "Infix Expression: " << formula.getInfix() << endl;
    cout << "Postfix Expression: " << formula.getPostfix() << endl;

    return 0;
}
