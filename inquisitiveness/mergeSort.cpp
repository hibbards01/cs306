#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  ifstream foo("data.txt");
  int next = 0;
  vector<int> numbers;

  foo >> next;

   while (!foo.eof())
    {
      numbers.push_back(next);
      foo >> next;
    }

   //   for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
   //cout << *it << " ";

   //cout << "\n";
   vector<int> v(numbers.size() * 2);

   sort(numbers.begin(), numbers.end());

   merge(numbers.begin(), numbers.end(), numbers.begin(), numbers.end(), v.begin());

   for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
     std::cout << ' ' << *it;
   std::cout << '\n';

  return 0;
}
