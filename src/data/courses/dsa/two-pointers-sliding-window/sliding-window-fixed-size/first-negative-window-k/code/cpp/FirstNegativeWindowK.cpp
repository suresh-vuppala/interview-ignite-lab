#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n×k) | Space: O(1)
    vector<int> firstNegativeBruteForce(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        
        // For each window
        for (int i = 0; i <= n - k; i++) {
            // Find first negative in window
            int firstNeg = 0;
            for (int j = i; j < i + k; j++) {
                if (arr[j] < 0) {
                    firstNeg = arr[j];
                    break;
                }
            }
            result.push_back(firstNeg);
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH DEQUE - OPTIMAL ====================
    // Time: O(n) | Space: O(k)
    vector<int> firstNegativeDeque(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        deque<int> dq;  // Store indices of negative numbers
        
        // Process first window
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }
        
        // First window result
        result.push_back(dq.empty() ? 0 : arr[dq.front()]);
        
        // Process remaining windows
        for (int i = k; i < n; i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Add current element if negative
            if (arr[i] < 0) {
                dq.push_back(i);
            }
            
            // First negative in current window
            result.push_back(dq.empty() ? 0 : arr[dq.front()]);
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    vector<int> firstNegative(vector<int>& arr, int k) {
        return firstNegativeDeque(arr, k);
    }
};
