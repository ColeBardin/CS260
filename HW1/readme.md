# CS260-001: Homework 1

By Cole Bardin : CAB572

## Description

This program is a game that attempts to guess the user's number using Binary Search method.

## Usage 

Upon running the program, it will ask the user to choose a number between 0 and 100.

The program will attempt to guess the number and the user can respond with:
'h' or 'H' to indicate their number is higher than the guess.
'l' or 'L' to indicate their number is lower than the guess.
'y' or 'Y' to indicate that the guess is correct.

If the user responds with higher or lower, the program will calculate a new guess and prompt the user again.

This repeats until the user indicates the guess is correct.

# Architecture 

This project contains one file `main.c`.

The only library dependency is `stdio.h` to interact with STDIN

Calculating the next guess, reading user input, and processing response is all done in `main()` method.

This method returns `0` upon completion.
