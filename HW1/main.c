/**
  @mainpage CS 260 - Homework 1
  @section Description
  Describe how the entire program works. What is it for?

  */

/**
  @file main.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 05, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#include <stdio.h>
#include <stdlib.h>

/**
  Does a binary search
  @param target is what to look for
  @param array is the sorted array to search
  @param start is first index
  @param stop is last index
  @return number of comparisons
*/
int binarySearch(int target, int *array, int start, int stop);

int main(void)
{
    int upper = 100;      /* Upper bound of guesses */
    int lower = 0;        /* Lower bound of guesses */
    int nextGuess;        /* Variable to hold the current guess */
    int isFound = 0;      /* Variable to indicate whether or not the number is found */
    char responseBuf[16]; /* Char array to hold extra characters read from STDIN */

    /* Print out welcome message */
    printf("Think of a number between 0 and 100.\n");
    printf("Responses:\n");
    printf("h or H means Higher\n");
    printf("l or L means Lower\n");
    printf("y or Y means yes this number is correct\n");

    /* Loop until the number is found */
    while (isFound == 0)
    {
        nextGuess = (upper + lower) / 2;
        printf("Is your number %d?\n", nextGuess);
        scanf("%s", responseBuf);

        /* Process user input */
        switch (responseBuf[0])
        {
        case 'y':
        case 'Y':
            isFound = 1;
            break;
        case 'h':
        case 'H':
            lower = nextGuess + 1;
            break;
        case 'l':
        case 'L':
            upper = nextGuess - 1;
            break;
        default:
            printf("Invalid response!\n");
            break;
        }
    }
    printf("Thank you for playing\n");
    return 0;
}

int binarySearch(int target, int *array, int start, int stop)
{
    if (start > stop)
    {
        printf("Never Found\n");
        return 0;
    }
    int middle = start + (stop - start) / 2;
    if (target == array[middle])
    {
        printf("I found it!\n");
        return 1;
    }
    if (target < array[middle])
    {
        return 1 + binarySearch(target, array, start, middle - 1);
    }
    return 1 + binarySearch(target, array, middle + 1, stop);
}