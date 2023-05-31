#include <stdio.h>
#include "huffmanHeap.h"

int main(){
    char filename[64];
    int ret;


    printf("Enter File Name to read:\n"); 
    ret = scanf("%s", filename);
    if(ret != 1){
        printf("Error reading filename\n");
        return -1;
    }
    huffman(filename);
    return 0;
}