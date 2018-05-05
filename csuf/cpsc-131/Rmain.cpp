////////////////////////////////////////////////////////////////////////////////
// Michael Wiseman                                                            //
// 800-84-6099                                                                //
// CPSC-131                                                                   //
// TR 10 - 11:15 am                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;    using std::cin;     using std::endl;    using std::vector;

int randomNumber(int maxNumber);
vector<int> reversedList(vector<int> inputList, int begin, int end);

int main()
{
    vector<int> list;
    int number;

    for (int counter = 1; counter <= 6; ++counter)
        list.push_back(randomNumber(100));
    cout << "Initial list: ";
    for (int counter = 0; counter <= 5; ++counter)
        cout << list[counter] << " ";
    list = reversedList(list, list.begin(), list.end());
    cout << "Reversed list: ";
    for (int counter = 0; counter <= 5; ++counter)
        cout << list[counter] << " ";

    return 0;
}

int randomNumber(int maxNumber)
{
    RAND_MAX = maxNumber;

    return rand();
}

vector<int> reversedList(vector<int> inputList, int begin, int end)
{
    int tempOne, tempTwo;
    vector<int> outputList;

    if (begin == end)
        return inputList;
    else
        outputList = reversedList(inputList, begin + 1, end + 1);

    return inputList;
}
