/*******************************************************
 * AUTHOR: PALMER CLUFF
 *
 * BUBBLE SORT
 *******************************************************/

#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

/***********************************
 * Run the program
 ***********************************/

void bubbleSort(int arr[], int n) {
  bool swapped = true;
  int j = 0;
  int tmp;
  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < n - j; i++) {
      if (arr[i] > arr[i + 1]) {
	tmp = arr[i];
	arr[i] = arr[i + 1];
	arr[i + 1] = tmp;
	swapped = true;
      } 
    }   
  }  
}

int main()
{
  int num = 10000000;
  //int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int *array = new int[num];
  ifstream myFile("randomNumbers.txt");
  
  for(int i = 0; i < num; i++) 
    {
      myFile >> array[i];
    }
  myFile.close();

  // cout << "Array before it is sorted: ";
  // for (int i = 0; i < num; i++) {
  //   cout << array[i] << ' ';
  // }
  // cout << endl;

  clock_t t;
  t = clock();
  bubbleSort(array, num);
  t = clock() - t;
  // cout << "Array after it is sorted : ";
  // for (int i = 0; i < num; i++) {
  //   cout << array[i] << ' ';
  // }
  // cout << endl;

  delete[] array;
  cout << "Program took " << (((float)t)/CLOCKS_PER_SEC) << " seconds\n";
  return 0;
}
