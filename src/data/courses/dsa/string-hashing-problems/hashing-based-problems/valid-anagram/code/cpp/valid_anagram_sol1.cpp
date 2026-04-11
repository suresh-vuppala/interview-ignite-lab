class Solution {
public:
    // Sort: O(n log n) — Sorted anagrams produce identical strings
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());   // Sort both strings
        sort(t.begin(), t.end());
        return s == t;              // Compare sorted versions
    }
};