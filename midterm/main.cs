using System;
using System.Diagnostics;

class QuickSort
{
    static void Main()
    {
        /* Iterate for N=3 to 17 */
        for(int N = 3; N <= 17; N++){
            /* Create an array of 10 random values */
            int[] A = makeRandomArray((int)Math.Pow(2, N));

            /* Start the timer */
            Stopwatch stopwatch = Stopwatch.StartNew();

            /* Implement quicksort algorithm */
            quickSort(A);

            /* Stop the timer  */
            stopwatch.Stop();
            TimeSpan elapsedTime = stopwatch.Elapsed;

            /* Output results */
            Console.WriteLine($"{N}: {elapsedTime.TotalMilliseconds} ms");
        }
    }


    /**
     @brief Implements quick sort algorithm on an array A
     @param A unsorted integer array
    */
    static void quickSort(int[] A){
        qusort(A, 0, A.Length - 1);
    }

    /**
     @brief performs the quick sort algorithm recusively on an array
     @param A unsorted integer array
     @param start starting index
     @param stop stopping index
    */
    static void qusort(int[] A, int start, int stop){
        /* Check if valid start and stop indices were given */
        if (start < stop){
            /* Create partition */
            int pivotIndex = partition(A, start, stop);
            /* Individually quickSort each partition */
            qusort(A, start, pivotIndex - 1);
            qusort(A, pivotIndex + 1, stop);
        }
    }

    /**
     @brief Partition for Quick Sort. Use Randomized Index Selection Here
     @param A array to partition
     @param start the first index to use
     @param stop the last index to use
     @return int Index of the partition element
    */
    static int partition(int[] A, int start, int stop){
        /* Start at the beginning of this section */
        int i = start;

        /* Swap randomIndex and stop indices */
        Random random = new Random();
        int randomIndex = random.Next(0, A.Length);
        swap(A, randomIndex, stop);

        /* Choose the pivot as the random value */
        int pivot = A[stop];

        /* Iterate j through A */
        for (int j = start; j < stop; j++){
            /* If current value is less than the random pivot */
            if (A[j] < pivot){
                /* Swap A[i] and A[j] */
                swap(A, i, j);
                /* Move forward in array */
                i++;
            }
        }

        /* Swap i and stop indices */
        swap(A, i , stop);

        return i;
    }

    /*
	 @brief Swaps two elements in the array
	 @param A is the array to swap two elements in
	 @param indexA is the index of the first element
	 @param indexB is the index of the second element
    */
    static void swap(int[] A, int indexA, int indexB){
        int temp = A[indexA];
        A[indexA] = A[indexB];
        A[indexB] = temp;
    }

    /**
     @brief Creates an array of random values
     @param size length of the array
     @return []int Array of random elements
    */
    static int[] makeRandomArray(int size){
        /* Create new rng seed */
        Random random = new Random();
        /* Create empty array of desired size */
        int[] A = new int[size];

        /* Iterate through the empty array */
        for(int i = 0; i < size; i++){
            /* Set a random value to the array */
            A[i] = random.Next(1, 100);
        }

        return A;
    }
}
