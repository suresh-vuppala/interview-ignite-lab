// ============================================================
// Isomorphic Strings
// ============================================================

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// ============================================================
// Solution 1: Two Hash Maps (Bidirectional)
// Time: O(N) | Space: O(1) — bounded by alphabet size
// ============================================================
class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.size(); i++) {
            // Check s→t mapping consistency
            if (mapST.count(s[i]) && mapST[s[i]] != t[i]) return false;

            // Check t→s mapping consistency (prevent two-to-one)
            if (mapTS.count(t[i]) && mapTS[t[i]] != s[i]) return false;

            // Establish bidirectional mapping
            mapST[s[i]] = t[i];
            mapTS[t[i]] = s[i];
        }

        return true; // All positions consistent
    }
};

// ============================================================
// Solution 2: First Occurrence Pattern Encoding
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }

    vector<int> encode(const string& str) {
        unordered_map<char, int> firstOccurrence;
        vector<int> pattern;

        for (int i = 0; i < str.size(); i++) {
            // Record first occurrence index for each character
            if (!firstOccurrence.count(str[i])) {
                firstOccurrence[str[i]] = i;
            }
            pattern.push_back(firstOccurrence[str[i]]);
        }

        return pattern;
    }
};
