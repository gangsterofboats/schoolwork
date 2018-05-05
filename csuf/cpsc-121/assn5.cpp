/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 5                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Tuesday, November 1, 2005                                                   *
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int numOfStudents();
string enterName();
float enterScore(int&, int&, int&, int&, int&, float&);
string grade(float);
void outputDataFileHead(ofstream&);
void outputStudentData(ofstream&, string, int, int, int, int,
                       int, float, string);

int main()
{
    bool programRunning = true;
    int numberOfStudents;
    string studentName;
    int quizOneScore, quizTwoScore, quizThreeScore, quizFourScore, quizFiveScore;
    float studentAverage;
    string studentGrade;
    string answer;
    float classScoreSum;
    float classAverage;
    ofstream dataFile;

    dataFile.open("c:\\Vim\\CPSC121\\studentdata.txt");
    outputDataFileHead(dataFile);
    while (programRunning == true)
    {
        numberOfStudents = numOfStudents();
        for (numberOfStudents; numberOfStudents > 0; numberOfStudents--)
        {
            studentName = enterName();
            enterScore(quizOneScore, quizTwoScore, quizThreeScore, quizFourScore,
                       quizFiveScore, studentAverage);
            studentGrade = grade(studentAverage);
            outputStudentData(dataFile, studentName, quizOneScore, quizTwoScore, 
                              quizThreeScore, quizFourScore, quizFiveScore,
                              studentAverage, studentGrade);
            classScoreSum = classScoreSum + studentAverage;
        }

        cout << "Are there more students?  ";
        cin >> answer;
        if (answer == "Yes" || answer == "yes")
            programRunning = true;
        else
            programRunning = false;
    }

    classAverage = classScoreSum / numberOfStudents;
    dataFile << "\nClass Average: " << classAverage << "%" << endl;
    dataFile.close();
    
    return 0;
}

int numOfStudents()
{
    int amountOfStudents;

    cout << "How many students are in the class?  ";
    cin >> amountOfStudents;
    cin.ignore();
    
    return amountOfStudents;
}

string enterName()
{
    string name;

    cout << "Please enter the student's name.  ";
    getline(cin, name);

    return name;
}

float enterScore(int& quizOne, int& quizTwo, int& quizThree, 
                 int& quizFour, int& quizFive, float& average)
{
    // int quizOne, quizTwo, quizThree, quizFour, quizFive;
    // float average;

    cout << "Please enter the student's test scores.  ";
    cin >> quizOne >> quizTwo >> quizThree >> quizFour >> quizFive;
    average = (quizOne + quizTwo + quizThree + quizFour + quizFive) / 5;
    cout << "\n";

    return average;
}

string grade(float averageScore)
{
    // float averageScore;
    string grade;

    if (averageScore >= 90)
    {
        grade = "A";
        return grade;
    }
    else if (averageScore >= 80 && averageScore <= 89)
    {
        grade = "B";
        return grade;
    }
    else if (averageScore >= 70 && averageScore <= 79)
    {
        grade = "C";
        return grade;
    }
    else if (averageScore >= 60 && averageScore <= 69)
    {
        grade = "D";
        return grade;
    }
    else
    {
        grade = "F";
        return grade;
    }
}

void outputDataFileHead(ofstream& dataOutputFile)
{
    ofstream dataOutputfile;

    dataOutputFile << setw(11) << "Student" << setw(10) << "Quiz #1" << setw(10)
                   << "Quiz #2" << setw(10) << "Quiz #3" << setw(10) << "Quiz #4"
                   << setw(10) << "Quiz #5" << setw(11) << "Average" << setw(8)
                   << "Grade" << endl;
}

void outputStudentData(ofstream& dataOutputFile, string name, int quizOne, 
                       int quizTwo, int quizThree, int quizFour, int quizFive,
                       float average, string grade)
{
    dataOutputFile << setw(11) << name << setw(10) << setprecision(1) << fixed
                   << quizOne << setw(10) << setprecision(1) << fixed << quizTwo
                   << setw(10) << setprecision(1) << fixed << quizThree
                   << setw(10) << setprecision(1) << fixed << quizFour << setw(10)
                   << setprecision(1) << fixed << quizFive << setw(11)
                   << setprecision(1) << fixed << average << setw(8) << grade;
}
