int mergeSort(int[] arr, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    return mergeSort(arr, l, m) + mergeSort(arr, m + 1, r) + merge(arr, l, m, r);
}

int merge(int[] arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, inv = 0;
    int[] L = new int[n1], R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            inv += n1 - i;
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    return inv;
}