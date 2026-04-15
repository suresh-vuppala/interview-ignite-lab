#include <string>
using namespace std;
// ============================================================
// Solution 1: Brute Force — generate all long-pressed variants — O(2^N)
// ============================================================
class Solution1 {
public:
    bool isLongPressedName(string name, string typed) {
        // Simple approach: compare char-by-char with two pointers
        int i = 0, j = 0;
        while (j < (int)typed.size()) {
            if (i < (int)name.size() && name[i] == typed[j]) { i++; j++; }
            else if (j > 0 && typed[j] == typed[j-1]) { j++; } // Long press repeat
            else return false;
        }
        return i == (int)name.size();
    }
};

// ============================================================
// Solution 2: Two Pointers with group counting — O(N+M) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, n = name.size(), m = typed.size();
        while (i < n && j < m) {
            if (name[i] != typed[j]) return false;
            // Count consecutive same chars in both
            int countN = 0, countT = 0;
            char c = name[i];
            while (i < n && name[i] == c) { i++; countN++; }
            while (j < m && typed[j] == c) { j++; countT++; }
            if (countT < countN) return false; // Typed fewer than needed
        }
        return i == n && j == m;
    }
};
