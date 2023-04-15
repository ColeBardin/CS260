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
	int swapped = 1; /* Flag for if a swap occurs */
	
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
	int i=1; /* Index to restrict already sorted indices */
	int j; /* Index of insert element */

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
	int middle; /* Index of middle element */

	/* Return if start stop indices are invalid */
	if(start >= stop){
		return;
	}

	/* Split array to perform merge sorting */
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

	int first[sizeFirst]; /* Array to hold copy of first half of source array */
	int second[sizeSecond]; /* Array to hold copy of second half of source array */

	int k; /* Index for source array */
	int i = 0; /* Index for first array */
	int j = 0; /* Index for second array */

	/* Copy first half of source array */
    for(k = start; k <= middle; k++){
        first[k - start] = A[k];
    }
	/* Copy second half of source array */
    for(k = middle + 1; k <= stop; k++){
        second[k - middle - 1] = A[k];
    }

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
		}else if(first[i] < second[j]){
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
	
	return;
}

/* Implement this function based on lecture */
void quickSort(int *A, int size) { 
	qusort(A, 0, size-1);
	return;
}

/* Implement this function based on lecture */
void qusort(int *A, int start, int stop) {
	int p; /* Partition index value */

	if(start < stop){
		p = partition(A, start, stop);
		qusort(A, start, p - 1);
		qusort(A, p + 1, stop);
	}
	return;
}

/* Implement this function based on lecture */
int partition(int *A, int start, int stop) { 
	int randomIndex; /* Variable for random index selection */
	int pivot; /* Pivot value chosen by random index */
	int i = start; /* Keeps track of partition index */
	int j; /* Index used to compare values to pivot */

	/* Generate random index within range start and stop, inclusive */
	randomIndex = (rand() / RAND_MAX) * (start - stop + 1) + start;
	/* Swap random element with last element */
	swap(A, randomIndex, stop);
	/* Set random element as pivot */
	pivot = A[stop];

	for(j = start; j < stop; j++){
		if(A[j] <= pivot){
			swap(A, i, j);
			i++;
		}
	}
	swap(A, i, stop);
	return i;
}

/* Swap element method */
void swap(int *A, int indexA, int indexB) {
	int temp = A[indexA];
	A[indexA] = A[indexB];
	A[indexB] = temp;
	return;
}

