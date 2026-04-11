// ============================================================
// Subarrays with K Different Integers
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution1 {
    public int subarraysWithKDistinct(int[] nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            Map<Integer,Integer> f = new HashMap<>();
            for (int j = i; j < nums.length; j++) {
                f.merge(nums[j], 1, Integer::sum);
                if (f.size() == k) count++;
                if (f.size() > k) break;
            }
        }
        return count;
    }
}

// ============================================================
// Solution 2: At Most K Decomposition (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    private int atMostK(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0, count = 0;
        for (int right = 0; right < nums.length; right++) {
            freq.merge(nums[right], 1, Integer::sum);
            while (freq.size() > k) {
                freq.merge(nums[left], -1, Integer::sum);
                if (freq.get(nums[left]) == 0) freq.remove(nums[left]);
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
}
