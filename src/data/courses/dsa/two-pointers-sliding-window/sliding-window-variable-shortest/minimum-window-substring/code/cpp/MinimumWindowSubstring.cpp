#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n³) | Space: O(m)
    string minWindowBruteForce(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }
        
        string minWindow = "";
        int minLen = INT_MAX;
        
        // Check all substrings
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                string window = s.substr(i, j - i + 1);
                
                if (containsAll(window, tCount) && window.length() < minLen) {
                    minLen = window.length();
                    minWindow = window;
                }
            }
        }
        
        return minWindow;
    }
    
    bool containsAll(string window, unordered_map<char, int>& tCount) {
        unordered_map<char, int> windowCount;
        for (char c : window) {
            windowCount[c]++;
        }
        
        for (auto& entry : tCount) {
            if (windowCount[entry.first] < entry.second) {
                return false;
            }
        }
        return true;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAPS ====================
    // Time: O(n+m) | Space: O(m+k)
    string minWindowSlidingWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }
        
        unordered_map<char, int> windowCount;
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Add character to window
            windowCount[s[right]]++;
            
            // Try to shrink window
            while (containsAllChars(windowCount, tCount)) {
                // Update minimum
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Shrink from left
                windowCount[s[left]]--;
                if (windowCount[s[left]] == 0) {
                    windowCount.erase(s[left]);
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
    
    bool containsAllChars(unordered_map<char, int>& window, unordered_map<char, int>& t) {
        for (auto& entry : t) {
            if (window[entry.first] < entry.second) {
                return false;
            }
        }
        return true;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED WITH MATCH COUNT ====================
    // Time: O(n+m) | Space: O(m+k)
    string minWindowOptimized(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }
        
        int required = tCount.size();
        unordered_map<char, int> windowCount;
        int matched = 0;
        
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Add character to window
            char c = s[right];
            windowCount[c]++;
            
            // Check if frequency matches
            if (tCount.count(c) && windowCount[c] == tCount[c]) {
                matched++;
            }
            
            // Try to shrink window
            while (matched == required) {
                // Update minimum
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Shrink from left
                char leftChar = s[left];
                windowCount[leftChar]--;
                if (tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar]) {
                    matched--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    string minWindow(string s, string t) {
        return minWindowOptimized(s, t);
    }
};
