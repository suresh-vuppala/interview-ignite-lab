// ============================================================
// Valid Anagram
// ============================================================

#include <string>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Sort Both Strings
// Time: O(N log N) | Space: O(N)
// ============================================================
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        // Sort both strings — anagrams produce identical sorted strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t; // Compare sorted versions
    }
};

// ============================================================
// Solution 2: Frequency Count Array (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int freq[26] = {}; // Fixed array for 26 lowercase letters

        // Count characters in s (increment)
        for (char c : s) freq[c - 'a']++;

        // Subtract characters in t (decrement)
        for (char c : t) freq[c - 'a']--;

        // If all counts are zero → anagram
        for (int f : freq) {
            if (f != 0) return false;
        }

        return true;
    }
};
