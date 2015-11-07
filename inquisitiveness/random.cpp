#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cassert>
using namespace std;

int random(int min, int max)
{
   assert(min <= max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

int main()
{
  int size = 10000000;
  int * array = new int[size];
  string file = "randomNumbers.txt";

  ofstream fout(file.c_str());

  if (fout.fail())
    cout << "ERROR\n";

  for (int i = 0; i < size; ++i)
    {
      int num = random(0, size);
      fout << num << endl;
    }

  fout.close();

  delete [] array;
}
