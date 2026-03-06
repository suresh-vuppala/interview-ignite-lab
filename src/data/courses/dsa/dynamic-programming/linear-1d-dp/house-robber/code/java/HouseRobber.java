import java.util.HashMap;

class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int robMemo(int[] nums) {
        HashMap<Integer, Integer> memo = new HashMap<>();
        return dpMemo(nums.length - 1, nums, memo);
    }
    
    private int dpMemo(int i, int[] nums, HashMap<Integer, Integer> memo) {
        if (i < 0) return 0;
        if (memo.containsKey(i)) return memo.get(i);
        int result = Math.max(nums[i] + dpMemo(i-2, nums, memo), dpMemo(i-1, nums, memo));
        memo.put(i, result);
        return result;
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    public int robTab(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    
    // ============ SPACE OPTIMIZED ============
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        
        int prev2 = nums[0], prev1 = Math.max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.length; i++) {
            int curr = Math.max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}