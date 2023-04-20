/**
  @file queue.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 20, 2023
  @section DESCRIPTION
  
  This is the source file for a classic queue data structure.
  It includes the definitions for methods Queue.h
 */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *newQueue() {
    Queue *new = malloc(sizeof(Queue));
    /* Return malloc'd pointer, will return NULL if malloc call fails */
    return new;
}

char isEmpty(Queue *Q) {
    /* Return 1 when HEAD is NULL, else 0 */
    return Q->head == NULL;
}

void enqueue(int v, Queue *Q) {
    /* Allocate dynamic memory for a new Node*/
    Node *new = malloc(sizeof(Node));
    /* Return if malloc fails */
    if(new == NULL) {
        return;
    }
    /* Populte new Node with data */
    new->value = v;
    new->next = NULL;

    if(isEmpty(Q)){
        /* For empty queue, set the head to be new Node */
        Q->head = new;
    }else{
        /* For non-empty queue, set previous tail Node point to new Node */
        Q->tail->next = new;
    }

    /* Update Queue tail to be new Node */
    Q->tail = new;
}

int front(Queue *Q) {
    if(isEmpty(Q)){
        /* If Queue is empty, return -1 */
        return -1;
    }else{
        /* Else, return value of HEAD element */
        return Q->head->value;
    }
}

void dequeue(Queue *Q) {
    if(isEmpty(Q)){
        /* Do nothing if Queue is empty */
        return;
    }else{
        /* Else, remove first element */
        Node *toDelete = Q->head;
        /* Update head to be second element */
        Q->head = toDelete->next;
        /* Free first element's memory */
        free(toDelete);
        return;
    }
}

void printQueue(Queue *Q) {
    if(isEmpty(Q)){
        /* If Queue is empty */
        printf("Queue is EMPTY\n");
    }else{
        int index = 0; /* Index for counting Nodes */
        Node *curr = Q->head; /* Current Node pointer, starts at HEAD */
        while(curr != NULL){
            /* Print out each element and its value */
            printf("Node: %d\tValue: %d\n", index++, curr->value);
            /* Iterate to next element */
            curr = curr->next;
        }
    }
}

void josephus(int n, int m) {

}
