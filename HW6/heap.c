/**
    @file heap.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date May 16, 2023
    @section DESCRIPTION
    This file implements the heap libray methods from heap.h
 */

#include "heap.h"
#include <math.h>

void heapSort(int* array, int size) {

}

Heap* makenull(int capacity) {
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
    /* NULL check heap pointer */
    if(myHeap != NULL){
        if(myHeap->currentSize != 0){
            /* Return element in position 0 */
            return myHeap->data[0];
        }else{
            /* If no elements in heap, return -1 */
            return -1;
        }
    }
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
    /* TODO */
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
    if(parent(i) < 0){
        /* If new value has no parent (first val), do nothing */
        return;
    }else if(myHeap->data[parent(i)] <= myHeap->data[i]){
        /* If parent is less than current, heap conditions pass */
        return;
    }else{
        /* If not, swap parent and current value */
        swap(myHeap, i, parent(i));
        /* Upheap from parent's old index (current's new index) */
        upheap(myHeap, parent(i));
    }

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
    /* Swap two integers in the array */
    int temp = myHeap->data[i];
    myHeap->data[i] = myHeap->data[j];
    myHeap->data[j] = temp;
}

void printHeap(Heap* myHeap) {

}
