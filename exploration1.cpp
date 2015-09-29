#include <iostream>
using namespace std;

int main()
{
  int a = 0;
  int b = 0;
  int c = a;
  int sum = 0;
  int total[b];

  cout << "a > ";
  cin >> a;

  cout << "b > ";
  cin >> b;

      int temp;
      
      temp = (c / b - 1);
      total[0] = a - (temp * (b - 1)); 

      c -= total[0];

      for (int i = 1; i < b; i++)
        total[i] = temp;

      for (int i = 1; i < b; i++)
      {
        total[i] -= b - (i + 1);
        total[b - 1] += b - (i + 1);
      }

for (int i = 0; i < b; i++)
{
cout << total[i] << (i < b - 1 ? " + " : "");  
sum += total[i];
}

cout << " = " << sum << endl;
  return 0;
}
