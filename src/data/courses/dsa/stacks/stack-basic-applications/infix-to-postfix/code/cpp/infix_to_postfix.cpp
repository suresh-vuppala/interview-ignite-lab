// ============================================================
// Infix to Postfix (Shunting-Yard)
// ============================================================

#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

// ============================================================
// Solution: Shunting-Yard Algorithm
// Time: O(N) | Space: O(N)
// ============================================================
class Solution {
public:
    string infixToPostfix(string s) {
        unordered_map<char, int> prec = {{'+',1},{'-',1},{'*',2},{'/',2}};
        stack<char> ops;
        string result;

        for (char c : s) {
            if (isalnum(c)) {
                result += c; // Operand → output directly
            } else if (c == '(') {
                ops.push(c); // Push unconditionally
            } else if (c == ')') {
                // Pop until '(' found
                while (!ops.empty() && ops.top() != '(') {
                    result += ops.top(); ops.pop();
                }
                ops.pop(); // Discard '('
            } else {
                // Operator: pop higher/equal precedence first
                while (!ops.empty() && ops.top() != '(' &&
                       prec[ops.top()] >= prec[c]) {
                    result += ops.top(); ops.pop();
                }
                ops.push(c);
            }
        }

        // Pop remaining operators
        while (!ops.empty()) { result += ops.top(); ops.pop(); }

        return result;
    }
};
