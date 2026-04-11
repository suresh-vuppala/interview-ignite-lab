// ============================================================
// Sliding Window Maximum
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N×K) | Space: O(1)
// ============================================================
class Solution1 {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] result = new int[nums.length - k + 1];
        for (int i = 0; i <= nums.length - k; i++) {
            int max = nums[i];
            for (int j = i + 1; j < i + k; j++) max = Math.max(max, nums[j]);
            result[i] = max;
        }
        return result;
    }
}

// ============================================================
// Solution 2: Monotonic Decreasing Deque (Optimal)
// Time: O(N) | Space: O(K)
// ============================================================
class Solution2 {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int[] result = new int[nums.length - k + 1];
        int idx = 0;

        for (int i = 0; i < nums.length; i++) {
            // Remove expired
            while (!dq.isEmpty() && dq.peekFirst() < i - k + 1) dq.pollFirst();

            // Remove smaller
            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) dq.pollLast();

            dq.offerLast(i);

            if (i >= k - 1) result[idx++] = nums[dq.peekFirst()];
        }

        return result;
    }
}
