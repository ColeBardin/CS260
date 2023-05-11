package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

/*
3: 0.000 ms
4: 0.000 ms
5: 0.000 ms
6: 0.000 ms
7: 0.000 ms
8: 0.501 ms
9: 0.000 ms
10: 0.000 ms
11: 0.497 ms
12: 1.000 ms
13: 4.500 ms
14: 11.000 ms
15: 80.612 ms
16: 725.197 ms
17: 775.202 ms
*/
func main() {
	/* Repeat for N = 3 to 17 */
	for N := 3; N <= 17 ; N++ {
		/* Create an array of 2^N random values */
		arr := generateRandomArray(int(math.Pow(2, float64(N))))

		/* Start the timer */
		start := time.Now()
		/* Implement quicksort algorithm */
		quickSort(arr, 0, len(arr)-1)
		/* Stop the timer */
		elapsed := time.Since(start)

		/* Output the elapsed time in miliseconds */
		fmt.Printf("%d: %.3f ms\n", N, 1000 * elapsed.Seconds())
	}
}

// Generates an array of unique random values
func generateRandomArray(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = i + 1
	}

	// Shuffle the array using Fisher-Yates algorithm
	rand.Seed(time.Now().UnixNano())
	for i := len(arr) - 1; i > 0; i-- {
		j := rand.Intn(i + 1)
		arr[i], arr[j] = arr[j], arr[i]
	}

	return arr
}

func quickSort(A []int, start, stop int) {
	/* Check if valid start and stop indices were given */
	if start < stop {
		/* Create partition */
		pivot := partition(A, start, stop)
		/* Individually quickSort each partition */
		quickSort(A, start, pivot-1)
		quickSort(A, pivot+1, stop)
	}
}

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

