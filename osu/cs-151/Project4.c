/*
  ============================================================================
  Name        : Project4.c
  Author      : Michael Wiseman
  Version     : Pi
  Copyright   : http://creativecommons.org/licenses/publicdomain
  Description : Project 4
  ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

void triangle(char *s1);
void triangle2(char s1[]);
void foo(int howMany, int start, int ar[]);
void foo2(int howMany, int start, int *ar);
char *bar(int howMany, int start, char *c);

int main(void)
{
    char string1[] = "Oregon State University";
    int array[] = {2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
        
    triangle(string1);
    triangle2(string1);
    foo(4, 3, array);
    foo2(4, 3, array);
    char *c = bar(7, 2, string1);
    printf("bar returned a pointer to this substring: %s of %s\n", c, string1);
        
    return EXIT_SUCCESS;
}// end of main



/*
 * Use a pointer to char to print out Strings
 * Use pointer arithmetic.
 * My output when sent "Oregon" is:
 * Oregon
 * regon
 * egon
 * gon
 * on
 * n
 */
void triangle(char *s1)
{
    // your code here
    while (*s1)
    {
        printf("%s\n", s1);
        ++s1;
    }
}



/*
 * Use array syntax to print out Strings
 * Do not use pointers
 * My output when sent "Oregon" is:
 * Oregon
 * regon
 * egon
 * gon
 * on
 * n
 */
void triangle2( char s1[] )
{
    // your code here
    int i;

    for (i = 0; s1[i] != '\0'; ++i)
    {
        printf("%s\n", &s1[i]);
    }
}



/*
 * Print out 'howMany' elements in the array starting at the 'start' index
 * My output with int array[] = {2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
 * foo(4, 3, array);
 * 8 10 9 7
 * 
 * Do not use pointers. Just use array syntax.
 */
void foo(int howMany, int start, int ar[])
{
    //your code here
    int i, j;

    for (i = start, j = 1; j <= howMany; ++i, ++j)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}



/*
 * Print out 'howMany' elements in the array starting at the 'start' index
 * My output with int array[] = {2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
 * foo(4, 3, array);
 * 8 10 9 7
 * 
 * Do not use array syntax. Just use pointers and pointer arithmetic.
 */
void foo2(int howMany, int start, int *ar)
{
    // your code here
    int i;
    
    ar += start;
    for (i = 1; i <= howMany; ++i, ++ar)
    {
        printf("%d ", *ar);
    }
    printf("\n");
}



/*
 * This function mallocs space for a new string with 'howMany' chars plus
 * a null termination char.
 * Then this function copies the substring starting at the 'start' index. 
 * It copies 'howMany' chars.
 * It also ends the new string with a null termination char and returns a
 * pointer to this new string.
 * My result when called with:
 * char string1[] = "Oregon State University";
 * char *c = bar(7, 2, string1);
 * printf("bar returned a pointer to this substring: %s of %s\n", c, string1);
 * 
 * bar returned a pointer to this substring: egon St of Oregon State University
 */
char *bar(int howMany, int start, char *c)
{
    // your code here
    char *subStr = malloc(sizeof(char) * (howMany + 1));
    int i;

    c += start;
    for (i = 1; i <= howMany; ++i, ++subStr, ++c)
    {
        *subStr = *c;
    }
    *subStr = '\0';
    subStr -= howMany;

    return subStr;
}