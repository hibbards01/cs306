import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class MyInsertionSort {
 
    public static void main(String[] args) throws IOException {
	// create Scanner inFile

	Scanner inFile = null;

	if (0 < args.length) {
	    inFile = new Scanner( new File(args[0]));
	} else {
	    System.err.println("Invalid arguments count:" + args.length);
	    //System.exit();
	}


	//	Scanner inFile = new Scanner(new File("randomNumbers.txt"));

	List<Integer> tokens = new ArrayList<Integer>();
	while (inFile.hasNext()) {
	    tokens.add(inFile.nextInt());
	}
	inFile.close();

	Integer[] tempsArray = tokens.toArray(new Integer[0]);

	//	for (int s : tempsArray) {
	//  System.out.println(s);
	//}

        Integer[] input = new Integer[] { 4, 2, 9, 6, 23, 12, 34, 0, 1 };
	long startTime = System.nanoTime();

        insertionSort(tempsArray);
	long endTime = System.nanoTime();

	System.out.println("Program took " + (((endTime - startTime) / 1000000) / 1000) + " miliseconds.");
    }

    private static void printNumbers(Integer[] input) {
         
        for (int i = 0; i < input.length; i++) {
            System.out.print(input[i] + ", ");
        }
        System.out.println("\n");
    }
 
    public static void insertionSort(Integer array[]) {
        int n = array.length;
	        for (int j = 1; j < n; j++) {
            int key = array[j];
            int i = j-1;
            while ( (i > -1) && ( array [i] > key ) ) {
                array [i+1] = array [i];
                i--;
            }
            array[i+1] = key;

	    }
            printNumbers(array);
    }
}