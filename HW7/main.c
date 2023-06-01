/**
    @mainpage CS 260 - Homework 7
    @section Description
    Describe how the entire program works. What is it for?
    This program calculates the huffman encoding values for a text file.
    It uses a heap of custom binary search trees to organize the data and calculate huffman codes
    Given a filename, it will output the ASCII value, percent occurance, and binary huffman code for all characters between 0 and 127 inclusive. 
 */
/**
    @file main.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date May 31, 2023
    @section DESCRIPTION
    Write a description of what this file contains here.
    Get the filename from the user and start huffman code process.
 */

#include <stdio.h>
#include "huffmanHeap.h"

int main(){
    char filename[64]; /* Filename string, up to 63 characters */

    /* Get filename from user */
    printf("Enter File Name to read:\n"); 
    if(scanf("%s", filename) != 1){
        printf("Error reading filename\n");
        return -1;
    }
    /* Calculate huffman codes */
    huffman(filename);
    return 0;
}