#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    int lengthOfLISRecursive(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
    
private:
    int solve(vector<int>& nums, int i, int prev) {
        if (i == nums.size()) return 0;
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int skip = solve(nums, i + 1, prev);
        return max(take, skip);
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N²) | Space: O(N²)
    int lengthOfLISMemo(vector<int>& nums) {
        unordered_map<string, int> memo;
        return solveMemo(nums, 0, -1, memo);
    }
    
private:
    int solveMemo(vector<int>& nums, int i, int prev, unordered_map<string, int>& memo) {
        if (i == nums.size()) return 0;
        string key = to_string(i) + "," + to_string(prev);
        if (memo.count(key)) return memo[key];
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solveMemo(nums, i + 1, i, memo);
        }
        int skip = solveMemo(nums, i + 1, prev, memo);
        memo[key] = max(take, skip);
        return memo[key];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N²) | Space: O(N)
    int lengthOfLISTab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    
    // ==================== SOLUTION 4: BINARY SEARCH (OPTIMAL) ====================
    // Time: O(N log N) | Space: O(N)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);
            if (it == sub.end()) {
                sub.push_back(num);
            } else {
                *it = num;
            }
        }
        return sub.size();
    }
};
