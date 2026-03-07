import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    public int lengthOfLISRecursive(int[] nums) {
        return solve(nums, 0, -1);
    }
    
    private int solve(int[] nums, int i, int prev) {
        if (i == nums.length) return 0;
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int skip = solve(nums, i + 1, prev);
        return Math.max(take, skip);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N²) | Space: O(N²)
    public int lengthOfLISMemo(int[] nums) {
        Map<String, Integer> memo = new HashMap<>();
        return solveMemo(nums, 0, -1, memo);
    }
    
    private int solveMemo(int[] nums, int i, int prev, Map<String, Integer> memo) {
        if (i == nums.length) return 0;
        String key = i + "," + prev;
        if (memo.containsKey(key)) return memo.get(key);
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solveMemo(nums, i + 1, i, memo);
        }
        int skip = solveMemo(nums, i + 1, prev, memo);
        int result = Math.max(take, skip);
        memo.put(key, result);
        return result;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N²) | Space: O(N)
    public int lengthOfLISTab(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        int max = 0;
        for (int len : dp) max = Math.max(max, len);
        return max;
    }
    
    // ==================== SOLUTION 4: BINARY SEARCH (OPTIMAL) ====================
    // Time: O(N log N) | Space: O(N)
    public int lengthOfLIS(int[] nums) {
        List<Integer> sub = new ArrayList<>();
        for (int num : nums) {
            int left = 0, right = sub.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sub.get(mid) < num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left == sub.size()) {
                sub.add(num);
            } else {
                sub.set(left, num);
            }
        }
        return sub.size();
    }
}
