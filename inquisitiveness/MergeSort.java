/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mergesort;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.logging.Level;
import java.util.logging.Logger;
 
public class MergeSort {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Create the list.
        int size = 10000000;
        List<Integer> list = new ArrayList<>();
//        for (int i = 0; i < size; i++) {
//            Random rand = new Random();
//            list.add(rand.nextInt(size));
//        }
        
        // Read from a file
        list = readFile(list);
        
        // Now do the merge sort
        long startTime = System.nanoTime();
        list = mergeSort(list);
        long endTime = System.nanoTime();
        
        // Output the time.
        System.out.println("Program took " + ((endTime - startTime) / 1000000) + " miliseconds.");
    }
    
    public static List<Integer> readFile(List<Integer> list) {
        try {
            // Grab the buffereader
            BufferedReader br = new BufferedReader(new FileReader("randomNumbers.txt"));
            
            String num;
            
            // Read from the file
            while ((num = br.readLine()) != null) {
                // Save it to the list
                list.add(Integer.parseInt(num));
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(MergeSort.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            System.out.println("ERROR: " + ex.getMessage());
        }
                
        return list;
    }
    
    public static <E extends Comparable<? super E>> List<E> mergeSort(List<E> m){
        if(m.size() <= 1) return m;
 
        int middle = m.size() / 2;
        List<E> left = m.subList(0, middle);
        List<E> right = m.subList(middle, m.size());
 
        right = mergeSort(right);
        left = mergeSort(left);
        List<E> result = merge(left, right);
 
        return result;
    }
 
    public static <E extends Comparable<? super E>> List<E> merge(List<E> left, List<E> right){
        List<E> result = new ArrayList<E>();
        Iterator<E> it1 = left.iterator();
        Iterator<E> it2 = right.iterator();
 
	E x = it1.next();
	E y = it2.next();
        while (true){
            //change the direction of this comparison to change the direction of the sort
            if(x.compareTo(y) <= 0){
		result.add(x);
		if(it1.hasNext()){
		    x = it1.next();
		}else{
		    result.add(y);
		    while(it2.hasNext()){
			result.add(it2.next());
		    }
		    break;
		}
	    }else{
		result.add(y);
		if(it2.hasNext()){
		    y = it2.next();
		}else{
		    result.add(x);
		    while (it1.hasNext()){
			result.add(it1.next());
		    }
		    break;
		}
	    }
        }
        return result;
    }
}
