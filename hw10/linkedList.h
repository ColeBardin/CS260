/**
    @file linkedList.h
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 06, 2023
    @section DESCRIPTION
    This file defines the library functions for a singly linked list of integers
 */

#pragma once

#include <stdbool.h>

/**
    A structure to represent a LinkedList node
 */
typedef struct Node Node;
struct Node {
    int value; /**< value of the node */
    Node *next; /**< pointer to next element in list */
};

/**
    A structure to represent a Linked List
 */
typedef struct LinkedList LinkedList;
struct LinkedList {
    Node *head; /**< pointer to the head node */
    Node *tail; /**< pointer to the tail node */
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
 * @param value value to be inserted
 * @param list List for word to be inserted into
 */
void linkedListInsert(int value, LinkedList *list);

/**
 * @brief Determines if the linked list contains a value
 * 
 * @param value Value to search for
 * @param list List to search in 
 * @return true If word is in list
 * @return false If word is not in list
 */
bool linkedListContains(int value, LinkedList *list);

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

/**
 * @brief Removes an element from the list if it is in the list
 * 
 * @param list List to remove from 
 * @param target value to remove
 */
void linkedListRemove(LinkedList *list, int target);
