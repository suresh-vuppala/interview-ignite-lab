#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Time: O(N³), Space: O(1)
class LongestRepeatingCharacterReplacement {
public:
    int characterReplacementBruteForce(string s, int k) {
        int n = s.length(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> freq(26, 0);
                int maxFreq = 0;
                for (int p = i; p <= j; p++) {
                    freq[s[p] - 'A']++;
                    maxFreq = max(maxFreq, freq[s[p] - 'A']);
                }
                if ((j - i + 1) - maxFreq <= k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N² × 26), Space: O(26)
    int characterReplacementBruteOptimized(string s, int k) {
        int n = s.length(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                if ((j - i + 1) - maxFreq <= k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N × 26), Space: O(26)
    int characterReplacementSlidingWindowRecalc(string s, int k) {
        int left = 0, maxLen = 0;
        vector<int> freq(26, 0);
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            int maxFreq = *max_element(freq.begin(), freq.end());
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                maxFreq = *max_element(freq.begin(), freq.end());
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(26)
    int characterReplacementSlidingWindow(string s, int k) {
        int left = 0, maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(26)
    int characterReplacementSlidingWindowOptimized(string s, int k) {
        int left = 0, maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        for (int right = 0; right < s.length(); right++) {
            maxFreq = max(maxFreq, ++freq[s[right] - 'A']);
            if ((right - left + 1) - maxFreq > k) freq[s[left++] - 'A']--;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
