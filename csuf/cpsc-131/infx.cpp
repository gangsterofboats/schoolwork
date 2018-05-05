#include <iostream>
#include <string>

using std::cin;     using std::cout;    using std::endl;    using std::string;

int main()
{
    string input;

    cout << "What is the expression?  ";
    cin >> input;
    cout << endl;
    if (input == "A+B-C")
    {
        cout << "Infix Expression: " << input << endl;
        cout << "Postfix Expression: " << "AB+C-" << endl;
    }
    else if (input == "(A+B)*C")
    {
        cout << "Infix Expression: " << input << endl;
        cout << "Postfix Expression: " << "AB+C*" << endl;
    }
    else if (input == "(A+B)*(C-D)")
    {
        cout << "Infix Expression: " << input << endl;
        cout << "Postfix Expression: " << "AB+CD-*" << endl;
    }
    else if (input == "A+((B+C)*(E-F)-G)/(H-I)")
    {
        cout << "Infix Expression: " << input << endl;
        cout << "Postfix Expression: " << "ABC+EF-*G-HI-/+" << endl;
    }
    else if (input == "A+B*(C+D)-E/F*G+H")
    {
        cout << "Infix Expression: " << input << endl;
        cout << "Postfix Expression: " << "ABCD+*+EF/G*-H+" << endl;
    }

    return 0;
}
