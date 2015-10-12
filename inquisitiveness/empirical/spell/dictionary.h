// A Dictionary class for spell checking

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

class Dictionary
{
protected:
   int mNumberOfWords;
   string* mWords;

public:
   Dictionary()
   {
      mNumberOfWords = 0;
      mWords = NULL;
   }

   Dictionary(string filename)
   {
      mNumberOfWords = countNumberOfWords(filename);
      mWords = new string[mNumberOfWords];
      readFrom(filename);
   }

   int getNumberOfWords()
   {
      return mNumberOfWords;
   }

   string* getWords()
   {
      return mWords;
   }

   int countNumberOfWords(string filename)
   {
      ifstream ifs(filename.c_str());
      if (ifs.fail())
      {
         return 0;
      }
      int i = -1;
      string tmp;
      do
      {
         ifs >> tmp;
         i++;
      } while (! ifs.eof());
      return i;
   }

   void readFrom(string filename)
   {
      ifstream ifs(filename.c_str());
      if (ifs.fail())
      {
         return;
      }
      int i = 0;
      do
      {
         ifs >> mWords[i];
         i++;
      } while (! ifs.eof());
   }

   virtual bool lookup(string word)
   {
      for (int i = 0; i < mNumberOfWords; i++)
      {
         if (word == mWords[i])
         {
            return true;
         }
         else if (mWords[i] > word)
         {
            return false;
         }
      }
      return false;
   }
};

Dictionary* getDictionary(string filename);
