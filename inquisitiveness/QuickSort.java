public class QuickSort {

    public static void main(String[] args) {
	int[] array = new int[]{5, 3, 8, 2, 1, 4, 7, 6, 10, 9};
	
	System.out.print("Array before it is sorted: ");
	for (int i = 0; i < 10; i++) {
	    System.out.print(array[i]);
	    System.out.print(' ');
	}
	System.out.println();
	
	quickSort(array, 0, 9);
	
	System.out.print("Array after it is sorted : ");
	for (int i = 0; i < 10; i++) {
	    System.out.print(array[i]);
	    System.out.print(' ');
	}
	System.out.println();
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