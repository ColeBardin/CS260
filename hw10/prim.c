/**
    @file prim.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 06, 2023
    @section DESCRIPTION
    Write a description of what this file contains here.
 */

#include "prim.h"
#include "primHeap.h"
#include <stdio.h>

void prim(char *filename, int startingNode) {
    FILE *file;

    if((file = fopen(filename, "r")) == NULL){
        printf("ERROR: Could not open file: %s\n", filename);
        return;
    }

    printf("Running Prim's Algorithm\n");
    printf("Input File: %s\n", filename);
    printf("Starting Node: %d\n", startingNode);

    int numNodes;
    if(fscanf(file, "%d", &numNodes) < 1){
        printf("ERROR: Failed reading number of nodes from file: %s\n", filename);
        return;
    }
    printf("Number of nodes: %d\n", numNodes);

    Heap *heap = newPrimHeap(numNodes*numNodes);
    if(heap == NULL){
        printf("ERROR: Failed to allocate memory for heap\n");
        return;
    }

    int fromEdge, toEdge, weight;
    int edgeCount = 0;
    while(fscanf(file, "%d %d %d", &fromEdge, &toEdge, &weight) > 0){
        primHeapInsert(fromEdge, toEdge, weight, heap);
        edgeCount++;
    }
    printPrimHeap(heap);

    fclose(file);
}