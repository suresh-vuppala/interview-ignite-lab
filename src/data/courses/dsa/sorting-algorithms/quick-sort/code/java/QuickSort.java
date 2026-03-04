class QuickSort {
    public void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high); // Get partition index
            quickSort(arr, low, pi - 1); // Sort left half
            quickSort(arr, pi + 1, high); // Sort right half
        }
    }
    
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; // Choose last element as pivot
        int i = low - 1; // Index of smaller element
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) { // If current element is smaller than pivot
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Place pivot in correct position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
}