// ============================================================
// Minimum Window Substring
// ============================================================

#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²×M) | Space: O(M)
// ============================================================
class Solution1 {
public:
    string minWindow(string s, string t) {
        // Build frequency map for target string t
        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }
        
        int minLength = INT_MAX;
        int minStart = 0;
        
        // Try all possible substrings
        for (int start = 0; start < s.size(); start++) {
            unordered_map<char, int> windowFreq;
            
            for (int end = start; end < s.size(); end++) {
                // Add current character to window
                windowFreq[s[end]]++;
                
                // Check if current window contains all characters of t
                bool isValid = true;
                for (auto& [ch, count] : targetFreq) {
                    if (windowFreq[ch] < count) {
                        isValid = false;
                        break;
                    }
                }
                
                // Update minimum window if valid and smaller
                if (isValid && end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    minStart = start;
                    break; // No need to expand further from this start
                }
            }
        }
        
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};

// ============================================================
// Solution 2: Sliding Window + Frequency Tracking (Optimal)
// Time: O(N+M) | Space: O(N+M)
// ============================================================
class Solution2 {
public:
    string minWindow(string s, string t) {
        // Step 1: Build frequency map for target string t
        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }
        
        // Step 2: Initialize variables
        int required = targetFreq.size();  // Number of unique chars in t that need to be present
        int formed = 0;                     // Number of unique chars in current window with desired frequency
        
        unordered_map<char, int> windowFreq; // Frequency map for current window
        
        int left = 0;                       // Left pointer of sliding window
        int minLength = INT_MAX;            // Length of minimum window found
        int minStart = 0;                   // Start index of minimum window
        
        // Step 3: Expand window by moving right pointer
        for (int right = 0; right < s.size(); right++) {
            char rightChar = s[right];
            
            // Add character from right to window
            windowFreq[rightChar]++;
            
            // Check if frequency of current character matches the desired count in t
            if (targetFreq.count(rightChar) && 
                windowFreq[rightChar] == targetFreq[rightChar]) {
                formed++; // One more unique character requirement satisfied
            }
            
            // Step 4: Try to shrink window from left while it's still valid
            while (formed == required) {
                // Update minimum window if current is smaller
                int currentLength = right - left + 1;
                if (currentLength < minLength) {
                    minLength = currentLength;
                    minStart = left;
                }
                
                // Remove character from left of window
                char leftChar = s[left];
                windowFreq[leftChar]--;
                
                // Check if removing this character breaks a requirement
                if (targetFreq.count(leftChar) && 
                    windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--; // One unique character requirement no longer satisfied
                }
                
                left++; // Shrink window from left
            }
        }
        
        // Step 5: Return result
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};

// ============================================================
// Solution 3: Binary Search on Length + Sliding Window
// Time: O(N×log N) | Space: O(N+M)
// ============================================================
class Solution3 {
private:
    // Helper: Check if any window of given length contains all chars of t
    bool canFindWindow(string& s, string& t, int windowLen, int& resultStart) {
        // Build target frequency map
        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }
        
        unordered_map<char, int> windowFreq;
        int required = targetFreq.size();
        int formed = 0;
        
        // Initialize first window
        for (int i = 0; i < windowLen && i < s.size(); i++) {
            windowFreq[s[i]]++;
            if (targetFreq.count(s[i]) && 
                windowFreq[s[i]] == targetFreq[s[i]]) {
                formed++;
            }
        }
        
        // Check first window
        if (formed == required) {
            resultStart = 0;
            return true;
        }
        
        // Slide window across string
        for (int right = windowLen; right < s.size(); right++) {
            int left = right - windowLen;
            
            // Add new character on right
            char rightChar = s[right];
            windowFreq[rightChar]++;
            if (targetFreq.count(rightChar) && 
                windowFreq[rightChar] == targetFreq[rightChar]) {
                formed++;
            }
            
            // Remove character on left
            char leftChar = s[left];
            if (targetFreq.count(leftChar) && 
                windowFreq[leftChar] == targetFreq[leftChar]) {
                formed--;
            }
            windowFreq[leftChar]--;
            
            // Check if current window is valid
            if (formed == required) {
                resultStart = left + 1;
                return true;
            }
        }
        
        return false;
    }
    
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        // Binary search on window length
        int low = t.size();
        int high = s.size();
        int minLength = INT_MAX;
        int minStart = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int start = 0;
            
            // Check if window of length mid exists
            if (canFindWindow(s, t, mid, start)) {
                // Found valid window, try smaller length
                minLength = mid;
                minStart = start;
                high = mid - 1;
            } else {
                // Need larger window
                low = mid + 1;
            }
        }
        
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};
