/**
  @mainpage CS 260 - Homework 
  @section Description
  Describe how the entire program works. What is it for?
 
  */

 /**
   @file main.c
   @author Cole Bardin <cab5721@drexel.edu>
   @date May 11, 2023
   @section DESCRIPTION
   Write a description of what this file contains here.
  */
 
 #include "linkedList.h"
 #include <stdio.h>

 int main() {
    LinkedList *L = newLinkedList();
    for(int i = 0; i < 10; i++){
        insert(i, L);
    }
    printf("Start:\n");
    printList(L);
    reverse(L);
    printf("After reverse:\n");
    printList(L);
 }