class Solution {
public:
    // O(n) time, O(1) space — frequency count with array[26]
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {};
        for (char c : s) freq[c - 'a']++;  // Increment for s
        for (char c : t) freq[c - 'a']--;  // Decrement for t
        for (int f : freq) {
            if (f != 0) return false; // Mismatch in frequency
        }
        return true;
    }
};