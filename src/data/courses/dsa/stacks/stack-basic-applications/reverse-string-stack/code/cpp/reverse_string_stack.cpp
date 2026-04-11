// ============================================================
// Reverse String Using Stack
// ============================================================

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Two-Pointer Swap (No Stack)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
public:
    string reverseString(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

// ============================================================
// Solution 2: Stack — Push All, Pop All
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    string reverseString(string s) {
        stack<char> st;

        // Push all characters
        for (char c : s) st.push(c);

        // Pop all — LIFO gives reverse
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
