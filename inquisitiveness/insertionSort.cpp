#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void insertion_sort (vector<int>& arr, int length){
  int j, temp;
  
  for (int i = 0; i < length; i++){
    j = i;
    
    while (j > 0 && arr[j] < arr[j-1]){
      temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
  }
}

int main()
{

  ifstream fin("data.txt");
  int next = 0;
  vector<int> data;

  fin >> next;

    while(!fin.eof())
      {
	data.push_back(next);

	fin >> next;
      }


    insertion_sort(data, data.size());

    for (std::vector<int>::iterator it = data.begin() ; it != data.end(); ++it)
      std::cout << ' ' << *it;

    cout << endl;

  return 0;
}
