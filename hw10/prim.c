/**
    @file prim.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 06, 2023
    @section DESCRIPTION
    Write a description of what this file contains here.
 */

#include "prim.h"
#include "primHeap.h"
#include "linkedList.h"
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

    Heap *heap = newPrimHeap(numNodes*numNodes);
    if(heap == NULL){
        printf("ERROR: Failed to allocate memory for heap\n");
        return;
    }

    int **adjMatrix = malloc(sizeof(int *) * numNodes);
    if(adjMatrix == NULL){
        printf("ERROR: Failed to allocate memory for adjacency matrix double pointer\n");
        deletePrimHeap(heap);
        fclose(file);
        return;
    }
    for(int i = 0; i < numNodes; i++){
        adjMatrix[i] = malloc(sizeof(int) * numNodes);
        if(adjMatrix[i] == NULL){
            printf("ERROR: Failed to allocate memory for adjacency matrix single pointer\n");
            for(int j = 0; j < i; j++){
                free(adjMatrix[j]);
            }
            free(adjMatrix);
            deletePrimHeap(heap);
            fclose(file);
            return;
        }
        for(int j = 0; j < numNodes; j++){
            adjMatrix[i][j] = -1;
        }
    }
    /* Add all edges into adj matrix */
    int fromEdge, toEdge, weight;
    while(fscanf(file, "%d %d %d", &fromEdge, &toEdge, &weight) > 0){
        adjMatrix[fromEdge][toEdge] = weight;
        adjMatrix[toEdge][fromEdge] = weight;
    }
    fclose(file);

    LinkedList *MSTNodes = newLinkedList();
    linkedListInsert(startingNode, MSTNodes);    

    int totalWeight = 0;
    while(lengthLinkedList(MSTNodes) != numNodes){
        for(int i = 0; i < numNodes; i++){
            for(int j = 0; j < i; j++){
                if(adjMatrix[i][j] > 0){
                    if(linkedListContains(i, MSTNodes) && !linkedListContains(j, MSTNodes)){
                        primHeapInsert(i, j, adjMatrix[i][j], heap);
                    }else if(!linkedListContains(i, MSTNodes) && linkedListContains(j, MSTNodes)){
                        primHeapInsert(j, i, adjMatrix[i][j], heap);
                    }
                }
            }
        }

        fromEdge = heap->data[0]->nodeA;
        toEdge = heap->data[0]->nodeB;
        weight = heap->data[0]->weight;
        printf("Added %d\n", toEdge);
        printf("Using Edge (%d, %d) with weight %d\n", toEdge > fromEdge ? fromEdge : toEdge, toEdge > fromEdge ? toEdge : fromEdge, weight);
        linkedListInsert(toEdge, MSTNodes);
        primHeapClear(heap);
        totalWeight += weight;
    }

    printf("Total Weight: %d\n", totalWeight);

    for(int i = 0; i < numNodes; i++){
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    deleteLinkedList(MSTNodes);
    deletePrimHeap(heap);
}