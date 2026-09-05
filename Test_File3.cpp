// A program that takes 10000 to 40000 elements in each indivdual array and sorts them using quicksort algorthim
// credit - chegg.com
// credit - geeksforgeeks.com
// credit - stackoverflow.com
// Modified by:
// Name: Adam Lee
// JagNumber: J00762612
// Date: 10/31/2024


#include <iostream>
#include <stdio.h>
#include <cstdlib> // Include this for rand()
#include <chrono>  // For measuring time

using namespace std;
using namespace std::chrono; // For high_resolution_clock

// Swap function
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// This function selects the last element as the pivot and places it in the right place
int partition(int array[], int min, int max)
{
    int pivot = array[max]; // Select the pivot element
    int index = (min - 1); // Store the index

    for (int j = min; j <= max - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            index++;
            swap(&array[index], &array[j]);
        }
    }
    swap(&array[index + 1], &array[max]);

    return (index + 1);
}

// Function to apply quick sort
void quickSort(int array[], int min, int max, bool isExample = false)
{
    if (min < max)
    {
        int part = partition(array, min, max);

        // Print the partition with pivot only for the example array
        if (isExample) {
            printf("Array after partitioning with pivot %d: ", array[part]);
            for (int k = 0; k < max + 1; k++) {
                printf("%d ", array[k]);
            }
            printf("\n");
        }

        quickSort(array, min, part - 1, isExample);
        quickSort(array, part + 1, max, isExample);
    }
}

// Display array
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Main function
int main()
{
    int array[] = { 64, 34, 25, 12, 22, 11, 90 }; // Sample array
    int n = sizeof(array) / sizeof(array[0]); // Compute length
    printf("Example array list using quick sort:\n\n");

    // Display unsorted array
    printf("Unsorted array: ");
    display(array, n); // Display unsorted array
    printf("\n");

    printf("Sorting the example array:\n");
    quickSort(array, 0, n - 1, true); // Set isExample to true to print the steps
    printf("Sorted array: ");
    display(array, n); // Display sorted array
    printf("\n");

    // Testing with sample random data
    const int sizes[] = { 10000, 20000, 30000, 40000 };
    long long times[4];

    for (int i = 0; i < 4; ++i) {
        int size = sizes[i];
        int* array_random = new int[size];

        // Fill the array with random numbers
        for (int j = 0; j < size; j++)
            array_random[j] = rand() % size;

        printf("\nFirst 10 elements of Unsorted array of %d: ", size);
        display(array_random, 10);

        auto start = high_resolution_clock::now();
        quickSort(array_random, 0, size - 1);
        auto stop = high_resolution_clock::now();
        times[i] = duration_cast<milliseconds>(stop - start).count();

        printf("\nFirst 10 elements of the sorted array of %d: ", size);
        display(array_random, 10);
        delete[] array_random; // Clean up dynamically allocated memory
    }

    // Print the sorting times
    printf("\nQuicksort Times:\n");
    for (int i = 0; i < 4; ++i) {
        printf("for array of %d elements: %lld milliseconds\n", sizes[i], times[i]);
    }

    printf("Name: Adam Lee\nJagnumber: J00762612\n");
    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
