#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n×k) | Space: O(1)
    int maxSumBruteForce(vector<int>& arr, int k) {
        int n = arr.size();
        int maxSum = INT_MIN;
        
        // Check each window of size k
        for (int i = 0; i <= n - k; i++) {
            // Calculate sum of current window
            int windowSum = 0;
            for (int j = i; j < i + k; j++) {
                windowSum += arr[j];
            }
            // Update maximum
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    // Time: O(n) | Space: O(1)
    int maxSumSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Calculate sum of first window
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        int maxSum = windowSum;
        
        // Slide window and update max
        for (int i = k; i < n; i++) {
            // Remove leftmost, add rightmost
            windowSum = windowSum - arr[i - k] + arr[i];
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    int maxSum(vector<int>& arr, int k) {
        return maxSumSlidingWindow(arr, k);
    }
};
