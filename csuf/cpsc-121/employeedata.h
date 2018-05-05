#include <string>

using namespace std;

class employeeData
{
    public:
        int welcomeMessage();
        string enterName();
        unsigned int enterHoursWorked();
        float enterPayRate();
        unsigned int enterDependents();
        bool enterHealthPlanMembership();
        float grossPayAmount();
        float withholdingTaxAmount();
        float healthInsuranceCost();
        float netPayAmount();
        void outputDataTitle();
        void outputEmployeeData();
        void goodbyeMessage();
    private:
        string name;
        unsigned int hoursWorked;
        float payRate;
        unsigned int dependents;
        string answer;
        string memberOfHealthPlan;
        unsigned int extraHours;
        float grossPay;
        float withholdingTax;
        float healthInsurance;
        float netPay;
        short int spacesNeeded;
        short int spacesPrinted;
        string titleLineOne;
        string titleLineTwo;
};
