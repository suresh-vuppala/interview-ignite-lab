// ============================================================
// Intersection of Two Arrays II
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Sort + Two Pointers
// Time: O(N log N + M log M) | Space: O(1) extra
// ============================================================
class Solution1 {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;

        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j]) { result.add(nums1[i]); i++; j++; }
            else if (nums1[i] < nums2[j]) i++;
            else j++;
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}

// ============================================================
// Solution 2: Hash Map Frequency (Optimal)
// Time: O(N + M) | Space: O(min(N,M))
// ============================================================
class Solution2 {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int n : nums1) freq.merge(n, 1, Integer::sum);

        List<Integer> result = new ArrayList<>();
        for (int n : nums2) {
            if (freq.getOrDefault(n, 0) > 0) {
                result.add(n);
                freq.merge(n, -1, Integer::sum);
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
