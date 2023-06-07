/**
    @mainpage CS 260 - Homework 10
    @section Description
    This program implements Prim's algorithm to find the minimum spanning tree of a graph given a starting node
 
 */

/**
    @file main.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 06, 2023
    @section DESCRIPTION
    This file reads the user's input and implements Prims algorithm.
    It asks the user for a filename that desribes the graph as well as a node to start.
    Then, it uses Prims algorithm to find the MST of the graph.
 */

#include <stdio.h>
#include "prim.h"

int main() {
    char filename[64]; /* Input filename from user */
    int startingNode; /* Node to start at from user */

    /* Get filename from user */
    printf("Enter File Containing Graph:\n");
    if(scanf("%s", filename) < 1){
        printf("ERROR: Could not read filename from STDIN\n");
        return -1;
    }
    
    /* Get starting node from user */
    printf("Enter Starting Node:\n");
    if(scanf("%d", &startingNode) < 1){
        printf("ERROR: Could not read starting node from STDIN\n");
        return -2;
    }

    /* Start Prim's algorithm */
    prim(filename, startingNode);

    return 0;
}
