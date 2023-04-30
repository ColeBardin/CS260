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
#include <stdbool.h>
#include <stdlib.h>
#include "openHash.h"

#define BUFSIZE 254

/**
 * @brief Determines if a character is an end of word indicator
 * 
 * @param c Character to examine
 * @return true if character signifies end of word
 * @return false if character is not end of word
 */
bool isEndOfWord(char c);

int main(void) {
  int tableSize, returnValue, uniqueWordCount, totalWordCount, index; 
  char inputBuffer[BUFSIZE]; /* Buffer to hold input characters */
  char character = 0; /* Temporary value to hold character value */
  FILE *file; /* File pointer handle */

  /* Get hash size form user */
  printf("Enter Size of Hash Table:\n");
  returnValue = scanf("%d", &tableSize);
  if(returnValue < 1){
    printf("Error getting hast table size\n");
    return -1;
  }

  /* Get filename from user */
  printf("Enter Name of File:\n");
  returnValue = scanf("%s", inputBuffer);
  if(returnValue < 1){
    printf("Error getting filename\n");
    return -1;
  }

  /* Attempt to open the file */
  file = fopen(inputBuffer, "r");
  if(file == NULL){
    printf("Error cannot find file: %s\n", inputBuffer);
    return -1;
  }

  /* Create openHash */
  OpenHash *hash = newOpenHash(tableSize);

  /* Set counter variables to 0 */
  uniqueWordCount = 0;
  totalWordCount = 0;
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

      /* Reset character index counter */
      index = 0;
      
      /* Only process strings with non zero length */
      if(strlen(inputBuffer) > 0){
        /* Increase total word counter */
        totalWordCount++;
        /* If the word is not already in the hash */
        if(member(inputBuffer, hash) == false){
          /* Increment unique word counter */
          uniqueWordCount++;
          /* Add word to hash */
          insertOpenHash(inputBuffer, hash); 
        }
      }
    }
  }

  int hashEntriesCount = 0;
  /* Print out stats about the interation */
  printf("Total Words: %d\n", totalWordCount);
  printf("Unique Words: %d\n", uniqueWordCount);
  printf("Hash Size: %d\n", tableSize);

  /* Print each row of the hash table and its number of values */
  for(int hashIndex = 0; hashIndex < tableSize; hashIndex++){
    printf("Row %d contains %d values.\n", hashIndex, lengthLinkedList(hash->data[hashIndex]));
    hashEntriesCount += lengthLinkedList(hash->data[hashIndex]);
  }
  
  /* Calculate average hash entry length */
  float hashAverage = (float)hashEntriesCount / (float)tableSize;
  printf("Average Length: %.2f\n", hashAverage);

  /* Free memory of open hash and linked list objects */
  deleteOpenHash(hash);
  return 0;
}

bool isEndOfWord(char c) {
  switch (c){
    /* End of word indicators specified in HW4 document */
    case ' ':
    case '\n':
    case '\r':
    case EOF:
      return true;
    default:
      return false;
  }
}