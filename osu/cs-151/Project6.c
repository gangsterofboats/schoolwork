/*
  ============================================================================
  Name        : Project6.c
  Author      : Michael Wiseman
  Version     : i
  Copyright   : Public Domain
  Description : Reading data from an .xls file and generating statistics.
  ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char name[100];
    int scores[7];
} STUDENT;

// function declarations
void getFileName(char *filename);
int howManyLines(char *filename);
void readFileIntoArray(char *filename, STUDENT students[], int *size);
void getStats(STUDENT students[], int size);

int main(void)
{
    char filename[30];
    STUDENT *students;
    int size;
    
    getFileName(filename); // already works

    students = malloc( (howManyLines(filename)+1) * sizeof(STUDENT)); // don't change
    
    readFileIntoArray(filename, students, &size); // your job to write this function

    getStats(students, size); // your job to write this function
    
    return EXIT_SUCCESS;
}

/*
 * This function goes through the student array and prints out who scored highest
 * on each of the seven assignments. If there is a tie, print out all the students
 * who tied for the highest score.
 * 
 * size is the size of the array.
 * 
 * You can use fmax in the math.h library if you want.
 */
void getStats(STUDENT students[], int size)
{
    int numOfScores = 7;
    int maxScore, i, j;
    
    for (i = 0; i < numOfScores; ++i)
    {
        j = 0;
        maxScore = students[j].scores[i];
        for (j = 0; j < size; ++j)
        {
            if (maxScore < students[j].scores[i])
            {
                maxScore = students[j].scores[i];
            }
        }
        for (j = 0; j < size; ++j)
        {
            if (maxScore == students[j].scores[i])
            {
                printf("%s had the highest grade on project %d, a %d\n", 
                       students[j].name, i + 1, students[j].scores[i]);
            }
        }
        printf("\n");
    }
}

/*
 * opens file named filename
 * 
 * read from the file while fscanf returns something != EOF  <- end of file
 * 
 * for each struct in the array:
 *   reads students names into struct
 *   reads the 7 scores into struct
 * counts the structs and puts the result into *size.
 * 
 * The lines in the file come in this form:
 * Wallace, Christine (userid) | studentid int1 int2 int3 int4 int5 int6 int7
 * 
 * for extra credit your code should also handle lines like this:
 * Mc Donald, Ronald (userid) | studentid int1 int2 int3 int4 int5 int6 int7
 * 
 * In other words, some last names may have 2 strings. But they will always end in ,
 * 
 * In either case, this function concatenates lastName, firstName (use strcat) and
 * stores the resulting string in the name member of the STUDENT struct.
 * Throw away the user id, |, and the student id. Don't store them anywhere in the struct.
 */
void readFileIntoArray(char *filename, STUDENT students[], int *size)
{
    int studentID, i, nameLength, numOfStudents = 0;
    char lastNameOne[33], lastNameTwo[33], firstName[33]; // lastNameOne will be the full name
    char userID[15], bar[3], testChar;
    FILE *fp;

    fp = fopen(filename, "r");

    do
    {
        fscanf(fp, "%s", lastNameOne);
        nameLength = strlen(lastNameOne);
        strcat(lastNameOne, " ");
        if (lastNameOne[nameLength - 1] != ',')
        {
            fscanf(fp, "%s", lastNameTwo);
            strcat(lastNameOne, lastNameTwo);
            strcat(lastNameOne, " ");
        }
        fscanf(fp, "%s", firstName);
        strcat(lastNameOne, firstName);
        strcpy(students[numOfStudents].name, lastNameOne);
        fscanf(fp, "%s", userID);
        fscanf(fp, "%s", bar);
        fscanf(fp, "%d", &studentID);
        for (i = 0; i < 7; ++i)
        {
            fscanf(fp, "%d", &students[numOfStudents].scores[i]);
        }
        ++numOfStudents;
    } while (fscanf(fp, "%c", &testChar) != EOF);

    fclose(fp);
    *size = numOfStudents;
}

/*
 * Gets a valid filename from the user. A valid filename ends in .xls
 * filename will point to the valid filename.
 */
void getFileName(char *filename)
{
    int len;
    
    do
    {
        printf("Where are the grades? Enter a filename that ends with .xls ");
        fflush(stdout);
        scanf("%s", filename);
        len = strlen(filename);
    }
    while(filename[len-1] != 's' || filename[len-2] != 'l' ||
          filename[len-3] != 'x' || filename[len-4] != '.');
}

/*
 * Counts the newlines but consecutive newlines will not be counted.
 */
int howManyLines(char *filename)
{
    FILE *fp;
    char c;
    int count=0, newLineflag=0;
    fp = fopen(filename, "r");
    while(fscanf(fp, "%c", &c) != EOF)
    {
        if(c=='\n' && !newLineflag)
        {
            count++;
            newLineflag = 1;
        }
        else if (c != '\n')
            newLineflag = 0;          
    }
    fclose(fp);
    return count;
}
