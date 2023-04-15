# CS260-001: Homework 2

By Cole Bardin : CAB572

## Description

This program compares different sorting algorithms for variable, random length arrays

There are 4 sorting algorithms implemented:

1) Bubble 

2) Insert

3) Merge

4) Quick

The program can also do a comparison of all sorting algorithms for arrays of length 2^N for N={3 - 17}

## Usage

Running the program will prompt the user to select which test to run.

The user can test all sorting methods or choose an individual one to test.

### Individual Tests 

For individual tests, the user can then specify an array length and the number of tests to run.

The program will then create and sort arrays, alerting the user if any sorting fails.

### Test All Sorting Methods

The program will time and compare all 4 sorting algorithms for arrays of length 2^N.

This is repeated for N = 3, 4, 5, 6, ..., 17

The results are output to STDOUT in a neat table.

## Results

### What was the fastest algorithm?

Quick Sort was the fastest

### What was the slowest algorithm?

Bubble sort was the slowest

### Did the timings match the analysis from class?

Somewhat. Our analysis said Bubble Sort and Instert Sort had similar upper bounds but on average, Insert Sort performed much better than Bubble Sort. As well, Merge Sort and Quick Sort had the same average, which is the theorhetical bound, but Quick Sort performed better on avergage than Merge Sort.

### What was the hardest part of this assignment?

Nothing.

### All algorithm timings

All Times in milliseconds.

|    Size |     Bubble |     Insert |      Merge |      Quick |
| --- | --- | --- | --- | --- |
|       8 |     0.0000 |     0.0000 |     0.0000 |     0.0000 |
|      16 |     0.0000 |     0.0000 |     0.0000 |     0.0000 |
|      32 |     0.0000 |     0.0000 |     0.0000 |     0.0000 |
|      64 |     0.0000 |     0.0000 |     0.0000 |     0.0000 |
|     128 |     0.0000 |     1.0000 |     0.0000 |     0.0000 |
|     256 |     0.0000 |     0.0000 |     0.0000 |     0.0000 |
|     512 |     1.0000 |     0.0000 |     0.0000 |     0.0000 |
|    1024 |     1.0000 |     1.0000 |     0.0000 |     0.0000 |
|    2048 |     6.0000 |     3.0000 |     0.0000 |     1.0000 |
|    4096 |    22.0000 |    13.0000 |     0.0000 |     0.0000 |
|    8192 |    89.0000 |    50.0000 |     1.0000 |     0.0000 |
|   16384 |   359.0000 |   194.0000 |     1.0000 |     1.0000 |
|   32768 |  1438.0000 |   820.0000 |     3.0000 |     3.0000 |
|   65536 |  5946.0000 |  3224.0000 |     6.0000 |     6.0000 |
|  131072 | 29657.0000 | 12605.0000 |    11.0000 |    12.0000 |

