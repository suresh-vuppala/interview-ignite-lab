#include <vector>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n×k) | Space: O(1)
    vector<pair<vector<int>, int>> subarraySumBruteForce(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<vector<int>, int>> result;
        
        // For each starting position
        for (int i = 0; i <= n - k; i++) {
            // Calculate sum of k elements
            int windowSum = 0;
            vector<int> window;
            for (int j = i; j < i + k; j++) {
                windowSum += arr[j];
                window.push_back(arr[j]);
            }
            result.push_back({window, windowSum});
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    // Time: O(n) | Space: O(1)
    vector<pair<vector<int>, int>> subarraySumSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<vector<int>, int>> result;
        
        // Calculate sum of first window
        int windowSum = 0;
        vector<int> firstWindow;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
            firstWindow.push_back(arr[i]);
        }
        result.push_back({firstWindow, windowSum});
        
        // Slide window
        for (int i = k; i < n; i++) {
            // Remove leftmost element, add rightmost element
            windowSum = windowSum - arr[i - k] + arr[i];
            vector<int> window(arr.begin() + i - k + 1, arr.begin() + i + 1);
            result.push_back({window, windowSum});
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    vector<pair<vector<int>, int>> subarraySum(vector<int>& arr, int k) {
        return subarraySumSlidingWindow(arr, k);
    }
};
