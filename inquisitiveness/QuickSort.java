import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.logging.Level;
import java.util.logging.Logger;

public class QuickSort {

    public static void main(String[] args) {
	int size = 10000000;
	List<Integer> list = new ArrayList<Integer>();

	// int[] array = new int[]{5, 3, 8, 2, 1, 4, 7, 6, 10, 9};
	
	// System.out.print("Array before it is sorted: ");
	// for (int i = 0; i < 10; i++) {
	//     System.out.print(array[i]);
	//     System.out.print(' ');
	// }
	// System.out.println();
	
	String filename;
	filename = args[0];

	list = readFile(list, filename);
	int[] array = convertIntegers(list);
	
	long startTime = System.nanoTime();
	quickSort(array, 0, array.length - 1);
	long endTime = System.nanoTime();
	
	// System.out.print("Array after it is sorted : ");
	// for (int i = 0; i < 10; i++) {
	//     System.out.print(array[i]);
	//     System.out.print(' ');
	// }
	// System.out.println();
	endTime -= startTime;
	endTime /= 100000000;
	double time = endTime;

	System.out.printf("Program took %f seconds\n", time);
    }

    public static List<Integer> readFile(List<Integer> list, String filename) {
	try {
	    BufferedReader br = new BufferedReader(new FileReader(filename));
	    String num;
	    while ((num = br.readLine()) != null) {
		list.add(Integer.parseInt(num));
	    }
	} catch (FileNotFoundException ex) {
	    Logger.getLogger(QuickSort.class.getName()).log(Level.SEVERE, null, ex);
	} catch (IOException ex) {
	    System.out.println("ERROR: " + ex.getMessage());
	}
	return list;
    }

    public static int[] convertIntegers(List<Integer> integers)
    {
	int[] ret = new int[integers.size()];
	for (int i=0; i < ret.length; i++)
	    {
		ret[i] = integers.get(i).intValue();
	    }
	return ret;
    }

    public static int partition(int arr[], int left, int right)
    {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	
	while (i <= j) {
            while (arr[i] < pivot)
		i++;
            while (arr[j] > pivot)
		j--;
            if (i <= j) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
            }
	};
	
	return i;
    }
    
    public static void quickSort(int arr[], int left, int right) {
	int index = partition(arr, left, right);
	if (left < index - 1)
            quickSort(arr, left, index - 1);
	if (index < right)
            quickSort(arr, index, right);
    }
}
