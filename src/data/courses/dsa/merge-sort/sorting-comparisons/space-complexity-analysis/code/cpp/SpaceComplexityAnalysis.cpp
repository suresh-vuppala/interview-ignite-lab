// Merge Sort: O(n) space
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1); // O(n) space
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    // ... merge logic
}

// Quick Sort: O(log n) space
void quickSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

// Heap Sort: O(1) space
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}