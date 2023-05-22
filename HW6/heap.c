/**
    @file heap.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date May 16, 2023
    @section DESCRIPTION
    This file implements the heap libray methods from heap.h
 */

#include "heap.h"
#include <math.h>
#include <stdio.h>

void heapSort(int* array, int size) {
    int i;
    /* Make new heap with capacity of size */
    Heap *newHeap = makenull(size);
    /* Insert values in array param into new heap */
    for(i = 0; i < size; i++){
        insert(array[i], newHeap);
    }
    /* For each value in the heap,*/
    for(i = 0; i < size; i++){
        array[i] = min(newHeap);
        deletemin(newHeap);
    }
}

Heap* makenull(int capacity) {
    /* Allocate memory and set default parameters */
    Heap* newHeap = malloc(sizeof(Heap));
    newHeap->data = malloc(sizeof(int) * capacity);
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

void deleteHeap(Heap* myHeap) {
    /* If the heap exists, free its memory */
    if(myHeap != NULL){
        /* If the data memory was previously allocated, free it */
        if(myHeap->data != NULL){
            free(myHeap->data);
        }
        free(myHeap);
    }
}

bool empty(Heap* myHeap) {
    /* Return true if myheap size is not 0 */
    return myHeap->currentSize == 0;
}

int min(Heap* myHeap) {
    int currentMin = -1;
    int minIndex = 0;
    /* NULL check heap pointer */
    if(myHeap == NULL){
        return currentMin;
    }
    /* If there is at least one element in the heap, seg fault won't occur when accessing data array */
    if(myHeap->currentSize > 0){
        /* Start with current min as first value */
        currentMin = myHeap->data[0];
        /* Find if there is a value smaller than the first element */
        for(int i = 0; i < myHeap->currentSize; i++){
            if(myHeap->data[i] < currentMin){
                currentMin = myHeap->data[i];
                minIndex = i;
            }
        }
        /* Put new minimum in position 0 */
        swap(myHeap, 0, minIndex);
    }
    /* Return smallest value in data array */
    return currentMin;
}

void deletemin(Heap* myHeap) {
    if(myHeap != NULL){
        if(myHeap->currentSize == 0){
            /* If no elements, do nothing */
            return;
        }else if(myHeap->currentSize == 1){
            /* If there is only one element, decrement size */
            myHeap->currentSize--;
            return;
        }else{
            /* Swap first element with last element */
            swap(myHeap, 0, myHeap->currentSize - 1);
            /* Decrement size to make that value as deleted */
            myHeap->currentSize--;
            /* Downheap heap to validate order */
            downheap(myHeap, 0);
        }
    }
}
 
void downheap(Heap* myHeap, int i) {
    int leftIndex = leftChild(i);
    int rightIndex = rightChild(i);
    /* index i has no children */
    if(leftIndex >= myHeap->currentSize){
        return;
    }
    /* Set minIndex to be index of i's smallest child */
    int minIndex = myHeap->data[leftIndex] > myHeap->data[rightIndex] ? rightIndex : leftIndex;
    /* If i's value is larger than its minimum child */
    if(myHeap->data[i] > myHeap->data[minIndex]){
        /* Swap i and i's smallest child */
        swap(myHeap, i, minIndex);
        /* Validate current heap position */
        downheap(myHeap, minIndex);
    }
}

void insert(int x, Heap* myHeap) {
    /* NULL check heap */
    if(myHeap == NULL){
        return;
    }

    /* If size is at max, cannot insert new value */
    if(myHeap->currentSize == myHeap->maxSize){
        return;
    }

    /* Set x value in heap data */
    myHeap->data[myHeap->currentSize] = x;
    /* Increment size */
    myHeap->currentSize++;
    /* Upheap heap to validate order */
    upheap(myHeap, myHeap->currentSize - 1);
}

void upheap(struct Heap* myHeap, int i) {
    int parentIndex = parent(i);
    if(parentIndex < 0){
        /* If new value has no parent (first val), do nothing */
        return;
    }
    int parentVal = myHeap->data[parentIndex];
    if(parentVal <= myHeap->data[i]){
        /* If parent is less than current, heap conditions pass */
        return;
    }
    /* If not, swap parent and current value */
    swap(myHeap, i, parentIndex);
    /* Upheap from parent's old index (current's new index) */
    upheap(myHeap, parentIndex);
}

int parent(int n) {
    /* Parent equation from lecture */
    return (n - 1) / 2;
}

int leftChild(int n) {
    /* Left child equation from lecture */
    return (n + 1) * 2 - 1;
}

int rightChild(int n) {
    /* Right child equation from lecture */
    return (n + 1) * 2;
}

void swap(Heap* myHeap, int i, int j) {
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
    int temp = myHeap->data[i];
    myHeap->data[i] = myHeap->data[j];
    myHeap->data[j] = temp;
}

/* A gift to the student: */
void printHeap(Heap *myHeap) {
    printf("Heap Current Size: %d\n", myHeap->currentSize);
    printf("Heap Max Size: %d\n", myHeap->maxSize);
    printf("Contents:\n");
    for (int i = 0; i < myHeap->currentSize; i++) {
        printf("%d ", myHeap->data[i]);
    }
    printf("\n");
} /* Thanks! */
