/****************************************************
* Program:
*   mergesort.cpp
* Author:
*   Samuel Hibbard
* Summary:
*   I couldn't find a library for the merge sort in
*       c++ so I implemented one myself by searching
*       google.
****************************************************/

// Include the right files.
#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>
using namespace std;

// For debugging purposes.
// To output debug type in command line: g++ -DSHOW <file>
#ifdef SHOW
#define Debug(x) x
#else
#define Debug(x)
#endif

/*************************************
* merge
*   This will merge the two numbers,
*       arrays together.
*************************************/
void merge(int array[], int first, int middle, int last)
{
    // Grab the sizes of the two arrays
    int size1 = middle - first + 1;
    int size2 = last - middle;

    // Now make copy's of these arrays
    int * lhArray = new int[size1];
    int * rhArray = new int[size2];
    for (int i = 0; i < size1; ++i)
    {
        lhArray[i] = array[first + i];
    }

    for (int i = 0; i < size2; ++i)
    {
        rhArray[i] = array[middle + 1 + i];
    }

    // Now merge them
    int index1 = 0;
    int index2 = 0;
    int index = first;

    while (index1 < size1 && index2 < size2)
    {
        // See if lh is less then rh
        if (lhArray[index1] <= rhArray[index2])
        {
            array[index] = lhArray[index1++];
        }
        else
        {
            array[index] = rhArray[index2++];
        }

        // Increment the array!
        ++index;
    }

    // Grab the left overs
    // First the left side
    while (index1 < size1)
    {
        array[index++] = lhArray[index1++];
    }

    // Now the right side
    while (index2 < size2)
    {
        array[index++] = rhArray[index2++];
    }

    // Delete the temporary arrays
    delete [] lhArray;
    delete [] rhArray;

    return;
}

/*************************************
* mergeSort
*   This will divide the array to one
*       single element then merge
*       everything.
*************************************/
void mergeSort(int array[], int first, int last)
{
    // Make sure that first is less then last
    if (first < last)
    {
        // Grab the middle of the array
        int middle = (first + (last - 1)) / 2;

        // Now call yourself and divide the first half
        mergeSort(array, first, middle);

        // And do it to the other side
        mergeSort(array, middle + 1, last);

        // Finally merge them together
        merge(array, first, middle, last);
    }

    return;
}

/*************************************
* random
*   Takes two ranges and returns a
*       random number.
* Author: Brother Helfrich
*************************************/
int random(int min, int max)
{
   assert(min <= max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

/*************************************
* main
*   Driver program.
*************************************/
int main(int argc, char const *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    // Create 100 random numbers
    int * array = new int[2000000];
    for (int i = 0; i < 2000000; ++i)
    {
        array[i] = random(1, 2000000);
    }

    // See how long it takes
    clock_t t;

    // Now sort them!
    t = clock();
    mergeSort(array, 0, 1999999);
    t = clock() - t;

    // Now show the array
#ifdef SHOW
    for (int i = 0; i < 100000000; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;
#endif
    // Delete the memory
    delete [] array;

    cout << "Program took " << (((float)t)/CLOCKS_PER_SEC) << " seconds\n";

    return 0;
}
