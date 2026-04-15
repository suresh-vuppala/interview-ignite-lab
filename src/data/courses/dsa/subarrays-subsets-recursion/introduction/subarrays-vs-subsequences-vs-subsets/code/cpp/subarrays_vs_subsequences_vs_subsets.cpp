#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — generate subarrays O(N²), subsequences O(2^N)
// ============================================================
class Solution1 {
public:
    // Subarrays: contiguous, N*(N+1)/2 count
    vector<vector<int>> allSubarrays(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < (int)nums.size(); i++) {
            vector<int> sub;
            for (int j = i; j < (int)nums.size(); j++) {
                sub.push_back(nums[j]);
                result.push_back(sub);
            }
        }
        return result;
    }
    // Subsequences: order-preserved, 2^N count — bitmask approach
    vector<vector<int>> allSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> sub;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) sub.push_back(nums[i]);
            result.push_back(sub);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Conceptual Framework — definitions and counting
// ============================================================
class Solution2 {
public:
    // Subarray: contiguous slice [i..j], count = N*(N+1)/2
    // Subsequence: any subset maintaining order, count = 2^N
    // Subset: any selection (order doesn't matter), count = 2^N
    // Key: Subarray ⊂ Subsequence, Subset = Subsequence ignoring order
    int countSubarrays(int n) { return n * (n + 1) / 2; }
    int countSubsequences(int n) { return 1 << n; }
    int countSubsets(int n) { return 1 << n; }
};
