/**
  @file linkedList.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 27, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


LinkedList *newLinkedList() {
    /* Allocate memory for new linked list */
    LinkedList *list = malloc(sizeof(LinkedList));
    /* By definition, empty list has null head and tail */
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void deleteLinkedList(LinkedList *list) {
    Node *currentNode; /* Pointer to keep track of current Node */
    Node *nextNode; /* Pointer to keep track of next Node */

    /* Start at list head */
    currentNode = list->head;

    /* Iterate through each element of the list */
    while(currentNode != NULL){
        /* Store next element */
        nextNode = currentNode->next;
        /* Free current node */
        free(currentNode);
        /* Advance to next node*/
        currentNode = nextNode;
    }

    /* Free memory for the list after all elements are freed */
    free(list);
}

void insert(int value, LinkedList *list) {
    /* Allocate memory for new Node */
    Node *node = malloc(sizeof(Node));
    /* Add value to new node */
    node->value = value;
    /* Make new node not point to anything */
    node->next = NULL;

    if(list->tail == NULL){
        /* If list is currently empty, set new node as head */
        list->head = node;
    }else{
        /* If not empty, add node after tail */
        list->tail->next = node;
    }
    /* Update tail pointer */
    list->tail = node;
}

void reverse(LinkedList *list) {
    /* 3 pointers to keep track of list order */
    Node *previous;
    Node *current;
    Node *next;

    /* Return*/
    if(list == NULL){
        printf("Empty list");
    }else{
        /* Start with previous NULL for new tail */
        previous = NULL;
        /* Start with current at head */
        current = list->head;

        while(current != NULL){
            /* Take the next node before swapping pointers */
            next = current->next;
            /* Point the current node backwards */
            current->next = previous;

            /* Move the previous pointer forward */
            previous = current;
            /* Move the current pointer forward */
            current = next;
        }
        /* Update list head */
        list->head = previous;
    }
}

bool contains(int value, LinkedList *list) {
    /* Start search at head of list */
    Node *currentNode = list->head;

    /* Iterate through each element */
    while(currentNode != NULL){
        /* If current element matches with word */
        if(currentNode->value == value){
            return true;
        }else{
            /* If no match, advance to next element */
            currentNode = currentNode->next;
        }
    }
    /* If no matches were found, list does not contain element */
    return false;
}

void printList(LinkedList *list) {
    /* Handle empty list being passed */
    if(list->head == NULL){
        printf("Empty List\n");
    }else{
        /* Iterate through all elements in list */
        Node *currentNode = list->head;
        while(currentNode != NULL){
            /* Print out their word */
            printf("[\"%d\"]\n", currentNode->value);
            currentNode = currentNode->next;
        }
    }
}

int lengthLinkedList(LinkedList *list) {
    int count = 0; /* Element counter variable */
    
    /* Handle invalid pointer being passed */
    if(list == NULL){
        return -1;
    }

    /* Iterate through each Node */
    Node *node = list->head;
    while(node != NULL){
        /* Count each non-NULL node */
        node = node->next;
        count++;
    }

    return count;
}
