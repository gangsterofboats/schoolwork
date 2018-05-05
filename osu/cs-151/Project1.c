/*
  ============================================================================
  Name        : Project1.c
  Author      : Michael Wiseman
  Version     : 1.0
  Copyright   : http://creativecommons.org/licenses/publicdomain/
  Description : Project 1, CS151
  Prints out the prime factors of a user entered integer.
  ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

// function declaration
int isPrime(int);

int main(void)
{
    int number; 
    int div = 2;
   
    printf("Please enter a positive integer followed by ENTER: ");
    fflush(stdout);
    scanf("%d",&number);
    number = abs(number); // Ensure a positive number    
    printf("The prime factors of %d is/are:\n", number);
   
    // Put your code below.  You may declare more ints in the first line of main
    // if you want.  Your job is to print out the prime factors of the integer
    // found in the variable number.
   
    while (div <= number)
    {
        if ((number % div == 0) && (isPrime(div)))
        {
            number /= div;
            while (number % div == 0)
            {
                printf("%d ", div);
                number /= div;
            }
        }
        ++div;
    }
    // Put your code above this

    return EXIT_SUCCESS;
}

int isPrime(int this_number)
{
    int divisor, prime;

    divisor = this_number / 2;
    prime = 1;
    while(divisor > 1)
    {
        if(this_number % divisor == 0)
        {
            prime = 0;
            divisor = 0;
        }
        else
        {
            --divisor;
        }
    }
   
    if(prime)
    {
        printf("%d ", this_number);
    }
   
    return prime;
}
