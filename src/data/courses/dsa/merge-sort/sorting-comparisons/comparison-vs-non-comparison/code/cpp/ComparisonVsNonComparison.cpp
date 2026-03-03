// Comparison-based: Merge Sort
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Non-comparison: Counting Sort
void countingSort(vector<int>& arr, int k) {
    vector<int> count(k + 1, 0);
    for (int x : arr) count[x]++;
    int idx = 0;
    for (int i = 0; i <= k; i++) {
        while (count[i]-- > 0) arr[idx++] = i;
    }
}