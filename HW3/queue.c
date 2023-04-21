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
    /* Set HEAD and TAIL to be NULL */
    new->head = NULL;
    new->tail = NULL;
    /* Return malloc'd pointer, will return NULL if malloc call fails */
    return new;
}

char isEmpty(Queue *Q) {
    /* Return 1 when HEAD is NULL, else 0 */
    return (Q->head == NULL);
}

void enqueue(int v, Queue *Q) {
    /* Allocate dynamic memory for a new Node*/
    Node *new = malloc(sizeof(Node));
    /* Return if malloc fails */
    if(new == NULL){
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
		
		/* Check if element is only Node in Queue */
		if(toDelete->next == NULL){
			/* If element was only NODE in Queue, make HEAD and TAIL NULL */
			Q->head = NULL;
			Q->tail = NULL;
		}else{
			/* Update head to be second element */
			Q->head = toDelete->next;
		}

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
            /* Print out value of Node */
            printf("Node: %d\tValue: %d\n", index++, curr->value);
            /* Iterate to next Node */
            curr = curr->next;
        }
    }
}

void josephus(int n, int m) {
    Queue *Q = newQueue(); /* Create new empty Queue */
    Node *currentNode; /* Pointer to store current Node */
    int index; /* Variable used to index Queue */
    int totalEliminated = 0; /* Counter for eliminated Nodes */

    /* If malloc call failed */
    if(Q == NULL){
        printf("Error failed to allocate memory for Josephus method\n");
        return;
    }

    /* Add n Nodes with their index as the value */
    for(index = 0; index < n; index++){
        enqueue(index, Q);
    }

    /* Start at HEAD */
    currentNode = Q->head;

    /* Iterate until n Nodes have been eliminated */
    while(totalEliminated < n){
        /* Advance M positions from currentNode */
        for(index = 0; index < m - 1; ){
            /* Find next valid Node */
            if(currentNode->next == NULL){
                /* If currentNode is TAIL, loop back to HEAD */
                currentNode = Q->head;
            }else{
                /* Else, advance to next Node */
                currentNode = currentNode->next;
            }

            /* Skip over already killed Nodes */
            if(currentNode->value != -1){
                index++;
            }
        }
        /* Print out current value/index */
        printf("%d", currentNode->value);
        /* Mark Node as killed */
        currentNode->value = -1;
        /* Count killed NODE */
        totalEliminated++;
        /* If this Node was not the last living Node */
        if(totalEliminated < n){
            printf(" ");
            /* Find next living Node */
            while(currentNode->value == -1){
                /* Go to next Node, loopback to HEAD if at TAIL */
                if(currentNode->next == NULL){
                    currentNode = Q->head;
                }else{
                    currentNode = currentNode->next;
                }
            }
        }
    }
    printf("\n");
    
    /* Dequeue all Nodes, this also frees their memory */
    for(index = 0; index < n; index++){
        dequeue(Q);
    }
    /* Free memory for Queue */
    free(Q);
}
