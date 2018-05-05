/*
  ============================================================================
  Name        : Project5.c
  Author      : Michael Wiseman
  Version     : e
  Copyright   : http://creativecommons.org/licenses/publicdomain/
  Description : Project 5, structs and more string functions
  ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct month
{
    char nameEng[10];
    char nameSpan[11];
    int order;
    int numDays;
};

// put your function declarations here
int findDayCount(struct month *m, char *name, int d);
void initStruct(struct month m[]);

int main(void)
{
    // declare other variables here
    struct month months[12];
    char mName[11];
    int day, dayOfYear;
    initStruct(months);

    // lots of your code here
    printf("Please enter the month name in English or Spanish: ");
    scanf("%s", mName);
    printf("Please enter the day (1 - 31): ");
    scanf("%d", &day);
    dayOfYear = findDayCount(months, mName, day);
    if (dayOfYear != -1)
    {
        printf("That is day #%d in the year.\n", dayOfYear);
    }

    return EXIT_SUCCESS;
}

int findDayCount(struct month *m, char *name, int d)
{
    // the already initialized struct is sent to you
    // name is what the user entered for the month (English or Spanish)
    // d is the day that the user entered
    // extra credit if you can use only pointer syntax (no [])
    int i, j;
    int dayOfYear;

    for (i = 0; i < 12; ++i)
    {
        if (strcmp((m + i)->nameEng, name) == 0 || strcmp((m + i)->nameSpan, name) == 0)
        {
            if (d > ((m + i)->numDays))
            {
                printf("There are %d days in that month.\n", (m + i)->numDays);
                printf("So you cannot use the date %d/%d\n", (m + i)->order, d);
                dayOfYear = -1;
            }
            else if (d < 1)
            {
                printf("%d is less than 1.\n", d);
                printf("So you cannot use the date %d/%d.\n", (m + i)->order, d);
                dayOfYear = -1;
            }
            else
            {
                for (j = 0; j < i; ++j)
                {
                    dayOfYear += ((m + j)->numDays);
                }
                dayOfYear += d;
            }
            break;
        }
    }
    if (i == 12)
    {
        printf("I did not find a month by the name %s in English or in Spanish.\n", name);
        dayOfYear = -1;
    }

    return dayOfYear;
}

void initStruct(struct month m[])
{
    // this has no loops, just a lot of lines that put the right values into the array
    strcpy(m[0].nameEng, "January");
    strcpy(m[0].nameSpan, "enero");
    m[0].order = 1;
    m[0].numDays = 31;

    strcpy(m[1].nameEng, "February");
    strcpy(m[1].nameSpan, "febrero");
    m[1].order = 2;
    m[1].numDays = 28;

    strcpy(m[2].nameEng, "March");
    strcpy(m[2].nameSpan, "marzo");
    m[2].order = 3;
    m[2].numDays = 31;

    strcpy(m[3].nameEng, "April");
    strcpy(m[3].nameSpan, "abril");
    m[3].order = 4;
    m[3].numDays = 30;

    strcpy(m[4].nameEng, "May");
    strcpy(m[4].nameSpan, "mayo");
    m[4].order = 5;
    m[4].numDays = 31;

    strcpy(m[5].nameEng, "June");
    strcpy(m[5].nameSpan, "Junio");
    m[5].order = 6;
    m[5].numDays = 30;

    strcpy(m[6].nameEng, "July");
    strcpy(m[6].nameSpan, "julio");
    m[6].order = 7;
    m[6].numDays = 31;

    strcpy(m[7].nameEng, "August");
    strcpy(m[7].nameSpan, "agosto");
    m[7].order = 8;
    m[7].numDays = 31;

    strcpy(m[8].nameEng, "September");
    strcpy(m[8].nameSpan, "septiembre");
    m[8].order = 9;
    m[8].numDays = 30;

    strcpy(m[9].nameEng, "October");
    strcpy(m[9].nameSpan, "Octubre");
    m[9].order = 10;
    m[9].numDays = 31;

    strcpy(m[10].nameEng, "November");
    strcpy(m[10].nameSpan, "noviembre");
    m[10].order = 11;
    m[10].numDays = 30;

    strcpy(m[11].nameEng, "December");
    strcpy(m[11].nameSpan, "diciembre");
    m[11].order = 12;
    m[11].numDays = 31;
}
