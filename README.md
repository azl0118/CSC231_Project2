# CSC231 Project 2 - Presentation of Sort Analysis

## Overview

This project compares the performance of two sorting algorithms implemented in C++: **Bubble Sort** and **Quicksort**.

The program tests each sorting algorithm using arrays of different sizes and measures the amount of time required to sort each array.

## Algorithms

### Bubble Sort
Bubble Sort repeatedly compares elements in an array and swaps them when they are out of order. The algorithm makes multiple passes through the array until it is completely sorted.

### Quicksort
Quicksort uses a divide-and-conquer approach. It selects a pivot, separates the array based on that pivot, and recursively sorts the smaller sections of the array.

## Performance Testing

The algorithms were tested using arrays containing:

- 10,000 elements
- 20,000 elements
- 30,000 elements
- 40,000 elements

| Array Size | Bubble Sort | Quicksort |
|-----------:|------------:|----------:|
| 10,000 | 615 ms | 2 ms |
| 20,000 | 2,475 ms | 4 ms |
| 30,000 | 6,020 ms | 8 ms |
| 40,000 | 9,407 ms | 9 ms |

The results show that Quicksort performs significantly faster than Bubble Sort as the size of the array increases.

## Technologies Used

- C++
- Microsoft Visual Studio
- Microsoft Excel

## Project Files

- `Test_File.cpp` - Bubble Sort implementation
- `Test_File3.cpp` - Quicksort implementation
- `BubbleSort.sln` - Bubble Sort Visual Studio solution
- `QuickSort.sln` - Quicksort Visual Studio solution
- `Project2_LeeAL.xlsx` - Performance comparison spreadsheet
- `Project2_LeeAL-2.pdf` - Project documentation

## Author

**Adam Lee**  
CSC231
