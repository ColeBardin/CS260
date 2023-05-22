# CS260-001: Homework 6

By Cole Bardin : CAB572

## Part 2: Timings

### Raw output

Running Timings.
All Times in milliseconds.
|    Size |       Heap |
| ----- | --------- |
|       8 |     0.0000 |
|      16 |     0.0000 |
|      32 |     0.0000 |
|      64 |     0.0000 |
|     128 |     0.0000 |
|     256 |     0.0000 |
|     512 |     0.0000 |
|    1024 |     0.0000 |
|    2048 |     1.0000 |
|    4096 |     7.0000 |
|    8192 |    25.0000 |
|   16384 |   100.0000 |
|   32768 |   395.0000 |
|   65536 |  1528.0000 |
|  131072 |  6148.0000 |

### Questions

What was the fastest algorithm?
It appears Quicksort is still the fastest, but very close with Mergesort.

What was the slowest algorithm?
Out of these three, Heapsort, but barely

Did the timings match the analysis from class?
Yes and no. Despite all having the same average runtime, my Heapsort was a bit slower, which matches what the internet tends to say about this comparison

What was the hardest part of this assignment?
Nothing