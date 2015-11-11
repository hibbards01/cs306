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
echo "Best: "
./quickSort best.txt
echo "Average: "
./quickSort average.txt
echo "Worst: "
./quickSort worst.txt

echo "Java: "
javac QuickSort.java
echo "Best: "
java QuickSort best.txt
echo "Average: "
java QuickSort average.txt
echo "Worst: "
java QuickSort worst.txt

echo

echo "Merge Sort:"
echo "C++: "
g++ -o mergeSort mergesort.cpp
echo "Best: "
./mergeSort best.txt
echo "Average: "
./mergeSort average.txt
echo "Worst: "
./mergeSort worst.txt

echo "Java: "
java -jar MergeSort.jar

echo

echo "n^2 Algorithms"
echo "--------------"

echo "Insertion Sort:"
echo "C++: "
g++ -o insertionSort insertionSort.cpp
echo "Best: "
./insertionSort best.txt
echo "Average: "
./insertionSort average.txt
echo "Worst: "
./insertionSort worst.txt

echo "Java: "
javac MyInsertionSort.java
echo "Best: "
java MyInsertionSort best.txt
echo "Average: "
java MyInsertionSort average.txt
echo "Worst: "
java MyInsertionSort worst.txt

echo

echo "Bubble Sort: "
echo "C++: "
g++ -o bubbleSort bubbleSort.cpp
echo "Best: "
./bubbleSort best.txt
echo "Average: "
./bubbleSort average.txt
echo "Worst: "
./bubbleSort worst.txt

echo "Java: "
javac BubbleSort.java
echo "Best: "
java BubbleSort best.txt
echo "Average: "
java BubbleSort average.txt
echo "Worst: "
java BubbleSort worst.txt