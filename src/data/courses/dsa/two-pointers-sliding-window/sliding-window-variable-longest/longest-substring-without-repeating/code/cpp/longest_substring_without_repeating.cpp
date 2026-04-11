// ============================================================
// Longest Substring Without Repeating Characters
// ============================================================

#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// ============================================================
// Solution 1: Brute Force — All Substrings
// Time: O(N³) | Space: O(N)
// ============================================================
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> seen;
            for (int j = i; j < s.size(); j++) {
                if (seen.count(s[j])) break;
                seen.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Sliding Window + Hash Set
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            // Shrink from left until duplicate removed
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// ============================================================
// Solution 3: Last Index Map — Jump Left (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen; // char → last index
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            // If duplicate found INSIDE current window → jump left
            if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left) {
                left = lastSeen[s[right]] + 1;
            }

            lastSeen[s[right]] = right; // Update last seen position
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
