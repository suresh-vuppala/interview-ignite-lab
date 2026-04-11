// ============================================================
// Find All Anagrams in a String
// ============================================================

#include <vector>
#include <string>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Rebuild Frequency per Window
// Time: O(N×M) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int m = p.size();
        int pFreq[26] = {};
        for (char c : p) pFreq[c - 'a']++;

        for (int i = 0; i <= (int)s.size() - m; i++) {
            int wFreq[26] = {};
            for (int j = i; j < i + m; j++) wFreq[s[j] - 'a']++;

            bool match = true;
            for (int k = 0; k < 26; k++)
                if (wFreq[k] != pFreq[k]) { match = false; break; }

            if (match) result.push_back(i);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Sliding Window + Frequency Match (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        int pFreq[26] = {}, wFreq[26] = {};
        int m = p.size();

        // Build p's frequency
        for (char c : p) pFreq[c - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            // Add entering character
            wFreq[s[i] - 'a']++;

            // Remove leaving character (once window is full)
            if (i >= m) wFreq[s[i - m] - 'a']--;

            // Check if window matches p's frequency
            if (i >= m - 1) {
                bool match = true;
                for (int k = 0; k < 26; k++)
                    if (wFreq[k] != pFreq[k]) { match = false; break; }
                if (match) result.push_back(i - m + 1);
            }
        }

        return result;
    }
};
