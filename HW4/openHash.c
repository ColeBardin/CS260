/**
  @file openHash.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 27, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#include <stdlib.h>
#include "openHash.h"

OpenHash* newOpenHash(int size) {
    /* Allocate memory for new hash table */
    OpenHash *newTable = malloc(sizeof(OpenHash));
    /* Set table size */
    newTable->size = size;
    /* Allocate memory for ~size~ LinkedList pointers in an array */
    newTable->data = malloc(sizeof(LinkedList*)*size); 
    
    /* Create a new linked list handle for each element in the data array */
    for(int i = 0; i < size; i++){
        newTable->data[i] = newLinkedList();
    }

    return newTable;
}

void deleteOpenHash(OpenHash *table) {
    /* Iterate over each LinkedList pointer in the table */
    for(int i = 0; i < table->size; i++){
        /* Delete the linked list, this frees it's memory */
        deleteLinkedList(table->data[i]);
    }

    /* Free memory for array of linked lists */
    free(table->data);
    /* Free memory for hash table */
    free(table);
}

int hash(char* word, int n) {
    /* Hash algorithm provided in HW4 document */
    int total = 0;
    for(int i=0; word[i]!=0; i++){
        char c = word[i];
        total = total+(int) c;
        total = total*101;
        total = total%n;
    }
    return total;
}

bool member(char* word, OpenHash* table) {
    /* Get has index for given word */
    int index = hash(word, table->size);
    /* Check if linked list array at the hash index contains the word */
    return contains(word, table->data[index]);
}

void insertOpenHash(char* word, OpenHash* table) {
    /* Use hash algorithm to get word from index */
    int index = hash(word, table->size);
    /* Ignore call if word is already in hash table */
    if(contains(word, table->data[index])){
        return;
    }
    /* Insert the word otherwise */
    insert(word, table->data[index]);
}

void printOpenHash(OpenHash *table) {
    /* Iterate through linked list array and print each list */
    for(int i = 0; i < table->size; i++){
        printList(table->data[i]);
    }
}
