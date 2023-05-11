package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

/*
3: 0.001 ms
4: 0.001 ms
5: 0.001 ms
6: 0.003 ms
7: 0.032 ms
8: 0.023 ms
9: 0.065 ms
10: 0.220 ms
11: 0.839 ms
12: 4.536 ms
13: 45.968 ms
14: 45.989 ms
15: 298.071 ms
16: 557.660 ms
17: 1480.923 ms
*/
func main() {
	/* Repeat for N = 3 to 17 */
	for N := 3; N <= 17 ; N++ {
		/* Create an array of 2^N random values */
		arr := generateRandomArray(int(math.Pow(2, float64(N))))

		/* Start the timer */
		start := time.Now()
		/* Implement quicksort algorithm */
		quickSort(arr)
		/* Stop the timer */
		elapsed := time.Since(start)

		/* Output the elapsed time in miliseconds */
		fmt.Printf("%d: %.3f ms\n", N, 1000 * elapsed.Seconds())
	}
}

/**
 @brief Creates an array of random values
 @param size length of the array
 @return []int Array of random elements
*/
func generateRandomArray(size int) []int {
	/* Create empty array of length size */
	arr := make([]int, size)

	/* Insert a random value at each index */
	for i := 0; i < size; i++ {
		/* Implement same random number generation as in HW2 code */
		arr[i] = rand.Int() % (size * 4)
	}

	return arr
}

/**
 @brief Implements quick sort algorithm on an array A
 @param A unsorted integer array
*/
func quickSort(A []int) {
	qusort(A, 0, len(A)-1)
}

/**
 @brief performs the quick sort algorithm recusively on an array
 @param A unsorted integer array
 @param start starting index
 @param stop stopping index
*/
func qusort(A []int, start, stop int) {
	/* Check if valid start and stop indices were given */
	if start < stop {
		/* Create partition */
		pivot := partition(A, start, stop)
		/* Individually quickSort each partition */
		qusort(A, start, pivot - 1)
		qusort(A, pivot + 1, stop)
	}
}

/**
 @brief Partition for Quick Sort. Use Randomized Index Selection Here
 @param A array to partition
 @param start the first index to use
 @param stop the last index to use
 @return int Index of the partition element
*/
func partition(A []int, start, stop int) int {
	i := start
	
	randomIndex := rand.Intn(len(A))
	/* Swap randomIndex and stop indices */
	A[randomIndex] += A[stop]
	A[stop] = -A[stop] + A[randomIndex]
	A[randomIndex] -= A[stop]

	/* Choose the pivot as the random value */
	pivot := A[stop]

	/* Iterate j through A */
	for j := start; j < stop; j++ {
		/* If current value is less than the random pivot */
		if A[j] <= pivot {
			/* Swap A[i] and A[j] */
			A[i] += A[j]
			A[j] = -A[j] + A[i] 
			A[i] -= A[j]
			/* Move forward in array */
			i++
		}
	}

	/* Swap i and stop indices */
	A[i] += A[stop]
	A[stop] = -A[stop] + A[i]
	A[i] -= A[stop]

	return i 
}

