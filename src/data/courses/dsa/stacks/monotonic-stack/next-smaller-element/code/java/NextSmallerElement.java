// ============================================================
// Next Smaller Element
// ============================================================

import java.util.*;

class Solution1 {
    public int[] nextSmaller(int[] nums) {
        int[] res = new int[nums.length]; Arrays.fill(res, -1);
        for (int i = 0; i < nums.length; i++)
            for (int j = i+1; j < nums.length; j++)
                if (nums[j] < nums[i]) { res[i] = nums[j]; break; }
        return res;
    }
}

class Solution2 {
    public int[] nextSmaller(int[] nums) {
        int[] res = new int[nums.length]; Arrays.fill(res, -1);
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[i] < nums[stack.peek()])
                res[stack.pop()] = nums[i];
            stack.push(i);
        }
        return res;
    }
}
