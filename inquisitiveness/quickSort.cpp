/*******************************************************
 * AUTHOR: PALMER CLUFF
 *
 * QUICK SORT
 *******************************************************/

#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

void quickSort(int arr[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];
  
  /* partition */
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  };
  

  /* recursion */
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}

/***********************************
 * Run the program
 ***********************************/

int main()
{
  int num = 10000000;
  //int array[] = {5, 3, 8, 2, 1, 4, 7, 6, 10, 9};
  int *array = new int[num];

  ifstream myFile("randomNumbers.txt");  
  for(int i = 0; i < num; i++) 
    {
      myFile >> array[i];
    }
  myFile.close();

  // cout << "Array before it is sorted: ";
  // for (int i = 0; i < 10; i++) {
  //   cout << array[i] << ' ';
  // }
  // cout << endl;
  clock_t t;
  t = clock();
  quickSort(array, 0, num - 1);
  t = clock() - t;
  // cout << "Array after it is sorted : ";
  // for (int i = 0; i < 10; i++) {
  //   cout << array[i] << ' ';
  // }
  // cout << endl;

  delete[] array;

  cout << "Program took " << (((float)t)/CLOCKS_PER_SEC) << " seconds\n";

  return 0;
}
