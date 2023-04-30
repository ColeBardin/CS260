/**
  @mainpage CS 260 - Homework 4
  @section Description
  Count the number of words in a text file using an Open Hash table.
 
  */
 
/**
  @file main.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 27, 2023
  @section DESCRIPTION
  This file reads in the input file and implements the OpenHash interface.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "openHash.h"

#define BUFSIZE 254

int isEndOfWord(char c);

int main(void) {
  int tableSize, returnValue, wordCount, index;
  char inputBuffer[BUFSIZE];
  char character = 1;
  FILE *file;

  printf("Enter Size of Hash Table:\n");
  returnValue = scanf("%d", &tableSize);
  if(returnValue < 1){
    return -1;
  }
  printf("Enter Name of File:\n");
  returnValue = scanf("%s", inputBuffer);
  if(returnValue < 1){
    printf("Error getting filename\n");
    return -1;
  }

  wordCount = 0;
  file = fopen(inputBuffer, "r");
  if(file == NULL){
    printf("Cannot file file: %s\n", inputBuffer);
    return -1;
  }

  /* Create openHash */

  index = 0;
  /* Iterate over each character in the file */
  while(character != EOF){
    character = fgetc(file);

    /* If character is a letter, add lowecase version */
    if(isalpha(character)){
      inputBuffer[index] = tolower(character);
      index++;
    /* Process end of word, ignore all other characters */
    }else if(isEndOfWord(character)){
      inputBuffer[index] = '\0';

      /* Reset character index */
      index = 0;
      
      if(strlen(inputBuffer) > 0){
        wordCount++;
      }
    }
  }
  
  /*
  For each word in the file do
    If the word is not in Hash Table then
        Count Unique Word
        Add to Hash Table
    End If
    Count Total Words
  End For
  Print Total Words in File
  Print Unique Words in File
  Print Hash Table Stats
  */
  return 0;
}

int isEndOfWord(char c) {
  switch (c){
    /* End of word indicators */
    case EOF:
    case '\n':
    case ' ':
    case '.':
    case ',':
    case '!':
    case '?':
    case ':':
    case '-':
      return 1;
    default:
      return 0;
  }
}