// ============================================================
// Previous Greater and Previous Smaller
// ============================================================

import java.util.*;

class Solution {
    public int[] previousGreater(int[] nums) {
        int[] res = new int[nums.length]; Arrays.fill(res, -1);
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] <= nums[i]) stack.pop();
            if (!stack.isEmpty()) res[i] = nums[stack.peek()];
            stack.push(i);
        }
        return res;
    }

    public int[] previousSmaller(int[] nums) {
        int[] res = new int[nums.length]; Arrays.fill(res, -1);
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] >= nums[i]) stack.pop();
            if (!stack.isEmpty()) res[i] = nums[stack.peek()];
            stack.push(i);
        }
        return res;
    }
}
