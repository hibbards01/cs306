// Get a plain old dictionary

#include "dictionary.h"

Dictionary* getDictionary(string filename)
{
   return new Dictionary(filename);
}
