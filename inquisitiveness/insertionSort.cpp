#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
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

int main(int argc, char* argv[])
{
  // string filename;
  //  cout << "filename > ";
  //getline(cin, filename);

  ifstream fin(argv[1]);

  cout << "filename: " << argv[1] << endl;

  int next = 0;
  vector<int> data;

  fin >> next;

    while(!fin.eof())
      {
	data.push_back(next);

	fin >> next;
      }

  clock_t t;
  t = clock();
    insertion_sort(data, data.size());
  t = clock() - t;

  //for (std::vector<int>::iterator it = data.begin() ; it != data.end(); ++it)
  //std::cout << ' ' << *it;

    cout << endl;

  cout << "Program took " << (((float)t)/CLOCKS_PER_SEC) << " seconds\n";

  return 0;
}
