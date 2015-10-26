public class BubbleSort {

    public static void main(String args[]) {
	int[] array = new int[]{5, 3, 8, 2, 1, 4, 7, 6, 10, 9};
	
	System.out.print("Array before it is sorted: ");
	for (int i = 0; i < 10; i++) {
	    System.out.print(array[i]);
	    System.out.print(' ');
	}
	System.out.println();
	
	bubbleSort(array);
	
	System.out.print("Array after it is sorted : ");
	for (int i = 0; i < 10; i++) {
	    System.out.print(array[i]);
	    System.out.print(' ');
	}
	System.out.println();
    }
    
    public static void bubbleSort(int[] arr) {
      boolean swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
	  swapped = false;
	  j++;
	  for (int i = 0; i < arr.length - j; i++) {
	      if (arr[i] > arr[i + 1]) {                          
		  tmp = arr[i];
		  arr[i] = arr[i + 1];
		  arr[i + 1] = tmp;
		  swapped = true;
	      }
	      
	  }                
	  
      }
      
    }
}