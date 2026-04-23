// ============================================================
// Evaluate Nested Expression
// ============================================================

#include <string>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;

// ============================================================
// Solution: Stack-Based Evaluation
// Time: O(N) | Space: O(N)
// ============================================================
class Solution {
public:
    int evaluate(string s) {
        // Stack of (operator, operands)
        stack<pair<string, vector<int>>> st;

        for (int i = 0; i < s.size(); i++) {
            
            // Parse operator (letters)
            if (isalpha(s[i])) {
                string op;
                while (i < s.size() && isalpha(s[i])) {
                    op += s[i++];
                }

                // Validate operator
                if (op != "add" && op != "sub" && op != "mult") {
                    return -1;  // Invalid operator
                }

                st.push({op, {}});
                i--;  // Adjust for loop increment
            }

            // Parse number (digits)
            else if (isdigit(s[i])) {
                // Number without operator frame → invalid
                if (st.empty()) return -1;

                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }

                // Add operand to current frame
                st.top().second.push_back(num);
                i--;  // Adjust for loop increment
            }

            // Closing bracket → compute result
            else if (s[i] == ')') {
                // No frame to close → invalid
                if (st.empty()) return -1;

                auto [op, nums] = st.top();
                st.pop();

                // Validate: exactly 2 operands
                if (nums.size() != 2) return -1;

                // Compute result based on operator
                int result;
                if (op == "add") {
                    result = nums[0] + nums[1];
                } else if (op == "sub") {
                    result = nums[0] - nums[1];
                } else {  // mult
                    result = nums[0] * nums[1];
                }

                // Pass result to parent or return if outermost
                if (!st.empty()) {
                    st.top().second.push_back(result);
                } else {
                    // Check if we've consumed entire string
                    if (i == s.size() - 1) {
                        return result;
                    } else {
                        return -1;  // Extra characters after result
                    }
                }
            }

            // Ignore commas, spaces, opening parentheses
            else if (s[i] == ',' || s[i] == ' ' || s[i] == '(') {
                continue;
            }

            // Invalid character
            else {
                return -1;
            }
        }

        // If stack not empty → unfinished expression
        return -1;
    }
};
