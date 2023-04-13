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
|       8 |     0.0070 |     0.0050 |     0.0050 |     0.0040 |
|      16 |     0.0060 |     0.0030 |     0.0050 |     0.0030 |
|      32 |     0.0120 |     0.0060 |     0.0080 |     0.0060 |
|      64 |     0.0660 |     0.0160 |     0.0170 |     0.0130 |
|     128 |     0.1270 |     0.0550 |     0.0330 |     0.0260 |
|     256 |     0.5140 |     0.2050 |     0.0680 |     0.0530 |
|     512 |     1.5740 |     0.6990 |     0.1250 |     0.0970 |
|    1024 |     5.1110 |     2.1530 |     0.2180 |     0.1690 |
|    2048 |    14.7100 |     5.5630 |     0.2880 |     0.2350 |
|    4096 |    36.5730 |    16.6750 |     0.5000 |     0.3910 |
|    8192 |   150.2920 |    60.4040 |     0.9540 |     0.7330 |
|   16384 |   736.0810 |   261.6880 |     2.0960 |     1.5540 |
|   32768 |  3219.8680 |  1051.8770 |     4.5060 |     3.5160 |
|   65536 | 13304.1620 |  4072.1120 |     9.0000 |     7.8090 |
|  131072 | 52480.3310 | 16277.4780 |    19.1820 |    15.8360 |
