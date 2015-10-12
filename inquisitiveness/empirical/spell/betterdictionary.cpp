// Get a Better dictionary

#include "dictionary.h"

class BetterDictionary : public Dictionary
{
public:
   BetterDictionary(string filename) : Dictionary(filename)
   {
   }

   bool lookup(string word)
   {
      return binarySearch(word, 0, mNumberOfWords - 1);
   }

   bool binarySearch(string sought, int first, int last)
   {
      int middle = (first + last) / 2;

      if (last < first)
      {
         return false;
      }
      else if (sought < mWords[middle])
      {
         return binarySearch(sought, first, middle - 1);
      }
      else if (sought > mWords[middle])
      {
         return binarySearch(sought, middle + 1, last);
      }
      else
      {
         return true;
      }
   }
};

Dictionary* getDictionary(string filename)
{
   return new BetterDictionary(filename);
}
