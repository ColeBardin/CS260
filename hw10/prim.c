/**
    @file prim.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 06, 2023
    @section DESCRIPTION
    This file contains the Prim's algorithm function and helper functions. It reads a file that describes a graph along with a staring node.
    Uses Prim's algorithm to find the MST of the graph, outputting its steps to STDOUT.
    Stores the MST nodes in a LinkedList and uses a Heap to sort bridging Edges. 
    Does permanently store the MST edges, it just prints out what they are as it selects them.
    Outputs the total MST weight.
 */

#include "prim.h"
#include <stdio.h>

void prim(char *filename, int startingNode) {
    FILE *file; /* File pointer for graph description */

    /* Attempt to open the file from the user */
    if((file = fopen(filename, "r")) == NULL){
        printf("ERROR: Could not open file: %s\n", filename);
        return;
    }

    /* Print out runtime stats */
    printf("Running Prim's Algorithm\n");
    printf("Input File: %s\n", filename);
    printf("Starting Node: %d\n", startingNode);

    int numNodes;
    /* Get the number of expected nodes from the file */
    if(fscanf(file, "%d", &numNodes) < 1){
        /* If fscanf fails to read number from first line, close file and return */
        printf("ERROR: Failed reading number of nodes from file: %s\n", filename);
        fclose(file);
        return;
    }

    /* Create an Adjacency Matrix for tracking edges */
    int **adjMatrix = makeAdjMatrix(numNodes);
    if(adjMatrix == NULL){
        /* If adjMatrix init fails, close file and return */
        printf("ERROR: Failed to initialize an adjacency matrix of size %d\n", numNodes);
        fclose(file);
        return;
    }
    
    int fromNode, toNode, weight; /* Variables to hold information about each edge while being read from file */
    /* Add all edges from file to Adjacency Matrix */
    while(fscanf(file, "%d %d %d", &fromNode, &toNode, &weight) > 0){
        adjMatrix[fromNode][toNode] = weight;
        adjMatrix[toNode][fromNode] = weight;
    }
    /* File is no longer needed */
    fclose(file);

    /* Create Heap for sorting bridging edges */
    Heap *bridgingEdgesHeap = newPrimHeap(numNodes*numNodes);
    if(bridgingEdgesHeap == NULL){
        /* If Heap init fails, free Adjacency Matrix and return */
        printf("ERROR: Failed to allocate memory for heap\n");
        deleteAdjMatrix(adjMatrix, numNodes);
        return;
    }

    /* Create LinkedList for tracking nodes in the MST */
    LinkedList *nodesInMST = newLinkedList();
    if(nodesInMST == NULL){
        /* If LinkedList init fails, free Adjacency Matrix, free Heap, and return */
        printf("ERROR: Failed to initialize LinkedList\n");
        deleteAdjMatrix(adjMatrix, numNodes);
        deletePrimHeap(bridgingEdgesHeap);
        return;
    }

    /* Add user given starting node to MST */
    linkedListInsert(startingNode, nodesInMST);    

    int totalWeight = 0; /* Tracks the total weight of the MST edges */

    /* Repeat until all nodes are in the MST */
    while(lengthLinkedList(nodesInMST) != numNodes){
        /* Find bridging nodes and place them into Heap */
        findBridgingNodes(bridgingEdgesHeap, nodesInMST, numNodes, adjMatrix);

        /* Get smallest weighted bridging edge from Heap, which is the first element */
        fromNode = bridgingEdgesHeap->data[0]->nodeA;
        toNode = bridgingEdgesHeap->data[0]->nodeB;
        weight = bridgingEdgesHeap->data[0]->weight;

        /* Print out newly added Node and the Edge used */
        printf("Added %d\n", toNode);
        /* Printing format: (smallerEdgeName, largerEdgeName) edgeWeight*/
        printf("Using Edge (%d, %d) with weight %d\n", toNode > fromNode ? fromNode : toNode, toNode > fromNode ? toNode : fromNode, weight);

        /* Add new Node to MST Node Linked List*/
        linkedListInsert(toNode, nodesInMST);
        /* Track weight of new edge being added to MST */
        totalWeight += weight;
    }

    /* Display MST total weight */
    printf("Total Weight: %d\n", totalWeight);

    /* Free all memory used in data structures */
    deletePrimHeap(bridgingEdgesHeap);
    deleteAdjMatrix(adjMatrix, numNodes);
    deleteLinkedList(nodesInMST);
}

int **makeAdjMatrix(int size) {
    /* Allocate size# of array of int pointers*/
    int **new = malloc(sizeof(int *) * size);
    if(new == NULL){
        return NULL;
    }

    /* For each int pointer, allocate an array of ints of length size */
    for(int i = 0; i < size; i++){
        new[i] = malloc(sizeof(int) * size);
        if(new[i] == NULL){
            /* If any malloc fails, free memory used for successful calls */
            for(int j = 0; j < i; j++){
                free(new[j]);
            }
            free(new);
            return NULL;
        }
        /* Set default value to be -1 for all cells */
        for(int j = 0; j < i; j++){
            new[i][j] = -1;
        }
    }
    
    return new;
}

void deleteAdjMatrix(int **A, int size) {
    if(A != NULL){
        /* Free each array of ints */
        for(int i = 0; i < size; i++){
            free(A[i]);
        }
        /* Free the double pointer */
        free(A);
    }
}

void findBridgingNodes(Heap *destHeap, LinkedList *MST, int numNodes, int **adjMatrix) {
    /* Clear data array of destination Heap */
    primHeapClear(destHeap);
    /* Iterate over each unique edge pair */
    for(int i = 0; i < numNodes; i++){
        for(int j = 0; j < i; j++){
            /* If there is a valid edge for this pair of nodes */
            if(adjMatrix[i][j] > 0){
                if(linkedListContains(i, MST) && !linkedListContains(j, MST)){
                    /* If i is in MST and j is not, insert edge */
                    primHeapInsert(i, j, adjMatrix[i][j], destHeap);
                }else if(!linkedListContains(i, MST) && linkedListContains(j, MST)){
                    /* If j is in MST and i is not, insert edge */
                    primHeapInsert(j, i, adjMatrix[i][j], destHeap);
                }
                /* Insertions are ordered such that nodeA is node in MST, and nodeB is new node (within Edge struct members) */
            }
        }
    }
}
