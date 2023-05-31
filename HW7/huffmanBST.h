/**
	@file
	@author Mark Boady <mwb33@drexel.edu>
	@date 2022
	@section DESCRIPTION
 
	This is a header file for a Binary Search Tree Class.
	Students will implement a related bst.c file to finish this assignment.
 */

/* You MAY NOT change this file */

#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

/* Type Definitions for the file */
typedef struct Node Node;
typedef struct BST BST;

/**
	A structure to represent a single node in a binary search tree.
 */
struct Node{
	float value; /**< The value at this point in the tree.*/
	char name; /**< Character for this node, -1 for no char.*/
	Node* left; /**< The left child of this node.*/
	Node* right; /**< The right child of this node.*/
};

/**
	A structure to represent a binary search tree.
 */
struct BST{
	Node* root; /**< The root node of the binary tree.*/
};

/* Front End Methods */
/* These method act on the TREE starting at the root */

/**
	Create a new empty Binary Search Tree
	@return Pointer to empty BST
 */
BST* newBST();

/**
	Free all the memory allocated to the BST
	@param T is the tree to delete from memory
 */
void deleteBST(BST* T);

BST *mergeBST(BST* firstMin, BST* secondMin);

bool find(BST *T, float target);

void deleteFromTree(BST *T, float target);

/**
	Insert a value into the BST. Ignore duplicates.
	@param T is the tree to insert into
	@param target is the value to insert
 */
void insert(BST* T, float target, char name);

/**
	Find the height of the tree.
	@param T is tree to check the height on
	@param The number of edges in longest path to root. -1 for null tree.
 */
int height(BST* T);

/**
	Insert a value starting at a node recursively.
	@param target is the value to insert
	@param current is the node to start at
	@return Updated pointer to node after changes
 */
Node* insertValue(float target, char name, Node* current);

/**
	Find a value in the tree starting at node recursively.
	@param target is the value to search for
	@param current is the node to start at
	@return True if found and False if not found
 */
bool findValue(float target, Node *current);

/**
	Find the minimum value starting at node recursively
	@param current is the node to start looking at
	@return The minimum of the section of the three starting at current
 */
float findMin(Node* current);

/**
	Find the height of a node. Null has height -1.
	@param current is the node to find the height of
	@return The height of the node in question
 */
int nodeHeight(Node* current);

/*
	Delete a value from the BST starting at node recursively.
	@param target is the value to delete
	@param current is the node to start at
	@return The updated node pointer
 */
Node* deleteValue(float target, Node* current);

/**
	Delete a specific node.
	@param current is the node to delete
	@return Updated pointer to replace node in the tree
 */
Node* deleteNode(Node* current);

void preorder(BST *T);
void inorder(BST *T);
void postorder(BST *T);

void preorderWalker(Node *current);
void postorderWalker(Node *current);
void inorderWalker(Node *current);


#endif
