// ============================================================
// Longest Repeating Character Replacement
// ============================================================

#include <string>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²×26) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int freq[26] = {};
            int maxF = 0;
            for (int j = i; j < s.size(); j++) {
                freq[s[j]-'A']++;
                maxF = max(maxF, freq[s[j]-'A']);
                if ((j-i+1) - maxF <= k)
                    maxLen = max(maxLen, j - i + 1);
                else break;
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Sliding Window + Max Frequency (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If replacements needed > k → shrink
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
