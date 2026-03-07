// Time: O(N²), Space: O(1)

class Solution {
    public void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}

public class InsertionSort {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        sol.insertionSort(arr);
        for (int num : arr) System.out.print(num + " ");
    }
}
