/**
  @file heightExp.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date May 04, 2023
  @section DESCRIPTION
  This file contains a function that will generate 5 random BSTs for heights 2^N for N=1 to N=10
  It will calculate the average height for all 5 Trees of each size and print out a table with the results
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "bst.h"

#define NUMTESTS 5

void heightExperiments() {
    int N; /* Value for log2(Num of BST elements) */
    int testNum; /* Value to track 5 tests of each N value */
    int elements; /* Number of elements in BST, 2^N */
    int index; /* Counter for inserting elements into BST */
    float averageHeight; /* Keeps track of average height for each N value */

    /* Print out table header in MD table format */
    printf("Experiments (N=Number Element, Table Shows Height)\n");
    printf("| %7s | %7s | %7s | %7s | %7s | %7s | %7s |\n", "N", "T1", "T2", "T3", "T4", "T5", "Average");
    printf("| %7s | %7s | %7s | %7s | %7s | %7s | %7s |\n", "----", "-----", "-----", "-----", "-----", "-----", "-------");

    /* Repeat for N from 1 to 10, inclusive */
    for (N = 1; N < 11; N++) {
      /* Print out the N value in MD table format */
      printf("| %7d ", (int)pow(2, N));
      /* Reset average height for this N value */
      averageHeight = 0.0;
      /* Get the number of elements for this round of tests */
      elements = pow(2, N);
      /* Repeat for 5 tests */
      for (testNum = 1; testNum <= NUMTESTS; testNum++) {
        /* Create BST and insert 2^N random elements */
        BST *T = newBST();
        for (index = 0; index < elements; index++) {
          insert(T, rand());
        }

        /* Print out current height in MD table format */
        printf("| %7d ", height(T));

        /* Sum the height of each test for this N value */
        averageHeight += height(T);

        /* Delete the BST */
        deleteBST(T);
      }
      /* Divide by number of tests to get average height */
      averageHeight /= NUMTESTS;
      /* Output average height in MD table format with newline */
      printf("| %7.2f |\n", averageHeight);
    }

    return;
}