/**
  @file heightExp.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date May 04, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "bst.h"

void heightExperiments() {
    int n, testNum, elements, index;
    float averageHeight;

    printf("Experiments (N=Number Element, Table Shows Height)\n");
    printf("| %7s | %7s | %7s | %7s | %7s | %7s | %7s |\n", "N", "T1", "T2", "T3", "T4", "T5", "Average");
    printf("| %7s | %7s | %7s | %7s | %7s | %7s | %7s |\n", "----", "-----", "-----", "-----", "-----", "-----", "-------");
    for (n = 1; n < 11; n++) {
      printf("| %7d ", (int)pow(2, n));
      averageHeight = 0.0;
      for (testNum = 1; testNum < 6; testNum++) {
        elements = pow(2, n);
        BST *T = newBST();
        for (index = 0; index < elements; index++) {
          insert(T, rand());
        }
        averageHeight += height(T);
        printf("| %7d ", height(T));

        deleteBST(T);
      }
      averageHeight /= 5;
      printf("| %7.2f |\n", averageHeight);
    }

    return;
}