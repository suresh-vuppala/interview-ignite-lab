class Solution {
public:
    // Optimal: O(n) time, O(1) space — Frequency count with array[26]
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {};
        for (char c : s) freq[c - 'a']++;  // Count chars in s
        for (char c : t) freq[c - 'a']--;  // Subtract chars in t
        for (int f : freq)
            if (f != 0) return false;       // Any mismatch = not anagram
        return true;
    }
};