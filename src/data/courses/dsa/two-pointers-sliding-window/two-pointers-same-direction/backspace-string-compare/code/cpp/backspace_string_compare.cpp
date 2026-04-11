// ============================================================
// Backspace String Compare
// ============================================================

#include <string>
using namespace std;

// ============================================================
// Solution 1: Stack — Build Processed Strings
// Time: O(N+M) | Space: O(N+M)
// ============================================================
class Solution1 {
public:
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }

    string process(const string& str) {
        string result;
        for (char c : str) {
            if (c == '#') {
                if (!result.empty()) result.pop_back(); // Backspace
            } else {
                result += c; // Type character
            }
        }
        return result;
    }
};

// ============================================================
// Solution 2: Two Pointers from End (Optimal)
// Time: O(N+M) | Space: O(1)
// ============================================================
class Solution2 {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;

        while (i >= 0 || j >= 0) {
            i = getNextValid(s, i);
            j = getNextValid(t, j);

            // Compare current valid characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;

            // One string exhausted, other hasn't
            if ((i >= 0) != (j >= 0)) return false;

            i--;
            j--;
        }

        return true;
    }

    // Find next valid (non-skipped) character index
    int getNextValid(const string& str, int idx) {
        int skip = 0;
        while (idx >= 0) {
            if (str[idx] == '#') { skip++; idx--; }
            else if (skip > 0) { skip--; idx--; } // Skip this character
            else break; // Valid character found
        }
        return idx;
    }
};
