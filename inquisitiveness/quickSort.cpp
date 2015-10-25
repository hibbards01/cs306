/*******************************************************
 * AUTHOR: PALMER CLUFF
 *
 * QUICK SORT
 *******************************************************/

#include <iostream>
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
  int array[] = {5, 3, 8, 2, 1, 4, 7, 6, 10, 9};

  cout << "Array before it is sorted: ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;

  quickSort(array, 0, 9);

  cout << "Array after it is sorted : ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;

  return 0;
}
