/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 6                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Thursday, November 17, 2005                                                 *
 ******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void getTemperatureData(int data[12][3]);
int warmHighTemp(int list[12][3], int lowerIndex, int upperIndex);
int warmLowTemp(int list[12][3], int lowerIndex, int upperIndex);
int coolHighTemp(int list[12][3], int lowerIndex, int upperIndex);
int coolLowTemp(int list[12][3], int lowerIndex, int upperIndex);
void outputDataHead(int year);
void outputData(string dataNameList[], int dataList[12][3], int arraySize);
void outputaverage(int dataList[12][3], int arraysize);
void outputWarmestHighMonth(string month, int warmestHighTemp);
void outputWarmestLowMonth(string month, int warmestLowTemp);
void outputCoolestHighMonth(string month, int coolestHighTemp);
void outputCoolestLowMonth(string month, int coolestLowTemp);

int main()
{
    int temperatureData[12][3];
    string months[12] = {"January", "February", "March", "April", "May", 
                         "June", "July", "August", "September", "October",
                         "November", "December"};
    int startArray = 0;
    int endArray = 11;
    int year;
    int sizeOfArray = 12;
    int warmestHighTemp, warmestLowTemp, coolestHighTemp, coolestLowTemp;
    int warmHighMonth, warmLowMonth, coolHighMonth, coolLowMonth;
    
    getTemperatureData(temperatureData);
    warmestHighTemp = warmHighTemp(temperatureData, startArray, endArray);
    warmestLowTemp = warmLowTemp(temperatureData, startArray, endArray);
    coolestHighTemp = coolHighTemp(temperatureData, startArray, endArray);
    coolestLowTemp = coolLowTemp(temperatureData, startArray, endArray);
    outputDataHead(year);
    outputData(months, temperatureData, sizeOfArray);
    outputaverage(temperatureData, sizeOfArray);
    outputWarmestHighMonth(months[warmHighMonth], warmestHighTemp);
    outputWarmestLowMonth(months[warmLowMonth], warmestLowTemp);
    outputCoolestHighMonth(months[coolHighMonth], coolestHighTemp);
    outputCoolestLowMonth(months[coolLowMonth], coolestLowTemp);

    return 0;
}

void getTemperatureData(int data[12][3])
{
    int month;
    int year;
    int lowTemp;
    int highTemp;

    cout << "Please enter the year for the data.  ";
    cin >> year;
    cout << endl;
    cout << "Please enter the data.  ";
    for (int i = 0; i <= 12; i++)
    {
        cin >> month >> highTemp >> lowTemp;
        data[month - 1][0] = month;
        data[month - 1][1] = highTemp;
        data[month - 1][2] = lowTemp;
    }
} 

int warmHighTemp(int list[12][3], int lowerIndex, int upperIndex)
{
    int max;

    if (lowerIndex == upperIndex)
        return list[lowerIndex][1];
    else
    {
        max = warmHighTemp(list, lowerIndex + 1, upperIndex);
        if (list[lowerIndex][1] >= max)
            return list[lowerIndex][1];
        else
            return max;
    }
}

int warmLowTemp(int list[12][3], int lowerIndex, int upperIndex)
{
    int max;

    if (lowerIndex == upperIndex)
        return list[lowerIndex][2];
    else
    {
        max = warmLowTemp(list, lowerIndex + 1, upperIndex);
        if (list[lowerIndex][2] >= max)
            return list[lowerIndex][2];
        else
            return max;
    }
}

int coolHighTemp(int list[12][3], int lowerIndex, int upperIndex)
{
    int min;

    if (lowerIndex == upperIndex)
        return list[lowerIndex][1];
    else
    {
        min = coolHighTemp(list, lowerIndex + 1, upperIndex);
        if (list[lowerIndex][1] <= min)
            return list[lowerIndex][1];
        else
            return min;
    }
}

int coolLowTemp(int list[12][3], int lowerIndex, int upperIndex)
{
    int min;

    if (lowerIndex == upperIndex)
        return list[lowerIndex][2];
    else
    {
        min = coolLowTemp(list, lowerIndex + 1, upperIndex);
        if (list[lowerIndex][2] <= min)
            return list[lowerIndex][2];
        else
            return min;
    }
}

void outputDataHead(int year)
{
    int spacesNeeded, spacesPrinted;
    string title;
    string dataYear;
    stringstream stringYear;

    stringYear << year;
    dataYear = stringYear.str();
    title = "Report for " + dataYear;
    
    spacesNeeded = (80 - title.length()) / 2;
    for(spacesPrinted = 0; spacesPrinted < spacesNeeded; spacesPrinted++)
        cout << " ";
    cout << title << endl;

    cout << setw(22) << "Month" << setw(29) << "High Temperature" << setw(29)
         << "Low Temperature" << endl;
}

void outputData(string dataNameList[], int dataList[12][3], int arraySize)
{
    int index;

    for (index = 0; index < arraySize; index++)
        cout << setw(22) << dataNameList[index] << setw(29) << dataList[12][1]
             << setw(29) << dataList[12][2] << endl;
}

void outputaverage(int dataList[12][3], int arraySize)
{
    int index;
    int sumLow, sumHigh;
    float averageLow, averageHigh;

    for (index = 0; index < arraySize; index++)
    {
        sumLow = sumLow + dataList[12][1];
        sumHigh = sumHigh + dataList[12][2];
    }

    averageLow = static_cast<float>(sumLow / 12);
    averageHigh = static_cast<float>(sumHigh / 12);

    cout << setw(22) << "Average" << setw(29) << averageHigh << setw(29)
         << averageLow << endl;
}

void outputWarmestHighMonth(string month, int warmestHighTemp)
{
    cout << "Warmest month (high): " << month << "    "
         << warmestHighTemp << endl;
}

void outputWarmestLowMonth(string month, int warmestLowTemp)
{
    cout << "Warmest month (low): " << month << "    "
         << warmestLowTemp << endl;
}

void outputCoolestHighMonth(string month, int coolestHighTemp)
{
    cout << "Coolest month (high): " << month << "    "
         << coolestHighTemp << endl;
}

void outputCoolestLowMonth(string month, int coolestLowTemp)
{
    cout << "Coolest month (low): " << month << "    "
         << coolestLowTemp << endl;
}
