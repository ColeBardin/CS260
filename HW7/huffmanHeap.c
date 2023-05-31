/**
    @file huffmanHeap.c
    @author Cole Bardin <cab5721@drexel.edu>
    @date May 16, 2023
    @section DESCRIPTION
    This file uses a Heap to implement Huffman Encoding
 */

#include "huffmanHeap.h"
#include <math.h>
#include <stdio.h>

void huffman(char *filename){
    FILE * file;
    char c;
    Heap *h;
    BST *node01;
    BST *node02;
    BST *new;
    
    int totalChars = 0;
    int charCount[128] = {0};
    float charPercent[128] = {0};
    int huffCode[128];

    /* Open fiile in reading mode */
    file = fopen(filename, "r");
    if(file == NULL){
    printf("Error opening file: %s\n", filename);
        return;
    }

    while((c = fgetc(file)) != EOF){
        /* Count every character between 0 and 127, inclusive */
        if(c >= 0 && c <= 127){
            charCount[c]++;
            /* Track total number of characters */
            totalChars++;
        }
    }

    /* Make new heap for all 128 characters */
    h = newHeap(128);
    for(int i = 0; i < 128; i++){
        if(charCount[i] > 0) {
            /* Calculate character percentages for found characters */
            charPercent[i] = (float)charCount[i] / totalChars;
            /* Insert new tree into heap for each character and its percent */
            heapInsert(charPercent[i], i, NULL, h);
        }
    }

    /* Repeat until there is one element left in the heap */
    while(h->currentSize != 1){
        /* Get minimum valued tree and remove it from heap */
        node01 = h->data[0];
        deleteHeapMin(h);
        /* Get next minimum valued tree and remove it from heap */
        node02 = h->data[0];
        deleteHeapMin(h);
        /* Merge first two minimum trees into a new tree */
        new = mergeBST(node01, node02); 
        /* Put the merged tree back into the heap */
        heapInsert(0, 0, new, h);
    }
    /* Convert Binary Tree into Huffman Codes*/
    getHuffmanCodes(huffCode, h->data[0]->root, 0);

    /* Print out results */
    printf("| ASCII | Percent | Code |\n");
    for(int i = 0; i < 128; i++){
        if(charCount[i] > 0.0){
            printf("| %5d | %7.5f | ", i, charPercent[i]);
            printBin(huffCode[i]);
            printf(" |\n");
        }
    }
    /* Free memory for Heap and Trees */
    deleteHeap(h);
}

void getHuffmanCodes(int *A, Node *current, int prev){
    if(current == NULL){
        /* End recursion if encoundered NULL node */
        return;
    }
    /* For non-character nodes */
    if(current->name == -1){
        /* Alter huffman code and recursivelt repeat on child nodes */
        getHuffmanCodes(A, current->left, prev << 1);
        getHuffmanCodes(A, current->right, (prev << 1) | 1);
    }else{
        /* Once a character node is reached, set value and end recursion */
        A[current->name] = prev;
        return;
    }
}

Heap* newHeap(int capacity) {
    /* Allocate memory and set default parameters */
    Heap* newHeap = malloc(sizeof(Heap));
    newHeap->data = malloc(sizeof(BST *) * capacity);
    newHeap->currentSize = 0;
    newHeap->maxSize = capacity;

    /* Error handle malloc call to heap data array */
    if(newHeap->data == NULL){
        /* Return NULL to indicate initialization error */
        return NULL;
    }else{
        /* If both malloc calls were successful, return struct pointer */
        return newHeap;
    }
}

void deleteHeap(Heap* myHeap) {
    /* If the heap exists, free its memory */
    if(myHeap != NULL){
        /* If the data memory was previously allocated, free it */
        if(myHeap->data != NULL){
            /* Delete all the BSTs stored in data array */
            for(int i = 0; i < myHeap->currentSize; i++){
                deleteBST(myHeap->data[i]);
            }
            free(myHeap->data);
        }
        free(myHeap);
    }
}

bool emptyHeap(Heap* myHeap) {
    /* Return true if myheap size is not 0 */
    return myHeap->currentSize == 0;
}

