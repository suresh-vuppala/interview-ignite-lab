int[] merge(int[] arr1, int[] arr2) {
    int n = arr1.length, m = arr2.length;
    int[] result = new int[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) 
        result[k++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
    while (i < n) result[k++] = arr1[i++];
    while (j < m) result[k++] = arr2[j++];
    return result;
}