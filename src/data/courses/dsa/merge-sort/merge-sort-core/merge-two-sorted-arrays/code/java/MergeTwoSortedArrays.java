// Time: O(N+M) | Space: O(N+M) extra space, O(1) in-place

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> mergeWithExtraSpace(int[] arr1, int[] arr2) {
        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] <= arr2[j]) {
                result.add(arr1[i++]);
            } else {
                result.add(arr2[j++]);
            }
        }
        while (i < arr1.length) result.add(arr1[i++]);
        while (j < arr2.length) result.add(arr2[j++]);
        return result;
    }
    
    public void mergeInPlace(int[] arr1, int m, int[] arr2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && arr1[i] > arr2[j]) {
                arr1[k--] = arr1[i--];
            } else {
                arr1[k--] = arr2[j--];
            }
        }
    }
}
