// ============================================================
// Majority Element
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Hash Map — Count Frequencies
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            freq.merge(num, 1, Integer::sum);
            if (freq.get(num) > nums.length / 2) return num;
        }

        return -1;
    }
}

// ============================================================
// Solution 2: Sort + Middle Element
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution2 {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}

// ============================================================
// Solution 3: Boyer-Moore Voting Algorithm (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution3 {
    public int majorityElement(int[] nums) {
        int candidate = nums[0], count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (count == 0) { candidate = nums[i]; count = 1; }
            else if (nums[i] == candidate) count++;
            else count--;
        }

        return candidate;
    }
}
