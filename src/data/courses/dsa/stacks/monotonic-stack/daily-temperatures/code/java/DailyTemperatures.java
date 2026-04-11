// ============================================================
// Daily Temperatures
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int[] dailyTemperatures(int[] temps) {
        int[] result = new int[temps.length];
        for (int i = 0; i < temps.length; i++)
            for (int j = i+1; j < temps.length; j++)
                if (temps[j] > temps[i]) { result[i] = j - i; break; }
        return result;
    }
}

// ============================================================
// Solution 2: Monotonic Stack (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int[] dailyTemperatures(int[] temps) {
        int[] result = new int[temps.length];
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < temps.length; i++) {
            while (!stack.isEmpty() && temps[i] > temps[stack.peek()]) {
                int idx = stack.pop();
                result[idx] = i - idx;
            }
            stack.push(i);
        }

        return result;
    }
}
