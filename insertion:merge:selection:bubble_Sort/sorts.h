#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{   
    if (start > stop || array == NULL) {
        return -1;
    }
    int current_min = start; // set current minimun to the start. 
    for (int i = start + 1; i <= stop; i++) {
        if (array[i] < array[current_min]) { // compare between the start and after 1 index. 
            current_min = i; // update current minimun to i. 
        }
    }
    return current_min; // return index.
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    if (size == 0 || array == NULL) {
        return;
    }
    
    for (int i = 0; i <= size-1; i++) { // iterate from the beginning.
        int current_min = i;// set current minimum to index i first.
        for (int j = i+1; j < size; j++) { // iterate from one index behind i. 
            if (array[current_min] > array[j]) { // compare one by one. 
                current_min = j; // update current minimum index. 
            }
        }
        swap(&array[i], &array[current_min]); // swap two values.
    if (print) {
        printIntArray(array, size);
    }
    }
}


/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{   
    if (size == 0) {
        return;
    }
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        int key = array[i];
        while (j>=0 && array[j] > key) {
            swap(&array[j], &array[j+1]); // worst example: 235796 -> 235769 -> 235679. Going backward for j in while loop. 
            j--;
        }
        array[j+1] = key; 
        if (print) {
            printIntArray(array, size);
        }
    }
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{   
    if (size == 0) {
        return;
    }
    int i, j; 
    for (i = 0; i < size - 1; i++) {
        for (j=0; j<size-1;j++) {
            if(array[j]>array[j+1]) {
                swap(&array[j], &array[j+1]);
                if (print) {
                    printIntArray(array, size);
                }
            }
        }
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    if (l > m || m + 1 > r)
        return;

    int i = l; // left start. 
    int j = m+1; // right start. 
    int k = l; // index start to temp array. 

    while(i<=m && j<=r) { // from left start to left end; right start to right end. 
        if(arr[i] <= arr[j]){ // check which is smaller. 
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++; 
        }
        k++;
    }
    // copy remainning if left half is longer. 
    while(i<=m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    //copy remainning if right half is longer. 
    while(j<=r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = l; i<=r; i++) {
        arr[i] = temp[i];
    }


}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
   if (l>=r) {
    return;
   }
   int m = (l+r)/2;
   merge_sort(arr, temp, l, m);
   merge_sort(arr, temp, m+1, r);
   merge(arr, temp, l,m,r);
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif