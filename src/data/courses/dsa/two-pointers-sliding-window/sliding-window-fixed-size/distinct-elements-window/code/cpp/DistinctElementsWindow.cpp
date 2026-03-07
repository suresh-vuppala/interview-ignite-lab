#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// ==================== SOLUTION 1: BRUTE FORCE ====================
// Time: O(N×K) | Space: O(N)
vector<int> distinctElementsBrute(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    
    // For each window
    for (int i = 0; i <= n - k; i++) {
        unordered_set<int> distinct;
        // Add all elements in window to set
        for (int j = i; j < i + k; j++) {
            distinct.insert(arr[j]);
        }
        result.push_back(distinct.size());
    }
    
    return result;
}

// ==================== SOLUTION 2: SLIDING WINDOW WITH HASHMAP ====================
// Time: O(N) | Space: O(N)
vector<int> distinctElementsSliding(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return {};
    
    unordered_map<int, int> freq;
    vector<int> result;
    
    // Build first window
    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }
    result.push_back(freq.size());
    
    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove leftmost element of previous window
        int leftElem = arr[i - k];
        freq[leftElem]--;
        if (freq[leftElem] == 0) {
            freq.erase(leftElem);
        }
        
        // Add new element to window
        freq[arr[i]]++;
        
        // Count distinct elements
        result.push_back(freq.size());
    }
    
    return result;
}

// ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
// Time: O(N) | Space: O(N)
vector<int> distinctElementsOptimized(vector<int>& arr, int k) {
    int n = arr.size();
    
    // Edge cases
    if (k <= 0 || k > n) return {};
    
    unordered_map<int, int> freq;
    vector<int> result;
    
    // Process first window
    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }
    result.push_back(freq.size());
    
    // Slide window from k to n-1
    for (int i = k; i < n; i++) {
        // Remove element going out of window
        int outElem = arr[i - k];
        freq[outElem]--;
        if (freq[outElem] == 0) {
            freq.erase(outElem);
        }
        
        // Add element coming into window
        int inElem = arr[i];
        freq[inElem]++;
        
        // Record distinct count
        result.push_back(freq.size());
    }
    
    return result;
}

// Main solution - recommended approach
vector<int> distinctElementsWindow(vector<int>& arr, int k) {
    return distinctElementsSliding(arr, k);
}
