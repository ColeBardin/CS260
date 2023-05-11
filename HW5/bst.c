/**
  @file bst.c
  @author Cole Bardin <cab5721@drexel.edu>
  @date May 02, 2023
  @section DESCRIPTION
  Write a description of what this file contains here.
 */

#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

BST *newBST() {
    BST *new = malloc(sizeof(BST));
    new->root = NULL;
    return new;
}

void deleteBST(BST *T) {
    while(T->root != NULL){
        deleteFromTree(T, T->root->value);
    }

    free(T);
}

void insert(BST *T, int target) {
    T->root = insertValue(target, T->root);
}

bool find(BST *T, int target) {
    return findValue(target, T->root);
}

void deleteFromTree(BST *T, int target) {
    if(T->root->left == NULL && T->root->right == NULL && T->root->value == target){
        free(T->root);
        T->root = NULL;
    }else if(find(T, target) == true){
        /* TODO: verify*/
        T->root = deleteValue(target, T->root);
    }
}

int min(BST *T) {
    Node *current = T->root;
    int min = -1;

    while(current != NULL){
        min = current->value;
        current = current->left;
    }

    return min;
}

void inorder(BST *T) {
    inorderWalker(T->root);
    printf("\n");
}

void preorder(BST *T) {
    preorderWalker(T->root);
    printf("\n");
}

void postorder(BST *T) {
    postorderWalker(T->root);
    printf("\n");
}

int height(BST *T) {
    return nodeHeight(T->root);
}

void inorderWalker(Node *current) {
    /* left number right */
    if(current == NULL){
        return;
    }
    if(current->left == NULL && current->right == NULL){
        printf("%d ", current->value);
    }else if(current->left == NULL){
        printf("%d ", current->value);
        inorderWalker(current->right);
    }else if(current->right == NULL){
        inorderWalker(current->left);
        printf("%d ", current->value);
    }else{
        inorderWalker(current->left);
        printf("%d ", current->value);
        inorderWalker(current->right);
    }
}

void preorderWalker(Node *current) {
    /* node left right */
    if(current == NULL){
        return;
    }
    printf("%d ", current->value);
    if(current->left == NULL && current->right == NULL){
        return;
    }else if(current->left == NULL){
        preorderWalker(current->right);
    }else if(current->right == NULL){
        preorderWalker(current->left);
    }else{
        preorderWalker(current->left);
        preorderWalker(current->right);
    }
}

void postorderWalker(Node *current) {
    /* left right node */
    if(current == NULL){
        return;
    }
    if (current->left == NULL && current->right == NULL) {
        printf("%d ", current->value);
    } else if (current->left == NULL) {
        postorderWalker(current->right);
        printf("%d ", current->value);
    } else if (current->right == NULL) {
        postorderWalker(current->left);
        printf("%d ", current->value);
    } else {
        postorderWalker(current->left);
        postorderWalker(current->right);
        printf("%d ", current->value);
    }
}

Node *insertValue(int target, Node *current) {
    if(current == NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->value = target;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }else if(current->value == target){
        return current;
    }else if(target < current->value){
        current->left = insertValue(target, current->left);
        return current;
    }else{
        current->right = insertValue(target, current->right);
        return current;
    }
}

bool findValue(int target, Node *current) {
    if(current == NULL){
        return false;
    }else if(current->value == target){
        return true;
    }else if(target < current->value){
        return findValue(target, current->left);
    }else{
        return findValue(target, current->right);
    }
}

int findMin(Node *current) {
    if(current == NULL){
        return -1;
    }else if(current->left == NULL){
        return current->value;
    }else{
        return findMin(current->left);
    }
}

int nodeHeight(Node *current) {
    if(current->left == NULL && current->right == NULL){
        return 0;
    }else if(current->left == NULL){
        return nodeHeight(current->right) + 1;
    }else if(current->right == NULL){
        return nodeHeight(current->left) + 1;
    }else{
        int left = nodeHeight(current->left);
        int right = nodeHeight(current->right);
        if(left > right){
            /* If left is greater than right, return left + 1 */
            return left + 1;
        }else{
            /* If right is greater than or equal to left, return right + 1 */
            return right + 1;
        }
    }
}

Node *deleteValue(int target, Node *current) {
    if (current == NULL) {
        return NULL;
    } else if (current->value == target) {
        return deleteNode(current);
    } else if (target < current->value) {
        current->left = deleteValue(target, current->left);
        return current;
    } else {
        current->right = deleteValue(target, current->right);
        return current;
    }
}

Node *deleteNode(Node *current) {
    if(current->left == NULL && current->right == NULL){
        /* No children */
        free(current);
        return NULL;
    }else if(current->left == NULL){
        Node *temp = current->right;
        free(current);
        return temp;
    }else if(current->right == NULL){
        Node *temp = current->left;
        free(current);
        return temp;
    }else{
        if(current->right != NULL){
            int min = findMin(current->right);
            current->value = min;
            current->right = deleteValue(min, current->right);
            return current;
        }else{
            Node *temp = current->left;
            free(current);
            return temp;
        }
    }
}