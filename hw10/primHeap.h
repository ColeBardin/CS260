/**
	@file primHeap.h
	@author Cole Bardin <cab5721@drexel.edu>
	@date June 06, 2023
	@section DESCRIPTION
	Write a description of what this file contains here.
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
    A structure to represent an integer-weighted graph edge between two integer-named nodes
 */
typedef struct Edge Edge;
struct Edge{
	int weight; /**< Weight of the edge connection */
	int nodeA; /**< Name of one connecting node */
	int nodeB; /**< Name of other connecting node */
};

/**
	A structure to represent a heap (Priority Queue / Min Heap) Data Structure.
 */
typedef struct Heap Heap;
struct Heap{
	Edge** data;/**< A pointer to your array of Edge pointers. */
	int maxSize;/**< The maximum size of the heap before it needs to be resized.*/
	int currentSize;/**< The current number of items in the array. */
};

/**
 Create a new empty Heap
 @return A pointer to the new heap
 */
Heap* newPrimHeap(int capacity);

/**
 Free all memory used by the heap
 @param myHeap is the heap to free
 */
void deletePrimHeap(Heap* myHeap);

/**
 Ask if the heap is currently empty
 @param myHeap is a pointer to the heap
 @return true if empty and false otherwise
 */
bool emptyHeap(Heap* myHeap);

/**
 What is the smallest value in the heap?
 @param myHeap is the heap to find min of
 @return The smallest value in the heap
 */
int primHeapMin(Heap* myHeap);

/**
 Delete the minimum from the heap
 @param myHeap is the heap to delete from
 */
void primHeapDeleteMin(Heap* myHeap);

/**
 Downheap starting at the node at index i
 @param myHeap is the heap to modify
 @param i is the index to start from
 */
void primDownHeap(Heap* myHeap, int i);

/**
 Insert value x into the Heap
 @param x is the value to insert
 @param myHeap is the heap to insert into
 */
void primHeapInsert(int nodeA, int nodeB, int weight, Heap* myHeap);

/**
 Upheap starting at node indexed to i
 @param myHeap is the heap to fix
 @param i is the index of the node to start upheaping at
 */
void primUpHeap(struct Heap* myHeap,int i);

/**
 What is the index of node n's parent?
 @param n is the child node's index
 @return n's parent's index
 */
int parent(int n);

/**
 What index contains the left child of n?
 @param n is the index of the parent
 @return the index of the left child of n
 */
int leftChild(int n);

/**
 What index contains the right child of n?
 @param n is the index of the parent
 @return the index of the right child of n
 */
int rightChild(int n);

/**
 Swap the values at indexes i and j in the heap.
 @param myHeap is the heap to modify
 @param i is the first index to swap
 @param j is the second index to swap with
 */
void primHeapSwap(Heap* myHeap, int i, int j);

/**
 This function prints the heap and will help you debug.
 @param myHeap is the heap to print
 */
void printPrimHeap(Heap* myHeap);

void primHeapClear(Heap* myHeap);
