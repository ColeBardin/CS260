#/**
  @file linkedlist.h
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 27, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#pragma once

#include <stdbool.h>

typedef struct Node Node;
struct Node {
    char *word;
    Node *next;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
    Node *head;
    Node *tail;
};

/**
 * @brief Allocates memory for a new linked list
 * 
 * @return LinkedList* Pointer to allocated memory
 */
LinkedList *newLinkedList();

/**
 * @brief Deletes a linked list and frees all of its memory
 * 
 * @param list List to be deleted
 */
void deleteLinkedList(LinkedList *list);

/**
 * @brief Inserts a word into the linked list, copies into new memory allocation
 * 
 * @param word Word to be inserted
 * @param list List for word to be inserted into
 */
void insert(char *word, LinkedList *list);

/**
 * @brief Determines if the linked list contains a word
 * 
 * @param word Word to search for
 * @param list List to search in 
 * @return true If word is in list
 * @return false If word is not in list
 */
bool contains(char *word, LinkedList *list);

/**
 * @brief Prints out contents of linked list, for debugging
 * 
 * @param list List to print
 */
void printList(LinkedList *list);

/**
 * @brief Determines number of elements in list
 * 
 * @param list List to analyze
 * @return int number of elements in list
 */
int lengthLinkedList(LinkedList *list);
