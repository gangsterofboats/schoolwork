/********************************************************************************
 * Michael Wiseman                                                              *
 * CS 151 Intro To C Programming                                                *
 * Professor Wallace                                                            *
 * Project #2                                                                   *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMessage(int, int);

int main(int argc, char *argv[])
{
    int prev, current;

    srand(time(NULL));
    current = rand();
    if (current > 99)
    {
        current %= 100;
    }
    printMessage(-1, current);
    while (current % 10 != 0)
    {
        prev = current;
        current = rand();
        if (current > 99)
        {
            current %= 100;
        }
        printMessage(prev, current);
    }
    
    return 0;
}

void printMessage(int pre, int curr)
{
    if (pre == -1)
    {
        if (curr % 2 == 0)
        {
            printf("x = %d and that is even.\n", curr);
        }
        else
        {
            printf("x = %d and that is odd.\n", curr);
        }
    }
    else
    {
        if (curr % 2 == 0)
        {
            if (curr > pre)
            {
                printf("x = %d and that is even and that is > %d the previous int\n", curr, pre);
            }
            else
            {
                printf("x = %d and that is even and that is < %d the previous int\n", curr, pre);
            }
        }
        else
        {
            if (curr > pre)
            {
                printf("x = %d and that is odd and that is > %d the previous int\n", curr, pre);
            }
            else
            {
                printf("x = %d and that is odd and that is < %d the previous int\n", curr, pre);
            }
        }
    }
}
