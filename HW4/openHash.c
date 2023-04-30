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
    OpenHash *newTable = malloc(sizeof(OpenHash));
    newTable->size = size;
    newTable->data = malloc(sizeof(LinkedList*)*size); 
    
    for(int i = 0; i < size; i++){
        newTable->data[i] = newLinkedList();
    }

    return newTable;
}

void deleteOpenHash(OpenHash *table) {
    for(int i = 0; i < table->size; i++){
        deleteLinkedList(table->data[i]);
    }
    free(table->data);
    free(table);
}

int hash(char* word, int n) {
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
    int index = hash(word, table->size);
    return contains(word, table->data[index]);
}

void insertOpenHash(char* word, OpenHash* table) {
    int index = hash(word, table->size);
    if(contains(word, table->data[index])){
        return;
    }
    insert(word, table->data[index]);
}

void printOpenHash(OpenHash *table) {
    for(int i = 0; i < table->size; i++){
        printList(table->data[i]);
    }
}