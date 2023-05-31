/**
	@file
	@author Mark Boady <mwb33@drexel.edu>
	@date 2023
	@section DESCRIPTION
 
	This file contains the interface for a heap data structure specialized for huffman encoding.
 
 */

#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "huffmanBST.h"

/**
 * @brief Calculates the huffman codes for the given file.
 * Prints huffman codes in markdown table format.
 * Only considers characters from 0 to 127 inclusive
 * 
 * @param filename file to read
 */
void huffman(char *filename);

/**
 * @brief determine the huffman codes for the Binary search tree
 * 
 * @param A array to store huff codes (character values = indices)
 * @param current current Node
 * @param code current huffman code for the node
 */
void getHuffmanCodes(int *A, Node *current, int code);

/**
	A structure to represent a heap (Priority Queue / Min Heap) Data Structure.
 */
typedef struct Heap Heap;
struct Heap{
	BST **data;/**< A pointer to your array of trees. */
	int maxSize;/**< The maximum size of the heap before it needs to be resized.*/
	int currentSize;/**< The current number of items in the array. */
};

/**
 Create a new empty Heap
 @return A pointer to the new heap
 */
Heap* newHeap(int capacity);

/**
 Free all memory used by the heap
 @param myHeap is the heap to free
 */
void deleteHeap(Heap* myHeap);

/**
 Ask if the heap is currently empty
 @param myHeap is a pointer to the heap
 @return true if empty and false otherwise
 */
bool emptyHeap(Heap* myHeap);


/**
 Delete the minimum from the heap
 @param myHeap is the heap to delete from
 */
void deleteHeapMin(Heap* myHeap);

/**
 Downheap starting at the node at index i
 @param myHeap is the heap to modify
 @param i is the index to start from
 */
void downHeap(Heap* myHeap, int i);

/**
 Insert value x into the Heap
 @param x is the value to insert
 @param myHeap is the heap to insert into
 */
void heapInsert(float value, char name, BST* T, Heap* myHeap);

/**
 Upheap starting at node indexed to i
 @param myHeap is the heap to fix
 @param i is the index of the node to start upheaping at
 */
void upHeap(struct Heap* myHeap,int i);

/**
 What is the index of node n's parent?
 @param n is the child node's index
 @return n's parent's index
 */
int heapNodeParent(int n);

/**
 What index contains the left child of n?
 @param n is the index of the parent
 @return the index of the left child of n
 */
int heapNodeLeftChild(int n);

/**
 What index contains the right child of n?
 @param n is the index of the parent
 @return the index of the right child of n
 */
int heapNodeRightChild(int n);

/**
 Swap the values at indexes i and j in the heap.
 @param myHeap is the heap to modify
 @param i is the first index to swap
 @param j is the second index to swap with
 */
void heapSwap(Heap* myHeap, int i, int j);

/**
 This function prints the heap and will help you debug.
 @param myHeap is the heap to print
 */
void printHeap(Heap* myHeap);

/**
 * @brief Prints out binary value of integer, skips leading zeros for nonzero inputs
 * 
 * @param num number to print out in binary
 */
void printBin(int num);

#endif
