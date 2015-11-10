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
  string file = "worst.txt";

  ofstream fout(file.c_str());

  if (fout.fail())
    cout << "ERROR\n";

  for (int i = size; i > 0; --i)
    {
      fout << i << endl;
    }

  fout.close();

  delete [] array;
}
