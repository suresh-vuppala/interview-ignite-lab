// ============================================================
// Remove Outermost Parentheses
// ============================================================

#include <string>
using namespace std;

// ============================================================
// Solution: Depth Counter (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) result += c; // Inner — include
                depth++;
            } else {
                depth--;
                if (depth > 0) result += c; // Inner — include
            }
        }

        return result;
    }
};
