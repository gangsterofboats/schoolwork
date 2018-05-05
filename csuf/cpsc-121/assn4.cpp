/*******************************************************************************
 * Michael Wiseman                                                             *
 * CPSC 121                                                                    *
 * Assignment 4                                                                *
 * mwiseman@student.fullerton.edu                                              *
 * Tuesday, October 18, 2005                                                   *
 ******************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include "employeedata.h"

using namespace std;

int employeeData::welcomeMessage()
{
    cout << "Hello and welcome to the InfoTech Employee Database." << endl;
    cout << "In a moment, please the the data for the person." << endl;

    return 0;
}

string employeeData::enterName()
{
    cout << "\nPlease enter the employee's name.  ";
    cin >> name;

    return name;
} 

unsigned int employeeData::enterHoursWorked()
{
    cout << "Please enter the number of hours worked.  ";
    cin >> hoursWorked;

    return hoursWorked;
}

float employeeData::enterPayRate()
{
    cout << "Please enter the pay rate.  ";
    cin >> payRate;

    return payRate;
}

unsigned int employeeData::enterDependents()
{
    cout << "Please enter the number of dependents the employee has.  Note that"
         << " the employee also counts as one of the dependents.  ";
    cin >> dependents;

    return dependents;
}

bool employeeData::enterHealthPlanMembership()
{
    cout << "Is the employee a member of the company sponsored health plan?  ";
    cin >> answer;
    if (answer == "Yes")
    {
        memberOfHealthPlan = "Y";
        return true;
    }
    else
    {
        memberOfHealthPlan = "N";
        return false;
    }
}

float employeeData::grossPayAmount()
{
    if(hoursWorked > 40)
    {
        extraHours = hoursWorked - 40;
        grossPay = 40 * payRate;
        grossPay = grossPay + ( extraHours * grossPay * 0.50 );
        return grossPay;
    }
    else
    {
        grossPay = hoursWorked * payRate;
        return grossPay;
    }
}

float employeeData::withholdingTaxAmount()
{
    if (grossPay > 300)
    {
        withholdingTax = grossPay * 0.22;
        return withholdingTax;
    }
    else
        withholdingTax = 0;

        return withholdingTax;
}

float employeeData::healthInsuranceCost()
{
    if (dependents == 1)
    {
        healthInsurance = 18.50;
        
        return healthInsurance;
    }
    else
    {
        healthInsurance = 18.50;
        dependents--;
        healthInsurance = healthInsurance + (dependents * 7.50);
        return healthInsurance;
    }
}

float employeeData::netPayAmount()
{
    netPay = grossPay - withholdingTax - healthInsurance;
    
    return netPay;
}

void employeeData::outputDataTitle()
{
    titleLineOne = "InfoTech Corporation";
    titleLineTwo = "Payroll Data For " + name;
    
    spacesNeeded = (80 - titleLineOne.length()) / 2;
    cout << endl;
    for(spacesPrinted = 0; spacesPrinted < spacesNeeded; spacesPrinted++)
        cout << " ";
    cout << titleLineOne << endl;

    spacesNeeded = (80 - titleLineTwo.length()) / 2;
    for(spacesPrinted = 0; spacesPrinted < spacesNeeded; spacesPrinted++)
        cout << " ";
    cout << titleLineTwo << endl;
}

void employeeData::outputEmployeeData()
{
    cout << setfill('.') << left << setw(65) << "Name: " << setfill(' ')
         << right << name << endl;
    cout << setfill('.') << left << setw(65) << "Gross Pay: " << setfill(' ')
         << right << "$" << setprecision(2) << fixed << grossPay << endl;
    cout << setfill('.') << left << setw(65) << "Withholding Tax: "
         << setfill(' ') << right << "$" << setprecision(2) << fixed 
         << withholdingTax << endl;
    cout << setfill('.') << left << setw(65) << "Health Insurance: "
         << setfill(' ') << right << "$" << setprecision(2) << fixed
         << healthInsurance << endl;
    cout << setfill('.') << left << setw(65) << "Net Pay: " << setfill(' ')
         << right << "$" << setprecision(2) << fixed << netPay << endl;
}

void employeeData::goodbyeMessage()
{
    cout << "\nGoodbye." << endl;
}

int main()
{
    employeeData netWages;

    netWages.welcomeMessage();
    netWages.enterName();
	netWages.enterHoursWorked();
	netWages.enterPayRate();
	netWages.enterDependents();
	netWages.enterHealthPlanMembership();
    netWages.grossPayAmount();
    netWages.withholdingTaxAmount();
    netWages.healthInsuranceCost();
    netWages.netPayAmount();
    netWages.outputDataTitle();
    netWages.outputEmployeeData();
    netWages.goodbyeMessage();

    return 0;
}
