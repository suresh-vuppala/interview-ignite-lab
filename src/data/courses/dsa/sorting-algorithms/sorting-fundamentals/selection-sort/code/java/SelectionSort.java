// Time: O(N²), Space: O(1)

class Solution {
    public void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

public class SelectionSort {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        sol.selectionSort(arr);
        for (int num : arr) System.out.print(num + " ");
    }
}
