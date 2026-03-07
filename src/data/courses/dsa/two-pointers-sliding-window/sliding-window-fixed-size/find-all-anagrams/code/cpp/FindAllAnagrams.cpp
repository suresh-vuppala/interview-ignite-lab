#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE WITH SORTING ====================
    // Time: O(n×k log k) | Space: O(k)
    vector<int> findAnagramsBruteForce(string s, string p) {
        vector<int> result;
        int k = p.length();
        int n = s.length();
        string sortedP = p;
        sort(sortedP.begin(), sortedP.end());
        
        // Check each window
        for (int i = 0; i <= n - k; i++) {
            string window = s.substr(i, k);
            sort(window.begin(), window.end());
            if (window == sortedP) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAP ====================
    // Time: O(n) | Space: O(1)
    vector<int> findAnagramsFreqMap(string s, string p) {
        vector<int> result;
        int k = p.length();
        int n = s.length();
        
        if (n < k) return result;
        
        // Build frequency maps
        unordered_map<char, int> pCount, windowCount;
        
        for (char c : p) {
            pCount[c]++;
        }
        
        // First window
        for (int i = 0; i < k; i++) {
            windowCount[s[i]]++;
        }
        
        // Check first window
        if (windowCount == pCount) {
            result.push_back(0);
        }
        
        // Slide window
        for (int i = k; i < n; i++) {
            // Add new character
            windowCount[s[i]]++;
            
            // Remove old character
            windowCount[s[i - k]]--;
            if (windowCount[s[i - k]] == 0) {
                windowCount.erase(s[i - k]);
            }
            
            // Check if anagram
            if (windowCount == pCount) {
                result.push_back(i - k + 1);
            }
        }
        
        return result;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED WITH MATCH COUNT ====================
    // Time: O(n) | Space: O(1)
    vector<int> findAnagramsOptimized(string s, string p) {
        vector<int> result;
        int k = p.length();
        int n = s.length();
        
        if (n < k) return result;
        
        // Frequency arrays for lowercase letters
        vector<int> pCount(26, 0), windowCount(26, 0);
        
        // Build pattern frequency
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        // Build first window
        for (int i = 0; i < k; i++) {
            windowCount[s[i] - 'a']++;
        }
        
        // Count initial matches
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (pCount[i] == windowCount[i]) {
                matches++;
            }
        }
        
        if (matches == 26) {
            result.push_back(0);
        }
        
        // Slide window
        for (int i = k; i < n; i++) {
            // Add new character
            int newIdx = s[i] - 'a';
            windowCount[newIdx]++;
            if (windowCount[newIdx] == pCount[newIdx]) {
                matches++;
            } else if (windowCount[newIdx] == pCount[newIdx] + 1) {
                matches--;
            }
            
            // Remove old character
            int oldIdx = s[i - k] - 'a';
            windowCount[oldIdx]--;
            if (windowCount[oldIdx] == pCount[oldIdx]) {
                matches++;
            } else if (windowCount[oldIdx] == pCount[oldIdx] - 1) {
                matches--;
            }
            
            // Check if all match
            if (matches == 26) {
                result.push_back(i - k + 1);
            }
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    vector<int> findAnagrams(string s, string p) {
        return findAnagramsOptimized(s, p);
    }
};
