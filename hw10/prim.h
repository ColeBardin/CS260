/**
    @file prim.h
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 06, 2023
    @section DESCRIPTION
    This header file defines the functions used to implement Prim's algorithm
 */

#pragma once

#include "linkedList.h"
#include "primHeap.h"

/**
 * @brief Implements Prim's algorithm on a graph
 * 
 * @param filename location of text file that describes number of nodes and edges
 * @param startingNode node to start algorithm at
 */
void prim(char *filename, int startingNode);

/**
 * @brief Allocates a size x size array of integers
 * 
 * @param size desired size of square matrix
 * @return int** valid pointer to matrix, NULL on failure
 */
int **makeAdjMatrix(int size);

/**
 * @brief Frees memory of an allocated size x size matrix
 * 
 * @param A adjacency matrix
 * @param size size of square matrix
 */
void deleteAdjMatrix(int **A, int size);

/**
 * @brief Find all bridging nodes from adjacency matrix and MST, add them to the Heap
 * 
 * @param dest heap to put bridging nodes into
 * @param MST list of nodes already in MST
 * @param numNodes number of nodes in graph
 * @param adjMatrix adjacency matrix describing graph's edges 
 */
void findBridgingNodes(Heap *dest, LinkedList *MST, int numNodes, int **adjMatrix);
