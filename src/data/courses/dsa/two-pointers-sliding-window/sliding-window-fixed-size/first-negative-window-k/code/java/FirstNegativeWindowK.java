// ============================================================
// First Negative in Every Window of Size K
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N×K) | Space: O(1)
// ============================================================
class Solution1 {
    public int[] firstNegative(int[] nums, int k) {
        int[] result = new int[nums.length - k + 1];
        for (int i = 0; i <= nums.length - k; i++) {
            for (int j = i; j < i + k; j++) {
                if (nums[j] < 0) { result[i] = nums[j]; break; }
            }
        }
        return result;
    }
}

// ============================================================
// Solution 2: Deque of Negative Indices (Optimal)
// Time: O(N) | Space: O(K)
// ============================================================
class Solution2 {
    public int[] firstNegative(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int[] result = new int[nums.length - k + 1];
        int idx = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0) dq.offerLast(i);

            if (i >= k - 1) {
                while (!dq.isEmpty() && dq.peekFirst() < i - k + 1)
                    dq.pollFirst();
                result[idx++] = dq.isEmpty() ? 0 : nums[dq.peekFirst()];
            }
        }

        return result;
    }
}
