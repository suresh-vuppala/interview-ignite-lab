#include <vector>
using namespace std;

// ==================== SOLUTION 1: BRUTE FORCE ====================
// Time: O(N³) | Space: O(1)
int subarrayProductBrute(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    
    // Check all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Calculate product of subarray [i...j]
            int product = 1;
            for (int idx = i; idx <= j; idx++) {
                product *= nums[idx];
            }
            
            if (product < k) {
                count++;
            }
        }
    }
    
    return count;
}

// ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
// Time: O(N²) | Space: O(1)
int subarrayProductOptimized(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    
    // For each starting position
    for (int i = 0; i < n; i++) {
        int product = 1;
        // Extend subarray
        for (int j = i; j < n; j++) {
            product *= nums[j];
            
            if (product < k) {
                count++;
            } else {
                break;  // Product will only increase
            }
        }
    }
    
    return count;
}

// ==================== SOLUTION 3: SLIDING WINDOW ====================
// Time: O(N) | Space: O(1)
int subarrayProductSlidingWindow(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    
    int left = 0;
    int product = 1;
    int count = 0;
    
    // Expand window with right pointer
    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right];
        
        // Shrink window if product >= k
        while (product >= k && left <= right) {
            product /= nums[left];
            left++;
        }
        
        // Count all subarrays ending at right
        count += (right - left + 1);
    }
    
    return count;
}

// Main solution - recommended approach
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    return subarrayProductSlidingWindow(nums, k);
}
