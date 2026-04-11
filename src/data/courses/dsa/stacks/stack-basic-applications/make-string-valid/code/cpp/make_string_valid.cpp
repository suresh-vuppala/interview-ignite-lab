// ============================================================
// Minimum Add to Make Parentheses Valid
// ============================================================

#include <string>
using namespace std;

// ============================================================
// Solution: Counter (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;

        for (char c : s) {
            if (c == '(') {
                open++; // Pending open
            } else {
                if (open > 0) open--; // Matched
                else close++;          // Unmatched close
            }
        }

        return open + close; // Need this many additions
    }
};
