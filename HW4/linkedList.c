/**
  @file linkedList.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date April 27, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


LinkedList *newLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void deleteLinkedList(LinkedList *list) {
    Node *currentNode = list->head;
    Node *nextNode;

    while(currentNode != NULL){
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(list);
}

void insert(char *word, LinkedList *list) {
    Node *node = malloc(sizeof(Node));
    node->word = malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->next = NULL;

    if(list->tail == NULL){
        list->tail = node;
        list->head = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
}

bool contains(char *word, LinkedList *list) {
    Node *currentNode = list->head;

    while(currentNode != NULL){
        if(!strcmp(currentNode->word, word)){
            return true;
        }else{
            currentNode = currentNode->next;
        }
    }
    return false;
}

void printList(LinkedList *list) {
    if(list->head == NULL){
        printf("Empty List\n");
    }else{
        Node *currentNode = list->head;

        while(currentNode != NULL){
            printf("[\"%s\"]\n", currentNode->word);
            currentNode = currentNode->next;
        }
    }
}