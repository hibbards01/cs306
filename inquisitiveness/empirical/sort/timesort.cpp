#include <iostream>
#include <iomanip>
#include "random.h"
using namespace std;

// Demonstrates sort algorithm timing.

/*********************************************************
 *
 *    FUNCTION: sort1
 *
 *  PARAMETERS: data - an array of integers
 *              n    - number of elements in the array to sort
 *
 *********************************************************/
void sort1(int data[], int n)
{
   bool notsorted = true;
   int temp;
   int i;
   
   while (notsorted)
   {
      notsorted = false;
      for (i = 0; i < n; ++i)
      {
         if (data[i] > data[i+1])
         {
            temp = data[i];
            data[i] = data[i + 1];
            data[i + 1] = temp;
            notsorted = true;
         }
      }
   }
}

#define LOOP_LIMIT 1000

bool slowCompare(int a, int b)
{
   // change the loop limit up or down...
//   for (int i = 0; i < LOOP_LIMIT; i++);
   return (a < b);
}

/*********************************************************
 *
 *    FUNCTION: sort2
 *
 *  PARAMETERS: data[] - array of data to be sorted
 *              left   - left index of array
 *              right  - right index of array
 *
 *********************************************************/
void sort2(int data[], int left, int right)
{
   int i;
   int j;
   int pivot;
   int temp;
   
   if (left <= right)
   {
      pivot = data[(left + right) / 2];
      
      i = left;
      j = right;
      do
      {
         while (slowCompare(data[i], pivot))
         {
            i++;
         }
         while (slowCompare(pivot, data[j]))
         {
            j--;
         }
         if (i <= j)
         {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
            j--;
         }
      } while (i < j);
      sort2(data, left, j);
      sort2(data, i, right);
   }
}
#ifdef STANDALONE
int main()
{
  int size;         // --- size of array
  int* array;       // --- array containing random integers
  Random r;         // --- random number generator object
  clock_t start;    // --- time when algorithm starts
  clock_t finish;   // --- time when algorithm finishes

  cout << " Size      Sort #1      Sort #2" << endl;

  for (size = 10000; size <= 50000; size+= 5000)
  {
     // --- create array with 'size' random integers
     array = new int[size];
     for (int i = 0; i < size; ++i)
     {
        array[i] = r.nextInt(1, 500);
     }
     cout << setw(5) << size;

     // --- Find out how much time for first sort
     start = clock();
     sort1(array, size);
     finish = clock();
     cout << setprecision(5) << setw(13) << (finish - start) / (double) CLOCKS_PER_SEC;
     
     // --- recreate array with new set of random integers
     delete [] array;
     array = new int[size];
     for (int i = 0; i < size; ++i)
     {
        array[i] = r.nextInt(1, 500);
     }
     
     // --- Find out how much time for second sort
     start = clock();
     sort2(array, 0, size);
     finish = clock();
     cout << setprecision(5) << setw(13) << (finish - start) / (double) CLOCKS_PER_SEC
          << endl;
     
     delete [] array;
  }

  return 0;
}
#endif

