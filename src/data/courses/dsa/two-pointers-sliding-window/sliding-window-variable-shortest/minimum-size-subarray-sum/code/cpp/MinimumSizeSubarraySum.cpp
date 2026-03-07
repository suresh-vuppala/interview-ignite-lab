#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n²) | Space: O(1)
    int minSubArrayLenBruteForce(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        
        // Check all subarrays
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                
                // Check if sum >= target
                if (currentSum >= target) {
                    minLen = min(minLen, j - i + 1);
                    break;  // No need to extend further
                }
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    // Time: O(n) | Space: O(1)
    int minSubArrayLenSlidingWindow(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int currentSum = 0;
        int minLen = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            // Add element to window
            currentSum += nums[right];
            
            // Shrink window while sum >= target
            while (currentSum >= target) {
                minLen = min(minLen, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
    
    // ==================== SOLUTION 3: BINARY SEARCH + PREFIX SUM ====================
    // Time: O(n log n) | Space: O(n)
    int minSubArrayLenBinarySearch(int target, vector<int>& nums) {
        int n = nums.size();
        
        // Build prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int minLen = INT_MAX;
        
        // For each starting position
        for (int i = 0; i < n; i++) {
            // Binary search for smallest j where sum[i:j] >= target
            int toFind = target + prefix[i];
            int left = i + 1, right = n;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (prefix[mid] >= toFind) {
                    minLen = min(minLen, mid - i);
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    int minSubArrayLen(int target, vector<int>& nums) {
        return minSubArrayLenSlidingWindow(target, nums);
    }
};
