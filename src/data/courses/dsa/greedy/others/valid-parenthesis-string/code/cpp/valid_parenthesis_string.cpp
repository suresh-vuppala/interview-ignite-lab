#include <string>
using namespace std;
// ============================================================
// Solution 1: Recursion — try each * as (, ), or empty — O(3^N)
// ============================================================
class Solution1 {
    bool check(string& s, int i, int open) {
        if (open < 0) return false;
        if (i == (int)s.size()) return open == 0;
        if (s[i] == '(') return check(s, i+1, open+1);
        if (s[i] == ')') return check(s, i+1, open-1);
        // s[i] == '*': try all three options
        return check(s, i+1, open+1) || check(s, i+1, open-1) || check(s, i+1, open);
    }
public:
    bool checkValidString(string s) { return check(s, 0, 0); }
};

// ============================================================
// Solution 2: Greedy — track min/max open count — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0; // min and max possible open count
        for (char c : s) {
            if (c == '(') { lo++; hi++; }
            else if (c == ')') { lo--; hi--; }
            else { lo--; hi++; } // * can be (, ), or empty
            if (hi < 0) return false; // Too many )
            lo = max(lo, 0); // Can't have negative open
        }
        return lo == 0;
    }
};
