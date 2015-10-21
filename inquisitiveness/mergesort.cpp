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
using namespace std;

/*************************************
* merge
*   This will merge the two numbers,
*       arrays together.
*************************************/
void merge(int array[], int first, int middle, int last)
{
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
    // Create 100 random numbers
    int array[100];
    for (int i = 0; i < 100; ++i)
    {
        array[i] = random(1, 100);
    }

    // Now sort them!
    mergeSort(array, 0, 100);

    // Now show the array
    for (int i = 0; i < 100; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}