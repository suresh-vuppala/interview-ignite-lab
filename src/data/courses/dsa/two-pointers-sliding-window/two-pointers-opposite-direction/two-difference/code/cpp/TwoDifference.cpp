#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// ==================== SOLUTION 1: BRUTE FORCE ====================
// Time: O(N²) | Space: O(1)
bool twoDifferenceBrute(vector<int>& arr, int k) {
    int n = arr.size();
    // Check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] - arr[i] == k) {  // Found pair with difference k
                return true;
            }
        }
    }
    return false;
}

// ==================== SOLUTION 2: TWO POINTERS ====================
// Time: O(N) | Space: O(1)
bool twoDifferenceTwoPointers(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = 1;
    
    while (right < n) {
        int diff = arr[right] - arr[left];
        
        // Found the pair
        if (diff == k && left != right) {
            return true;
        }
        
        // Difference too small, move right pointer
        if (diff < k) {
            right++;
        }
        // Difference too large, move left pointer
        else {
            left++;
        }
        
        // Ensure pointers don't overlap
        if (left == right) {
            right++;
        }
    }
    
    return false;
}

// ==================== SOLUTION 3: HASHSET ====================
// Time: O(N) | Space: O(N)
bool twoDifferenceHashSet(vector<int>& arr, int k) {
    unordered_set<int> seen;
    
    for (int num : arr) {
        // Check if num + k or num - k exists
        if (seen.count(num + k) || seen.count(num - k)) {
            return true;
        }
        seen.insert(num);
    }
    
    return false;
}

// ==================== SOLUTION 4: BINARY SEARCH ====================
// Time: O(N log N) | Space: O(1)
bool binarySearch(vector<int>& arr, int start, int target) {
    int left = start, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

bool twoDifferenceBinarySearch(vector<int>& arr, int k) {
    // For each element, search for element + k
    for (int i = 0; i < arr.size(); i++) {
        if (binarySearch(arr, i + 1, arr[i] + k)) {
            return true;
        }
    }
    return false;
}

// Main solution - recommended approach
bool twoDifference(vector<int>& arr, int k) {
    return twoDifferenceTwoPointers(arr, k);
}
