
		Empirical Analysis of Spelling

What this code allows us to do:

Compare the empirical speed of spell checking using slow, fast and
even faster (fastest?) implementations of dictionary lookups.

g++ -c dictionary.cpp betterdictionary.cpp bestdictionary.cpp

g++ spell.cpp dictionary.o -o slowspell

g++ spell.cpp betterdictionary.o -o fasterspell

g++ spell.cpp bestdictionary.o -o fastestspell

time cat /home/neffr/dictionary.txt | slowspell /home/neffr/dictionary.txt

time cat /home/neffr/dictionary.txt | fasterspell /home/neffr/dictionary.txt

time cat /home/neffr/dictionary.txt | fastestspell /home/neffr/dictionary.txt

========================================================================
