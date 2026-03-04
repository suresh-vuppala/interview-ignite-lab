class KthLargestElement {
    public int findKthLargest(int[] arr, int k) {
        return quickSelect(arr, 0, arr.length - 1, arr.length - k); // Convert to 0-indexed position
    }
    
    private int quickSelect(int[] arr, int low, int high, int k) {
        int pi = partition(arr, low, high); // Partition array
        if (pi == k) return arr[pi]; // Found kth largest
        if (pi > k) return quickSelect(arr, low, pi - 1, k); // Search left
        return quickSelect(arr, pi + 1, high, k); // Search right
    }
    
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
}