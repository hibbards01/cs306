/*******************************************************
 * AUTHOR: PALMER CLUFF
 *
 * BUBBLE SORT
 *******************************************************/

#include <iostream>
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
  int *array = new int[10000000];
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

  bubbleSort(array, num);

  // cout << "Array after it is sorted : ";
  // for (int i = 0; i < num; i++) {
  //   cout << array[i] << ' ';
  // }
  // cout << endl;
  cout << "Done!\n";
  delete[] array;
  return 0;
}
