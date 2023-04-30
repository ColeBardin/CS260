#/**
  @file linkedlist.h
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 27, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#pragma once

#include <stdbool.h>

typedef struct Node Node;
struct Node {
    char *word;
    Node *next;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
    Node *head;
    Node *tail;
};

LinkedList *newLinkedList();
void deleteLinkedList(LinkedList *list);
void insert(char *word, LinkedList *list);
void pop(LinkedList *list);
bool contains(char *word, LinkedList *list);
void printList(LinkedList *list);