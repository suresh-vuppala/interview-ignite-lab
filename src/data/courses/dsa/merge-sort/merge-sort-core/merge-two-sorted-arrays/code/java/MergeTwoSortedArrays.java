// ============================================================
// Merge Sorted Array
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Copy + Sort
// Time: O((M+N) log(M+N)) | Space: O(1)
// ============================================================
class Solution1 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        System.arraycopy(nums2, 0, nums1, m, n);
        Arrays.sort(nums1);
    }
}

// ============================================================
// Solution 2: Three Pointers from End (Optimal)
// Time: O(M+N) | Space: O(1)
// ============================================================
class Solution2 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
}
