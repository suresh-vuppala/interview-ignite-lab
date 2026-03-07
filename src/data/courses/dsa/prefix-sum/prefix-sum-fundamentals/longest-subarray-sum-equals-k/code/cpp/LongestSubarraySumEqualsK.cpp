#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LongestSubarraySumEqualsK {
public:
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N³) | Space: O(1)
    
    static int longestSubarrayBrute(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int subarraySum = 0;
                for (int idx = i; idx <= j; idx++) {
                    subarraySum += nums[idx];
                }
                if (subarraySum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    // Time: O(N²) | Space: O(1)
    
    static int longestSubarrayOptimized(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                if (currentSum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== SOLUTION 3: PREFIX SUM WITH HASHMAP ====================
    // Time: O(N) | Space: O(N)
    
    static int longestSubarrayPrefixSum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = -1;  // Empty prefix before index 0
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            // Check if (prefixSum - k) exists
            if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
                int length = i - prefixSumMap[prefixSum - k];
                maxLen = max(maxLen, length);
            }
            
            // Store first occurrence only (to maximize length)
            if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
                prefixSumMap[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== SOLUTION 4: SLIDING WINDOW (POSITIVE ONLY) ====================
    // Time: O(N) | Space: O(1)
    
    static int longestSubarraySlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int currentSum = 0;
        int maxLen = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            
            while (currentSum > k && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            if (currentSum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    
    static int longestSubarraySumK(vector<int>& nums, int k) {
        /*
         * Find length of longest subarray with sum equal to k.
         * 
         * Time: O(N) - single pass
         * Space: O(N) - HashMap
         * 
         * Works with negative numbers and zeros.
         */
        return longestSubarrayPrefixSum(nums, k);
    }
};
