#include <iostream>
#include <list>
#include <cstdlib>

using std::cin;     using std::cout;    using std::endl;    using std::list;

typedef list<int>::iterator iterator;

void getSmallestNumber(list<int>& inputList, iterator& min);
void selectionSort(list<int>& inputList, list<int>& outputList);

int main()
{
    list<int> unsortedNumbers, sortedNumbers;
    iterator current;

    for (int counter = 1; counter <= 10; ++counter)
        unsortedNumbers.push_back(rand());
    cout << "Unsorted List: ";
    for (current = unsortedNumbers.begin(); current != unsortedNumbers.end(); ++current)
        cout << *current << " ";
    cout << endl;
    selectionSort(unsortedNumbers, sortedNumbers);
    cout << "Sorted List: ";
    for (current = sortedNumbers.begin(); current != sortedNumbers.end(); ++current)
        cout << *current << " ";
    cout << endl;
    
    return 0;
}

void getSmallestNumber(list<int>& inputList, iterator& min)
{
    iterator current;
    min = inputList.begin();

    for (current = inputList.begin(); current != inputList.end(); ++current)
        if (*current < *min)
            min = current;
}

void selectionSort(list<int>& inputList, list<int>& outputList)
{
    iterator min;

    while (!inputList.empty())
    {
        getSmallestNumber(inputList, min);
        outputList.push_back(*min);
        inputList.remove(*min);
    }
}
