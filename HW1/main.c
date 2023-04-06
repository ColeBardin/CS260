/**
  @mainpage CS 260 - Homework 1
  @section Description
  Game to guess a number between 0 and 100 that the user chooses.
  Uses binary searching techniques to guess the user's number.

  */

/**
  @file main.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 05, 2023
  @section DESCRIPTION
  Runs the number guessing program implementing binary searching
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int upper = 100;      /* Upper bound of guesses */
    int lower = 0;        /* Lower bound of guesses */
    int nextGuess;        /* Variable to hold the current guess */
    int isFound = 0;      /* Variable to indicate whether or not the number is found */
    char responseBuf[16]; /* Char array to hold extra characters read from STDIN */

    /* Print out welcome message with instructions */
    printf("Think of a number between 0 and 100.\n");
    printf("Responses:\n");
    printf("h or H means Higher\n");
    printf("l or L means Lower\n");
    printf("y or Y means yes this number is correct\n");

    /* Loop until the number is found */
    while (isFound == 0)
    {
		/* Calculate next guess as midpoint between upper and lower bound */
        nextGuess = (upper + lower) / 2;
        printf("Is your number %d?\n", nextGuess);

		/* Get user input */
        scanf("%s", responseBuf);

        /* Process user input */
        switch (responseBuf[0])
        {
		/* Yes response case */
        case 'y':
        case 'Y':
            isFound = 1;
            break;
		/* Higher response case */
        case 'h':
        case 'H':
            lower = nextGuess + 1;
            break;
		/* Lower response case */
        case 'l':
        case 'L':
            upper = nextGuess - 1;
            break;
		/* Unexpected response case */
        default:
            printf("Invalid response!\n");
            break;
        }
    }

    printf("Thank you for playing\n");
    return 0;
}
