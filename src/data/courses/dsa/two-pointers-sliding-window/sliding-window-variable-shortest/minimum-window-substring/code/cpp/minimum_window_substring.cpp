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
        int minLen = INT_MAX, minStart = 0;
        unordered_map<char, int> tFreq;
        for (char c : t) tFreq[c]++;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> wFreq;
            for (int j = i; j < s.size(); j++) {
                wFreq[s[j]]++;
                bool valid = true;
                for (auto& [c, cnt] : tFreq)
                    if (wFreq[c] < cnt) { valid = false; break; }
                if (valid && j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    minStart = i;
                    break;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

// ============================================================
// Solution 2: Sliding Window + Frequency Tracking (Optimal)
// Time: O(N+M) | Space: O(N+M)
// ============================================================
class Solution2 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq, wFreq;
        for (char c : t) tFreq[c]++;

        int required = tFreq.size(); // Unique chars needed
        int formed = 0;              // Unique chars fully met
        int left = 0, minLen = INT_MAX, minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            // Expand: add right character
            wFreq[s[right]]++;
            if (tFreq.count(s[right]) && wFreq[s[right]] == tFreq[s[right]])
                formed++;

            // Shrink: minimize window while still valid
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // Remove left character
                wFreq[s[left]]--;
                if (tFreq.count(s[left]) && wFreq[s[left]] < tFreq[s[left]])
                    formed--;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
