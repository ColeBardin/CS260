/**
	@file openHash.h
	@author Cole Bardin <cab572@drexel.edu>
	@date April 25, 2023
	@section DESCRIPTION
	
	Header file for Hash Table functions
 */

#pragma once

#include <stdbool.h>
#include "linkedList.h"

typedef struct OpenHash OpenHash;
struct OpenHash {
	int size;
	LinkedList **data;
};

/**
	Create a new Hash table based around an array
	of size elements.
	@param size is the size the array the table is built with
	@return a pointer to the struct
*/
OpenHash* newOpenHash(int size);

/**
 	Deletes an OpenHash struct and frees all memeroy 
 	@param table OpenHash Table to delete
 */
void deleteOpenHash(OpenHash *table);

/**
	The hash function for strings.
	@param word is a null terminated character array
	@param n is the size of the array
	@return the hashed index for the string
*/
int hash(char* word, int n);

/**
	Ask if string is in the table
	@param word is a null terminated character array
	@param table is the Hash Table to search
	@return true if found and false if not
*/
bool member(char* word, OpenHash* table);

/**
	Insert a string into the table. Ignore duplicates.
	@param word is a null terminated character array
	@param table is the Hash Table to search
*/
void insertOpenHash(char* word, OpenHash* table);

void printOpenHash(OpenHash *table);
