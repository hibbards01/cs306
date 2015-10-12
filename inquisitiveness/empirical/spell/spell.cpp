// spell checking for empirical analysis

#include "dictionary.h"

int main(int argc, char* argv[])
{
   string filename = "dictionary.txt";
   string word;

   if (argc > 1)
   {
      filename = argv[1];
   }

   Dictionary* dict = getDictionary(filename);

   while (cin >> word)
   {
      if (! dict->lookup(word))
      {
         cout << word << endl;
      }
   }

   return 0;
}
