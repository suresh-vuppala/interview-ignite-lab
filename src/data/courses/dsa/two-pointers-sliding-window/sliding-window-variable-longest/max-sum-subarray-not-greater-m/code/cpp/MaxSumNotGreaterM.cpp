#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

// ==================== SOLUTION 1: BRUTE FORCE ====================
// Time: O(N³) | Space: O(1)
int maxSumBrute(vector<int>& arr, int M) {
    int n = arr.size();
    int maxSum = 0;
    
    // Check all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Calculate sum of subarray [i...j]
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += arr[k];
            }
            if (currentSum <= M) {
                maxSum = max(maxSum, currentSum);
            }
        }
    }
    
    return maxSum;
}

// ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
// Time: O(N²) | Space: O(1)
int maxSumOptimized(vector<int>& arr, int M) {
    int n = arr.size();
    int maxSum = 0;
    
    // For each starting position
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        // Extend subarray
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            if (currentSum <= M) {
                maxSum = max(maxSum, currentSum);
            }
        }
    }
    
    return maxSum;
}

// ==================== SOLUTION 3: SLIDING WINDOW (POSITIVE INTEGERS) ====================
// Time: O(N) | Space: O(1)
int maxSumSlidingWindow(vector<int>& arr, int M) {
    int n = arr.size();
    int left = 0;
    int currentSum = 0;
    int maxSum = 0;
    
    // Expand window with right pointer
    for (int right = 0; right < n; right++) {
        currentSum += arr[right];
        
        // Shrink window if sum exceeds M
        while (currentSum > M && left <= right) {
            currentSum -= arr[left];
            left++;
        }
        
        // Update max sum
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

// ==================== SOLUTION 4: PREFIX SUM + BINARY SEARCH ====================
// Time: O(N log N) | Space: O(N)
int maxSumPrefixBinarySearch(vector<int>& arr, int M) {
    set<long long> prefixSums;
    prefixSums.insert(0);
    
    long long prefixSum = 0;
    int maxSum = 0;
    
    for (int num : arr) {
        prefixSum += num;
        
        // Find smallest prefix >= (prefixSum - M)
        long long target = prefixSum - M;
        auto it = prefixSums.lower_bound(target);
        
        if (it != prefixSums.end()) {
            maxSum = max(maxSum, (int)(prefixSum - *it));
        }
        
        prefixSums.insert(prefixSum);
    }
    
    return maxSum;
}

// Main solution - recommended approach
int maxSumNotGreaterM(vector<int>& arr, int M) {
    // Check if all positive
    bool allPositive = true;
    for (int x : arr) {
        if (x <= 0) {
            allPositive = false;
            break;
        }
    }
    
    // Use sliding window for positive integers
    if (allPositive) {
        return maxSumSlidingWindow(arr, M);
    }
    // Use prefix sum for arrays with negatives
    return maxSumPrefixBinarySearch(arr, M);
}
