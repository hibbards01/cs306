// Get a Best dictionary

#include <set>
#include "dictionary.h"
using namespace std;

class BestDictionary : public Dictionary
{
protected:
   set<string> mWords;

public:
   BestDictionary(string filename)
   {
      ifstream ifs(filename.c_str());
      if (! ifs.fail())
      {
         do
         {
            string word;
            ifs >> word;
            mWords.insert(word);
         } while (! ifs.eof());
      }
   }

   bool lookup(string word)
   {
      return (mWords.find(word) != mWords.end());
   }
};

Dictionary* getDictionary(string filename)
{
   return new BestDictionary(filename);
}
