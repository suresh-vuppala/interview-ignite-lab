#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n×k) | Space: O(1)
    vector<int> maxSlidingWindowBruteForce(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        
        // For each window
        for (int i = 0; i <= n - k; i++) {
            // Find max in window
            int windowMax = *max_element(arr.begin() + i, arr.begin() + i + k);
            result.push_back(windowMax);
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: MONOTONIC DEQUE - OPTIMAL ====================
    // Time: O(n) | Space: O(k)
    vector<int> maxSlidingWindowDeque(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        deque<int> dq;  // Store indices in decreasing order of values
        
        for (int i = 0; i < n; i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove indices with smaller values (can't be max)
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            
            // Add current index
            dq.push_back(i);
            
            // Add max to result (after first window is complete)
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        
        return result;
    }
    
    // ==================== SOLUTION 3: USING MAX HEAP ====================
    // Time: O(n log k) | Space: O(k)
    vector<int> maxSlidingWindowHeap(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        priority_queue<pair<int, int>> heap;  // Max heap: (value, index)
        
        // Add first k elements
        for (int i = 0; i < k; i++) {
            heap.push({arr[i], i});
        }
        
        result.push_back(heap.top().first);
        
        // Process remaining elements
        for (int i = k; i < n; i++) {
            // Add new element
            heap.push({arr[i], i});
            
            // Remove elements outside window
            while (!heap.empty() && heap.top().second <= i - k) {
                heap.pop();
            }
            
            // Top is maximum
            result.push_back(heap.top().first);
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        return maxSlidingWindowDeque(arr, k);
    }
};
