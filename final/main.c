/**
    @mainpage CS 260 - Final Skill Assessment
    @section Description
    Describe how the entire program works. What is it for?
 
 */
 
/**
    @file main.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date June 12, 2023
    @section DESCRIPTION
    Write a description of what this file contains here.
 */

#include <stdio.h>
#include "bst.h"

int main(){
    BST *T1;
    BST *T2;
    int values[] = {9,1,6,3,4,2,5,7,0,8};
    int diff[] = {9,1,6,3,4,2,5,7,0,11};

    printf("Testing two identical trees\n");
    T1 = newBST();
    T2 = newBST();
    for(int i = 0; i < 10; i++){
        insert(T1, values[i]);
        insert(T2, values[i]);
    }
    printf("Result: %d\n", identical(T1, T2));
    deleteBST(T1);
    deleteBST(T2);
    
    printf("Testing two different trees\n");
    T1 = newBST();
    T2 = newBST();
    for(int i = 0; i < 10; i++){
        insert(T1, values[i]);
        insert(T2, diff[i]);
    }
    printf("Result: %d\n", identical(T1, T2));
    deleteBST(T1);
    deleteBST(T2);

    return 0;
}
