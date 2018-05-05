/*
  ============================================================================
  Name        : Project3.c
  Author      : Michael Wiseman
  Version     : 1.0
  Copyright   : http://creativecommons.org/licenses/publicdomain
  Description : Project 3
  ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>


// function declarations
int lucky13(int s, int arr[]);
int largestDiff(int s, int arr[]);
int either22or44(int s, int arr[]);

int main(void)
{
    int x;
    int size = 7;
    int ar[] =  { 2, -5, 13, 6, 4, 2, 2 };
    int ar2[] = { 2, -5, 6, 13, 4, 2, 4 };
    int ar3[] = { 2, 3, -5, 6, 4, 4, 13 };
    int ar4[] = { 2, 2, 4, 4, 2, 13, 7 };

    // Call a function at the end of this function.
    x = lucky13(size, ar);
    printf("lucky13 returned %d\n", x);
    
    // Call functions in a different file.
    x = largestDiff(size, ar);
    printf("largestDiff returned %d\n", x);
    
    x = either22or44(size, ar);
    printf("either22or44 returned %d\n", x);
    
    x = either22or44(size, ar2);
    printf("either22or44 returned %d\n", x);
    
    x = either22or44(size, ar3);
    printf("either22or44 returned %d\n", x);
        
    x = either22or44(size, ar4);
    printf("either22or44 returned %d\n", x);
    
    return EXIT_SUCCESS;
}

int lucky13(int s, int arr[])
{
    // your code here
    int i;
    int sum = 0;

    if (s == 0)
    {
        return 0;
    }
    else
    {
        for (i = 0; i < s && arr[i] != 13; ++i)
        {
            sum += arr[i];
        }
        return sum;
    }
}