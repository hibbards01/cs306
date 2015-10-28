/****************************************************
* Program:
*   mergesort.cpp
* Author:
*   Samuel Hibbard
* Summary:
*   I couldn't find a library for the merge sort in
*       c++ so I implemented one myself by searching
*       google.
****************************************************/
package com.mergesort;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * MergeSort
 * @author samuelhibbard
 */
public class MergeSort {
    
    /**
     * merge
     *  This will merge the two numbers,
     *      arrays together.
     * @param array
     * @param first
     * @param middle
     * @param last 
     */
    private void merge(List<BigInteger> array, BigInteger first, BigInteger middle, BigInteger last) {
        // Garb the sizes
        BigInteger size1 = middle.subtract(first).add(BigInteger.ONE);
        BigInteger size2 = last.subtract(middle);
        
        // Now make copy's of array
        List<BigInteger> lhs = new ArrayList<>();
        List<BigInteger> rhs = new ArrayList<>();
        
        for (BigInteger i = BigInteger.ZERO; i.compareTo(size1) < 0; i = i.add(BigInteger.ONE)) {
            if (!lhs.add(array.get(first.intValue() + i.intValue()))) {
                System.out.println("ERROR in inserting numbers for lhs.");
            }
        }
        
        for (BigInteger i = BigInteger.ZERO; i.compareTo(size2) < 0; i = i.add(BigInteger.ONE)) {
            if (!rhs.add(array.get(middle.intValue() + 1 + i.intValue()))) {
                System.out.println("ERROR in inserting numbers for rhs.");   
            }     
        }

        // Now merge them
        BigInteger index1 = BigInteger.ZERO;
        BigInteger index2 = BigInteger.ZERO;
        BigInteger index = first;
        
        while (index1.compareTo(size1) < 0 && index2.compareTo(size2) < 0) {
            // See which one is smaller
            if (lhs.get(index1.intValue()).compareTo(rhs.get(index2.intValue())) <= 0) {
                array.set(index.intValue(), lhs.get(index1.intValue()));
                index1 = index1.add(BigInteger.ONE);
            } else {
                array.set(index.intValue(), rhs.get(index2.intValue()));
                index2 = index2.add(BigInteger.ONE);
            }
            
            index = index.add(BigInteger.ONE);
        }
        
        // Now grab the rest of the values that are left over
        while (index1.compareTo(size1) < 0) {
            array.set(index.intValue(), lhs.get(index1.intValue()));
            index = index.add(BigInteger.ONE);
            index1 = index1.add(BigInteger.ONE);
        }
        
        while (index2.compareTo(size2) < 0) {
            array.set(index.intValue(), rhs.get(index2.intValue()));
            index = index.add(BigInteger.ONE);
            index2 = index2.add(BigInteger.ONE);
        }
    }
    
    /**
     * mergeSort
     *   This will divide the array to one
     *       single element then merge
     *       everything.
     * @param array
     * @param first
     * @param last 
     */
    public void mergeSort(List<BigInteger> array, BigInteger first, BigInteger last) {
        // Make sure that first is smaller then last
        if (first.compareTo(last) < 0) {
            // Now grab the middle
            BigInteger middle = (first.add(last.subtract(BigInteger.ONE)));
            middle.divide(new BigInteger("2"));
            
            // Divide the first half
            mergeSort(array, first, middle);
            
            // Divide the second half
            mergeSort(array, middle.add(BigInteger.ONE), last);
            
            // Now finally merge them
            merge(array, first, middle, last);
        }
    }
    
    /**
     * random
     *  Grab a random value.
     * @param max
     * @return 
     */
    private BigInteger random(BigInteger max) {
        // Grab a random number
        Random rnd = new Random();
        
        // Grab the result
        BigInteger result = new BigInteger(max.bitLength(), rnd);

        // Now do a random value greater then zero
        while (result.compareTo(BigInteger.ZERO) <= 0) {
            result = new BigInteger(max.bitLength(), rnd);
        }

        return result;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Save everything in an array
        MergeSort merge = new MergeSort();
        List<BigInteger> array = new ArrayList<>();
        
        // Create the Random numbers
        System.out.println("Grabbing random numbers");
        BigInteger max = new BigInteger("100");
        for (BigInteger i = BigInteger.ZERO; i.compareTo(max) < 0; i = i.add(BigInteger.ONE)) {
            // Grab some random values
            if (!array.add(merge.random(max))) {
                System.out.println("ERROR in inserting numbers.");
            }
        }
        
        // Now sort the numbers.
        System.out.println("Now sorting");
        merge.mergeSort(array, BigInteger.ZERO, max.subtract(BigInteger.ONE));
        
        // Display the array
//        for (BigInteger i = BigInteger.ZERO; i.compareTo(max) < 0; i = i.add(BigInteger.ONE)) {
//            System.out.print(array.get(i.intValue()) + " ");
//        }
//        System.out.println("\n");
    }
}