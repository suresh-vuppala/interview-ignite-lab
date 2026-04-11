#include <vector>
#include <unordered_map>
using namespace std;

// ==================== SOLUTION 1: BRUTE FORCE ====================
// Time: O(N²) | Space: O(1)
// Check every pair of elements for the target sum
vector<int> twoSumBrute(vector<int>& nums, int target) {
    int n = nums.size();
    
    // Try all pairs (i, j) where i < j
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if this pair sums to target
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    
    return {}; // No solution found (shouldn't happen per constraints)
}

// ==================== SOLUTION 2: HASH MAP — ONE PASS ====================
// Time: O(N) | Space: O(N)
// Store seen numbers in map, look up complement in O(1)
vector<int> twoSumHashMap(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // value -> index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement was already seen
        if (seen.count(complement)) {
            return {seen[complement], i};
        }
        
        // Store current number for future lookups
        // (check BEFORE insert to avoid using same element twice)
        seen[nums[i]] = i;
    }
    
    return {}; // No solution found
}

// Main solution - recommended approach
vector<int> twoSum(vector<int>& nums, int target) {
    return twoSumHashMap(nums, target);
}
