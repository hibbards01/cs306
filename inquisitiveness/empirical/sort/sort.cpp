#include <iostream>
#include <cstdlib>
using namespace std;

extern void sort2(int data[], int left, int right);

void displayArray(int array[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << array[i] << " ";
   }
   cout << endl;
}

int main(int argc, char* argv[])
{
    int i = 0;
    int size = 0;
    int data;
    if (argc > 1)
    {
        size = atoi(argv[1]);
    }
    int array[size];

    while (cin >> data)
    {
        array[i++] = data;
    }
    sort2(array, 0, size);
    displayArray(array, size);

    return 0;
}
