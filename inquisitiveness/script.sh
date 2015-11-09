#!/bin/bash
# Inquisitiveness Bash Script
# May have to compile using the command: ./script.sh
# Palmer Cluff

echo
echo "***INQUISITIVENESS BASH SCRIPT***"
echo

echo "n log n Algorithms"
echo "------------------"
echo "Quicksort:"
echo "C++: "
g++ -o quickSort quickSort.cpp
./quickSort

echo "Java: "
javac QuickSort.java
java QuickSort

echo

echo "Merge Sort:"
echo "C++: "
g++ -o mergeSort mergesort.cpp
./mergeSort

echo "Java: "
java -jar MergeSort.jar

echo

echo "n^2 Algorithms"
echo "--------------"

echo "Insertion Sort:"
echo "C++: "
g++ -o insertionSort insertionSort.cpp
./insertionSort

echo "Java: "
javac MyInsertionSort.java
java MyInsertionSort

echo

echo "Bubble Sort: "
echo "C++: "
g++ -o bubbleSort bubbleSort.cpp
./bubbleSort

echo "Java: "
javac BubbleSort.java
java BubbleSort