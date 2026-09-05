/* bubble sort program that reads 10000 to 40000 elements and sorts them using bubble sort
* credited - chegg.com
* credited - geeksforgeeks.org
* credited - stackoverflow.com
* modified by Adam Lee, JagNumber: J00762612
* date: 10/31/2024
*/
#include <iostream> 
#include <stdio.h>
#include <chrono>  // for timer
#include <cstdlib> // for rand()

using namespace std::chrono;

// swap elements of array
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort function
void bubbleSort(int array[], int len, bool printPasses = false)
{
    int i, j; // integer values i and j respectfully
    bool swapped; // boolean for swapped function
    for (i = 0; i < len - 1; i++) // for loop that compares elements in the array, returns false if smaller
    {
        swapped = false;
        for (j = 0; j < len - i - 1; j++) // for loop that compares the next largest and swaps if need
        {
            if (array[j] > array[j + 1]) // if statment that swaps the elements in the array.
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }

        // Print the array after each complete pass if specified
        if (printPasses) {
            printf("Array after pass %d: ", i + 1);
            for (int k = 0; k < len; k++) {
                printf("%d ", array[k]);
            }
            printf("\n");
        }

        if (!swapped) // if no swaps, break from loop
            break;
    }
}

// function to display the array
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]); // print array
}

int main()
{
    int array[] = { 64, 34, 25, 12, 22, 11, 90 }; // example array
    int n = sizeof(array) / sizeof(array[0]); // math for length of array
    printf("Example array list using bubble sort:\n");
    printf("\n");

    printf("Unsorted array: ");
    display(array, n); // Display unsorted array
    printf("\n\n");

    // Call bubble sort with pass print as true
    bubbleSort(array, n, true); 
    printf("\nSorted array: ");
    display(array, n); // Display sorted array
    printf("\n");

    // Testing with sample random data
    int array_10000[10000];
    int array_20000[20000];
    int array_30000[30000];
    int array_40000[40000];

    long long time_10000, time_20000, time_30000, time_40000;

    // Starts with 10000 elements
    auto a = high_resolution_clock::now(); // starts timer for first array

    
    for (int i = 0; i < 10000; i++) // for loop that counts through 0 to 10000 and increments
        array_10000[i] = rand() % 10000; // gets random number generated 
    printf("\nUnsorted array with 10000 elements: \n"); // displays first 10 elements of the unsorted array.
    display(array_10000, 10);

    printf("\nSorted array with 10000 elements: \n");
    bubbleSort(array_10000, 10000); // calls bubble sort function for 10000 number array
    display(array_10000, 10); // display first 10 elements of sorted array

    auto b = high_resolution_clock::now(); // stops timer for first array
    time_10000 = duration_cast<milliseconds>(b - a).count(); // store time taken

    // Repeat for 20000 elements
    a = high_resolution_clock::now();

    
    for (int i = 0; i < 20000; i++)
        array_20000[i] = rand() % 20000;
    printf("\nUnsorted array with 20000 elements: \n");
    display(array_20000, 10);

    printf("\nSorted array with 20000 elements: \n");
    bubbleSort(array_20000, 20000);
    display(array_20000, 10);

    b = high_resolution_clock::now();
    time_20000 = duration_cast<milliseconds>(b - a).count();

    // Repeat for 30000 elements
    a = high_resolution_clock::now();

    for (int i = 0; i < 30000; i++)
        array_30000[i] = rand() % 30000;
    printf("\nUnsorted array with 30000 elements: \n");
    display(array_30000, 10);

    printf("\nSorted array with 30000 elements: \n");
    bubbleSort(array_30000, 30000);
    display(array_30000, 10);

    b = high_resolution_clock::now();
    time_30000 = duration_cast<milliseconds>(b - a).count();

    // Repeat for 40000 elements
    a = high_resolution_clock::now();

    
    for (int i = 0; i < 40000; i++)
        array_40000[i] = rand() % 40000;
    printf("\nUnsorted array with 40000 elements: \n");
    display(array_40000, 10);

    printf("\nSorted array with 40000 elements: \n");
    bubbleSort(array_40000, 40000);
    display(array_40000, 10);

    b = high_resolution_clock::now();
    time_40000 = duration_cast<milliseconds>(b - a).count();

    // Print times for each array
    printf("\n");
    printf("\nBubble sort time:\n");
    printf("for an array of 10000: %lld milliseconds\n", time_10000);
    printf("for an array of 20000: %lld milliseconds\n", time_20000);
    printf("for an array of 30000: %lld milliseconds\n", time_30000);
    printf("for an array of 40000: %lld milliseconds\n", time_40000);
    printf("Name: Adam Lee\nJagNumber: J00762612\n"); // name and jagnumber

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