void deleteHeapMin(Heap* myHeap) {
    if(!emptyHeap(myHeap)){
        /* Swap first element with last element */
        heapSwap(myHeap, 0, myHeap->currentSize - 1);
        /* Decrement size to make that value as deleted */
        myHeap->currentSize--;
        /* Downheap heap to validate order */
        downHeap(myHeap, 0);
    }
}
 
void downHeap(Heap* myHeap, int i) {
    int leftIndex = heapNodeLeftChild(i);
    int rightIndex = heapNodeRightChild(i);
    int minIndex;
    /* index i has no children */
    if(leftIndex >= myHeap->currentSize){
        return;
    }
    
    if(rightIndex >= myHeap->currentSize){
        /* Min index is left child if right child doesn't exist */
        minIndex = leftIndex;
    }else{
        /* Choose smallest value if both children exist */
        minIndex = myHeap->data[leftIndex]->root->value > myHeap->data[rightIndex]->root->value ? rightIndex : leftIndex;
    }

    /* If i's value is larger than its minimum child */
    if(myHeap->data[i]->root->value > myHeap->data[minIndex]->root->value){
        /* Swap i and i's smallest child */
        heapSwap(myHeap, i, minIndex);
        /* Validate current heap position */
        downHeap(myHeap, minIndex);
    }
}

void heapInsert(float value, char name, BST* T, Heap* myHeap) {
    /* NULL check heap */
    if(myHeap == NULL){
        return;
    }

    /* If size is at max, cannot insert new value */
    if(myHeap->currentSize == myHeap->maxSize){
        printf("Warning! Cannot insert into full Heap\n");
        return;
    }

    if(T == NULL){
        /* Set x value in heap data */
        BST *new = newBST();
        insert(new, value, name);
        myHeap->data[myHeap->currentSize] = new;
    }else{
        myHeap->data[myHeap->currentSize] = T;
    }
    /* Increment size */
    myHeap->currentSize++;
    /* Upheap heap to validate order */
    upHeap(myHeap, myHeap->currentSize - 1);
}

void upHeap(struct Heap* myHeap, int i) {
    int parentIndex = heapNodeParent(i);
    if(parentIndex < 0){
        /* If new value has no parent (first val), do nothing */
        return;
    }
    float parentVal = myHeap->data[parentIndex]->root->value;
    if(parentVal <= myHeap->data[i]->root->value){
            /* If parent is less than current, heap conditions pass */
            return;
    }
    /* If not, swap parent and current value */
    heapSwap(myHeap, i, parentIndex);
    /* Upheap from parent's old index (current's new index) */
    upHeap(myHeap, parentIndex);
}

int heapNodeParent(int n) {
    /* Parent equation from lecture */
    return (n - 1) / 2;
}

int heapNodeLeftChild(int n) {
    /* Left child equation from lecture */
    return n * 2 + 1;
}

int heapNodeRightChild(int n) {
    /* Right child equation from lecture */
    return n * 2 + 2;
}

void heapSwap(Heap* myHeap, int i, int j) {
    /* NULL check heap pointer */
    if(myHeap == NULL){
        return;
    }
    /* If there currently isn't 2 elements or heap cannot store 2 elements, cannot swap */
    if(myHeap->currentSize < 2 || myHeap->maxSize < 2){
        return;
    }
    /* If i or j is out of range of current num of elements, should not swap */
    if(j > myHeap->currentSize - 1 || i > myHeap->currentSize - 1){
        return;
    }
    /* If indices are the same, no need to swap */
    if(i == j){
        return;
    }
    /* Swap two integers in the array */
    BST *temp = myHeap->data[i];
    myHeap->data[i] = myHeap->data[j];
    myHeap->data[j] = temp;
}

/* A gift to the student: */
void printHeap(Heap *myHeap) {
    printf("Size: %d of %d\n", myHeap->currentSize, myHeap->maxSize);
    printf("Contents:\n");
    for (int i = 0; i < myHeap->currentSize; i++) {
        printf("root: %d(%c) - %.5f\n", myHeap->data[i]->root->name, myHeap->data[i]->root->name, myHeap->data[i]->root->value);
    }
    printf("\n");
} /* Thanks! */

void printBin(int num) {
    bool print = false;
    for(unsigned i = 1 << 31; i > 0; i = i / 2){
        if(num & i){
            printf("1");
            print = true;
        }else if(print){
            printf("0");
        }
    }
    if(!print){
        printf("0");
    }
}