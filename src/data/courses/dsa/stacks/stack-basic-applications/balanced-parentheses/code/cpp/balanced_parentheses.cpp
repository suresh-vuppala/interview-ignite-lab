// ============================================================
// Valid Parentheses (Balanced Brackets)
// ============================================================

#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Repeatedly Remove Pairs
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution1 {
public:
    bool isValid(string s) {
        string prev;
        while (s != prev) {
            prev = s;
            size_t pos;
            while ((pos = s.find("()")) != string::npos) s.erase(pos, 2);
            while ((pos = s.find("[]")) != string::npos) s.erase(pos, 2);
            while ((pos = s.find("{}")) != string::npos) s.erase(pos, 2);
        }
        return s.empty();
    }
};

// ============================================================
// Solution 2: Stack — Single Pass (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> match = {
            {')', '('}, {']', '['}, {'}', '{'}
        };

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c); // Opening bracket → push
            } else {
                // Closing bracket → check match
                if (st.empty() || st.top() != match[c]) {
                    return false; // No opener or wrong type
                }
                st.pop(); // Matched pair — remove opener
            }
        }

        return st.empty(); // Any unmatched openers?
    }
};
