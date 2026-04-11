// ============================================================
// Decode String
// ============================================================

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st; // (previous string, repeat count)
        string currentStr;
        int currentNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0'); // Multi-digit number
            } else if (c == '[') {
                // Save current state and reset
                st.push({currentStr, currentNum});
                currentStr = "";
                currentNum = 0;
            } else if (c == ']') {
                // Pop and build: prevStr + currentStr × count
                auto [prevStr, count] = st.top();
                st.pop();
                string repeated;
                for (int i = 0; i < count; i++) repeated += currentStr;
                currentStr = prevStr + repeated;
            } else {
                currentStr += c; // Regular character
            }
        }

        return currentStr;
    }
};
