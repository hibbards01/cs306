#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int DEFAULT_SIZE = 10;

void displayArray(int array[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << array[i] << " ";
   }
   cout << endl;
}

bool isDuplicate(int array[], int x)
{
   for (int i = 0; i < x; i++)
   {
      if (array[i] == array[x])
      {
         return true;
      }
   }
   return false;
}

int main(int argc, char* argv[])
{
   int size = DEFAULT_SIZE;
   int maxValue = size + 1;
   (int) ((float) rand() / RAND_MAX * maxValue);

   if (argc == 2)
   {
      size = atoi(argv[1]);
      maxValue = size + 1;
   }
   else if (argc == 3)
   {
      size = atoi(argv[1]);
      maxValue = atoi(argv[2]);
   }

   int* array = new int[size];

   srand(time(NULL));
   for (int i = 0; i < size;)
   {
      array[i] = (int) ((float) rand() / RAND_MAX * maxValue);
//      if (! isDuplicate(array, i)) // too slow for large size
      {
         i++;
      }
   }
   displayArray(array, size);

   return 0;
}
