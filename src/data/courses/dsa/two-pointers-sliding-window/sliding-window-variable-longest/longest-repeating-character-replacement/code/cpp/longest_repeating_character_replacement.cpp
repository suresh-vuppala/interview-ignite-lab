#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n²) | Space: O(1)
    int characterReplacementBruteForce(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        
        // Check all substrings
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                // Update frequency
                freq[s[j] - 'A']++;
                
                // Find max frequency
                int maxFreq = *max_element(freq.begin(), freq.end());
                int length = j - i + 1;
                
                // Check if valid
                if (length - maxFreq <= k) {
                    maxLen = max(maxLen, length);
                }
            }
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAP ====================
    // Time: O(n×26) = O(n) | Space: O(1)
    int characterReplacementSlidingWindow(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            // Add character to window
            freq[s[right] - 'A']++;
            
            // Find max frequency
            int maxFreq = *max_element(freq.begin(), freq.end());
            
            // Shrink window if invalid
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    // Time: O(n) | Space: O(1)
    int characterReplacementOptimized(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        
        for (int right = 0; right < n; right++) {
            // Add character to window
            freq[s[right] - 'A']++;
            
            // Update max frequency
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            // Shrink window if invalid
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    int characterReplacement(string s, int k) {
        return characterReplacementOptimized(s, k);
    }
};
