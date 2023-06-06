/**
    @file primHeap.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 06, 2023
    @section DESCRIPTION
    This file implements the library functions from primHeap.h
 */

#include "primHeap.h"
#include <math.h>
#include <stdio.h>

Heap* newPrimHeap(int capacity) {
    /* Allocate memory and set default parameters */
    Heap* newHeap = malloc(sizeof(Heap));
    newHeap->data = malloc(sizeof(Edge *) * capacity);
    for(int i = 0; i < capacity; i++){
        newHeap->data[i] = malloc(sizeof(Edge));
    }
    newHeap->currentSize = 0;
    newHeap->maxSize = capacity;

    /* Error handle malloc call to heap data array */
    if(newHeap->data == NULL){
        /* Return NULL to indicate initialization error */
        return NULL;
    }else{
        /* If both malloc calls were successful, return struct pointer */
        return newHeap;
    }
}

void deletePrimHeap(Heap* myHeap) {
    /* If the heap exists, free its memory */
    if(myHeap != NULL){
        /* If the data memory was previously allocated, free it */
        if(myHeap->data != NULL){
            for(int i = 0; i < myHeap->currentSize; i++){
                free(myHeap->data[i]);
            }
            free(myHeap->data);
        }
        free(myHeap);
    }
}

bool emptyHeap(Heap* myHeap) {
    /* Return true if myheap size is not 0 */
    return myHeap->currentSize == 0;
}

int primHeapMin(Heap* myHeap) {
    int currentMin = -1;
    /* NULL check heap pointer */
    if(myHeap == NULL){
        return currentMin;
    }
    /* If there is at least one element in the heap, seg fault won't occur when accessing data array */
    if(myHeap->currentSize > 0){
        currentMin = myHeap->data[0]->weight;
    }
    /* Return smallest value in data array */
    return currentMin;
}

void primHeapDeleteMin(Heap* myHeap) {
    if(!emptyHeap(myHeap)){
        /* Swap first element with last element */
        primHeapSwap(myHeap, 0, myHeap->currentSize - 1);
        /* Decrement size to make that value as deleted */
        myHeap->currentSize--;
        /* Downheap heap to validate order */
        primDownHeap(myHeap, 0);
    }
}
 
void primDownHeap(Heap* myHeap, int i) {
    int leftIndex = leftChild(i);
    int rightIndex = rightChild(i);
    int minIndex;
    /* index i has no children */
    if(leftIndex >= myHeap->currentSize){
        return;
    }
    
    if(rightIndex >= myHeap->currentSize){
        /* Min index is left child if right child doesn't exist */
        minIndex = leftIndex;
    }else{
        /* Choose smallest value if both children exist */
        minIndex = myHeap->data[leftIndex]->weight > myHeap->data[rightIndex]->weight ? rightIndex : leftIndex;
    }

    /* If i's value is larger than its minimum child */
    if(myHeap->data[i]->weight > myHeap->data[minIndex]->weight){
        /* Swap i and i's smallest child */
        primHeapSwap(myHeap, i, minIndex);
        /* Validate current heap position */
        primDownHeap(myHeap, minIndex);
    }
}

void primHeapInsert(int nodeA, int nodeB, int weight, Heap* myHeap) {
    /* NULL check heap */
    if(myHeap == NULL){
        return;
    }

    /* If size is at max, cannot insert new value */
    if(myHeap->currentSize == myHeap->maxSize){
        printf("Warning! Cannot insert into full Heap\n");
        return;
    }

    /* Set connections and weight for new node */
    myHeap->data[myHeap->currentSize]->nodeA = nodeA;
    myHeap->data[myHeap->currentSize]->nodeB = nodeB;
    myHeap->data[myHeap->currentSize]->weight = weight;
    /* Increment size */
    myHeap->currentSize++;
    /* Upheap heap to validate order */
    primUpHeap(myHeap, myHeap->currentSize - 1);
}

void primUpHeap(struct Heap* myHeap, int i) {
    int parentIndex = parent(i);
    if(parentIndex < 0){
        /* If new value has no parent (first val), do nothing */
        return;
    }
    int parentVal = myHeap->data[parentIndex]->weight;
    if(parentVal <= myHeap->data[i]->weight){
        /* If parent is less than current, heap conditions pass */
        return;
    }
    /* If not, swap parent and current value */
    primHeapSwap(myHeap, i, parentIndex);
    /* Upheap from parent's old index (current's new index) */
    primUpHeap(myHeap, parentIndex);
}

int parent(int n) {
    /* Parent equation from lecture */
    return (n - 1) / 2;
}

int leftChild(int n) {
    /* Left child equation from lecture */
    return n * 2 + 1;
}

int rightChild(int n) {
    /* Right child equation from lecture */
    return n * 2 + 2;
}

void primHeapSwap(Heap* myHeap, int i, int j) {
    /* NULL check heap pointer */
    if(myHeap == NULL){
        return;
    }
    /* If there currently isn't 2 elements or heap cannot store 2 elements, cannot swap */
    if(myHeap->currentSize < 2 || myHeap->maxSize < 2){
        return;
    }
    /* If i or j is out of range of current num of elements, should not swap */
    if(j > myHeap->currentSize - 1 || i > myHeap->currentSize - 1){
        return;
    }
    /* If indices are the same, no need to swap */
    if(i == j){
        return;
    }
    /* Swap two integers in the array */
    Edge *temp = myHeap->data[i];
    myHeap->data[i] = myHeap->data[j];
    myHeap->data[j] = temp;
}

/* A gift to the student: */
void printPrimHeap(Heap *myHeap) {
    printf("Heap Current Size: %d\n", myHeap->currentSize);
    printf("Heap Max Size: %d\n", myHeap->maxSize);
    printf("Contents:\n");
    for (int i = 0; i < myHeap->currentSize; i++) {
        printf("[%d to %d, %d] ", myHeap->data[i]->nodeA, myHeap->data[i]->nodeB, myHeap->data[i]->weight);
    }
    printf("\n");
} /* Thanks! */

void primHeapClear(Heap* myHeap) {
    myHeap->currentSize = 0;
}
