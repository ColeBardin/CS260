/**
    @file bst.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date May 02, 2023
    @section DESCRIPTION
    
    This file includes a Binary Search Tree library focused on implementing huffman encoding.
 */

#include "huffmanBST.h"
#include <stdlib.h>
#include <stdio.h>

BST *newBST() {
    /* Allocate new binary search tree and set its root to NULL */
    BST *new = malloc(sizeof(BST));
    new->root = NULL;
    return new;
}

BST *mergeBST(BST* firstMin, BST* secondMin) {
    BST *new = newBST();
    insert(new, firstMin->root->value + secondMin->root->value, -1);
    new->root->left = firstMin->root;
    new->root->right = secondMin->root;
    return new;
}

void deleteBST(BST *T) {
    /* Repeatedly delete the root value until the Tree is empty */
    while(T->root != NULL){
        /* This call will also free memory of all the Nodes */
        deleteFromTree(T, T->root->value);
    }

    /* Free memory used for the Tree */
    free(T);
}

bool find(BST *T, float target) {
    /* Call recursive function to search through all nodes for the target */
    return findValue(target, T->root);
}

bool findValue(float target, Node *current) {
    /* Recusively find value from current node */
    if (current == NULL) {
        /* If reached a NULL node, the value does not exist in the Tree, return
         * false */
        return false;
    } else if (current->value == target) {
        /* If value is found, return true */
        return true;
    } else if (target < current->value) {
        /* If target is smaller than the current value, move left */
        return findValue(target, current->left);
    } else {
        /* If target is larger than the current value, move right */
        return findValue(target, current->right);
    }
}

void deleteFromTree(BST *T, float target) {
    /* If the value exists in the tree */
    if (find(T, target) == true) {
        /* Call recursive function to delete it, starting from the root */
        T->root = deleteValue(target, T->root);
    }
}

void insert(BST *T, float target, char name) {
    /* Insert integer and save return value as new root */
    T->root = insertValue(target, name, T->root);
}

Node *insertValue(float target, char name, Node *current) {
    if(current == NULL){
        /* When arrived at proper insert location, allocate memory and populate data */
        Node* newNode = malloc(sizeof(Node));
        newNode->value = target;
        newNode->name = name;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }else if(current->value == target){
        /* If value already exists, skip insertion */
        return current;
    }else if(target < current->value){
        /* Move to the left if current node is larger than insert target value */
        current->left = insertValue(target, name, current->left);
        return current;
    }else{
        /* Move to the right if current node is smaller than insert target value */
        current->right = insertValue(target, name, current->right);
        return current;
    }
}

float findMin(Node *current) {
    /* Recursively search move left through the Tree to find the minimum value */
    if(current == NULL){
        /* If passed NULL node by user, return error */
        printf("Error: Cannot find minimum with NULL root\n");
        return -1.0;
    }else if(current->left == NULL){
        /* If the left value is NULL, this is the minimum */
        return current->value;
    }else{
        /* If left is not NULL, there is a smaller value in Tree */
        return findMin(current->left);
    }
}

Node *deleteValue(float target, Node *current) {
    /* Recursive method to find and delete a value from the tree */
    if(current == NULL){
        /* If current node is NULL, value is not found */
        return NULL;
    }else if(current->value == target){
        /* If value is found, delete the Node */
        return deleteNode(current);
    }else if(target < current->value){
        /* If the target is smaller than the current one, move left down the tree */
        current->left = deleteValue(target, current->left);
        return current;
    }else{
        /* If targer is larger than the current one, move right down the tree */
        current->right = deleteValue(target, current->right);
        return current;
    }
}

Node *deleteNode(Node *current) {
    if(current->left == NULL && current->right == NULL){
        /* If no children, free memory and replace node with NULL */
        free(current);
        return NULL;
    }else if(current->left == NULL){
        /* If left side is NULL, replace this node with right side */
        Node *temp = current->right;
        free(current);
        return temp;
    }else if(current->right == NULL){
        /* If right side is NULL, replace this node with left side */
        Node *temp = current->left;
        free(current);
        return temp;
    }else{
        /* If it has 2 children, replace this node with minimum value below it */
        float min = findMin(current->right);
        current->value = min;
        current->right = deleteValue(min, current->right);
        return current;
    }
}

void inorder(BST *T) {
    /* Call the recursive inoder printer method starting at the root */
    inorderWalker(T->root);
    /* Add newline at end of printing */
    printf("\n");
}

void preorder(BST *T) {
    /* Call the recursive preorder printer method starting at the root */
    preorderWalker(T->root);
    /* Add newline at end of printing */
    printf("\n");
}

void postorder(BST *T) {
    /* Call the recursive postorder printer method starting at the root */
    postorderWalker(T->root);
    /* Add newline at end of printing */
    printf("\n");
}

void inorderWalker(Node *current) {
    /* left number right */
    if (current == NULL) {
        /* End recursive branch at NULL node */
        return;
    }
    if (current->left == NULL && current->right == NULL) {
        /* If no children, print out current number */
        printf("%c:%.5f ", current->name, current->value);
    } else if (current->left == NULL) {
        /* If left side is NULL, print number then right side */
        printf("%c:%.5f ", current->name, current->value);
        inorderWalker(current->right);
    } else if (current->right == NULL) {
        /* If right side is NULL, print left side then number */
        inorderWalker(current->left);
        printf("%c:%.5f ", current->name, current->value);
    } else {
        /* If 2 children, print left, then number, then right */
        inorderWalker(current->left);
        printf("%c:%.5f ", current->name, current->value);
        inorderWalker(current->right);
    }
}

void preorderWalker(Node *current) {
    /* node left right */
    if (current == NULL) {
        /* End recursive branch at NULL node */
        return;
    }
    /* Otherwise, always print current value first */
    printf("%c:%.5f ", current->name, current->value);
    if (current->left == NULL && current->right == NULL) {
        /* End recursive branch if no children */
        return;
    } else if (current->left == NULL) {
        /* If left side is NULL, print out right */
        preorderWalker(current->right);
    } else if (current->right == NULL) {
        /* If right side is NULL, print out left */
        preorderWalker(current->left);
    } else {
        /* If 2 children, print left then right */
        preorderWalker(current->left);
        preorderWalker(current->right);
    }
}

void postorderWalker(Node *current) {
    /* left right node */
    if (current == NULL) {
        /* End recursive branch at NULL node */
        return;
    }
    if (current->left == NULL && current->right == NULL) {
        /* If no children, print current value */
        printf("%c:%.5f ", current->name, current->value);
    } else if (current->left == NULL) {
        /* If left side is NULL, print right side then current value */
        postorderWalker(current->right);
        printf("%c:%.5f ", current->name, current->value);
    } else if (current->right == NULL) {
        /* If right side is NULL, print left side then current value */
        postorderWalker(current->left);
        printf("%c:%.5f ", current->name, current->value);
    } else {
        /* If 2 children, print left side, then right side, then current value
         */
        postorderWalker(current->left);
        postorderWalker(current->right);
        printf("%c:%.5f ", current->name, current->value);
    }
}