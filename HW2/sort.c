/**
        @file
        @author Mark Boady <mwb33@drexel.edu>
        @date July 20, 2022
        @section DESCRIPTION

        For your homework assignment, you must implement all the unfinished
   functions provided in this file.

        You may add new functions, but you may not change the function
   signatures of anything provided.

 */

#include "sort.h"
#include "stdio.h"
#include "stdlib.h"

/* Implement this function based on lecture */
void bubbleSort(int *A, int size) {
	unsigned int index; /* Variable to index the array */
	uint8_t swapped = 1; /* Flag for if a swap occurs */
	
	while(swapped == 1){ 
		/* Unset swapped flag for this sort iteration */
		swapped = 0;
		/* Iterate through the array */
		for(index = 0; index < size - 1; index++){
			/* Determine if the current value is in the wrong place */
			if(A[index] > A[index + 1]){
				/* Set swapped flag */
				swapped = 1;
				/* Swap the two elements */
				swap(A, index, index + 1);
			}
		}
	}
	return;
}

/* Implement this function based on lecture */
void insertSort(int *A, int size) { 
	int i=1;
	int j;

	while(i < size){
		j=i;
		while((j > 0) && (A[j-1] > A[j])){
			swap(A, j - 1, j);
			j -= 1;
		}
		i++;
	}

	return;
}

/* Implement this function based on lecture */
void mergeSort(int *A, int size) { 
	msort(A, 0, size-1);
}

/* Implement this function based on lecture */
void msort(int *A, int start, int stop) {
	int middle;

	/* Return if start stop indices are invalid */
	if(start >= stop){
		return;
	}
	middle = start + (stop-start) / 2;
	msort(A, start, middle);
	msort(A, middle + 1, stop);
	
	/* Merge array back into correct order */
	merge(A, start, middle, stop);
}

/* Implement this function based on lecture */
void merge(int *A, int start, int middle, int stop) { 
	int sizeFirst = middle - start + 1;	/* Size of first array */
	int sizeSecond = stop - middle; /* Size of second array */

	int *first = arrayCopy(A, start, middle); /* Copy of first half of source array */
	int *second = arrayCopy(A, middle + 1, stop); /* Copy of second half of source array */

	int k; /* Index for source array */
	int i = 0; /* Index for first array */
	int j = 0; /* Index for second array */

	/* Merging */
	for(k = start; k <= stop; k++){
		/* Options: */
		if(i >= sizeFirst){
			/* Nothing left in first array */
			A[k] = second[j];
			j++;
		}else if(j >= sizeSecond){
			/* Nothing is left in second array */
			A[k] = first[i];
			i++;
		}else if(first[i] < second[j]) {
			/* Element in first array is less than second */
			A[k] = first[i];
			i++;			
		//}else if(first[i] > second[j]){
		}else{
			/* Element in second array is less than first */
			A[k] = second[j];
			j++;
		}
	}
	/* Free memory of copied arrays */
	free(first);
	free(second);
	
	return;
}

/* Implement this function based on lecture */
void quickSort(int *A, int size) { 
	qusort(A, 0, size-1);
	return;
}

/* Implement this function based on lecture */
void qusort(int *A, int start, int stop) {
	if(start >= stop) {
		return;
	}
	int p = partition(A, start, stop);
	qusort(A, start, p-1);
	qusort(A, p, stop);
	return;
}

/* Implement this function based on lecture */
int partition(int *A, int start, int stop) { return 0; }

/* Swap element method */
void swap(int *A, int indexA, int indexB) {
	A[indexB] += A[indexA];
	A[indexA] = A[indexB] - A[indexA];
	A[indexB] -= A[indexA];
	return;
}

int *arrayCopy(int *A, int start, int stop) {
	int length;
	int *copied;
	int index;
	
	/* Error handle input indices, if start == stop, then only copy 1 element */
	if (stop < start) {
		return NULL;
	}

	/* Calculate length of  array to copy */
	length = stop - start + 1;
	copied = (int *)malloc(length * sizeof(int));
	/* Error handle malloc call */
	if (copied == NULL) {
		return NULL;
	}
	
	/* Copy array values into new array */
	for (index = 0; index <= length; index++) {
		copied[index] = A[start + index];
	}

	/* Return copied array pointer */
	return copied;	
}
