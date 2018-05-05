/*
  ============================================================================
  Name        : Project3.c
  Author      : Michael Wiseman
  Version     : 1.0
  Copyright   : http://creativecommons.org/license/publicdomain/
  Description : Project 3 additional functions
  ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int largestDiff(int size, int arr[])
{
    int min, max;
    int i = 0;

    // your code here
    if (size == 0)
    {
        return 0;
    }
    else
    {
        min = arr[i];
        for (i = 0; i < size; ++i)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        i = 0;
        max = arr[i];
        for (i = 0; i < size; ++i)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
    }
    
    return (max - min);
}

int either22or44(int size, int arr[]) // xor that is
{
    // your code here
    int i;
    int state = 0;

    for (i = 0; (i + 1) < size; ++i)
    {
        if (arr[i] == 4)
        {
            if ((state == 0) && (arr[i + 1] == 4)) 
            {
                state = 1; // There are two 4s in a row
            }
            else if ((state == 1) && (arr[i + 1] == 4)) // Two 4s or Two 2s have already been seen
            {
                state = 0;
            }
        }
        else if (arr[i] == 2)
        {
            if ((state == 0) && (arr[i + 1] == 2))
            {
                state = 1;
            }
            else if ((state == 1) && (arr[i + 1] == 2))
            {
                state = 0;
            }
        }
    }

    return state;
}