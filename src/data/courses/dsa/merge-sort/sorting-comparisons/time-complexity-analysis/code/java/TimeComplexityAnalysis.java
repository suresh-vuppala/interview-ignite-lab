// Merge Sort: O(n log n) always
void mergeSort(int[] arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);        // T(n/2)
        mergeSort(arr, m + 1, r);    // T(n/2)
        merge(arr, l, m, r);         // O(n)
    }
}
// Recurrence: T(n) = 2T(n/2) + O(n) = O(n log n)

// Quick Sort: O(n log n) average, O(n²) worst
void quickSort(int[] arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);  // O(n)
        quickSort(arr, l, p - 1);      // T(n/2) avg
        quickSort(arr, p + 1, r);      // T(n/2) avg
    }
}
// Best/Avg: T(n) = 2T(n/2) + O(n) = O(n log n)
// Worst: T(n) = T(n-1) + O(n) = O(n²)