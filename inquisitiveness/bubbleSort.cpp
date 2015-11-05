/*******************************************************
 * AUTHOR: PALMER CLUFF
 *
 * BUBBLE SORT
 *******************************************************/

#include <iostream>
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
  int array[] = {5, 3, 8, 2, 1, 4, 7, 6, 10, 9};

  cout << "Array before it is sorted: ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;

  bubbleSort(array, 10);

  cout << "Array after it is sorted : ";
  for (int i = 0; i < 10; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;

  return 0;
}
