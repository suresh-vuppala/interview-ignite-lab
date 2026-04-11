// ============================================================
// Evaluate Reverse Polish Notation (Postfix)
// ============================================================

#include <vector>
#include <string>
#include <stack>
using namespace std;

// ============================================================
// Solution: Stack (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;

        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long b = st.top(); st.pop(); // First pop = right operand
                long a = st.top(); st.pop(); // Second pop = left operand

                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b); // Truncates toward zero in C++
            } else {
                st.push(stol(t)); // Push number
            }
        }

        return (int)st.top();
    }
};
