// Merge Sort: O(n) space
void merge(int[] arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int[] L = new int[n1], R = new int[n2]; // O(n) space
    // ... merge logic
}

// Quick Sort: O(log n) space (recursion stack)
void quickSort(int[] arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r); // O(1) space
        quickSort(arr, l, p - 1);     // Stack depth O(log n)
        quickSort(arr, p + 1, r);
    }
}

// Heap Sort: O(1) space
void heapSort(int[] arr) {
    int n = arr.length;
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}