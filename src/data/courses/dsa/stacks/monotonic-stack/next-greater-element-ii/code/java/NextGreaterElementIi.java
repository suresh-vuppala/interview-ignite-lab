// ============================================================
// Next Greater Element II (Circular)
// ============================================================

import java.util.*;

class Solution1 {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length; int[] res = new int[n]; Arrays.fill(res, -1);
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                if (nums[(i+j)%n] > nums[i]) { res[i] = nums[(i+j)%n]; break; }
        return res;
    }
}

class Solution2 {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length; int[] res = new int[n]; Arrays.fill(res, -1);
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < 2 * n; i++) {
            while (!stack.isEmpty() && nums[i%n] > nums[stack.peek()])
                res[stack.pop()] = nums[i%n];
            if (i < n) stack.push(i);
        }
        return res;
    }
}
