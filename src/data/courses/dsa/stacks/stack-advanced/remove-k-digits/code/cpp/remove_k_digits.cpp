// ============================================================
// Remove K Digits
// ============================================================

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack; // Use string as stack for easy result building

        for (char d : num) {
            // Pop larger digits — greedy removal
            while (k > 0 && !stack.empty() && stack.back() > d) {
                stack.pop_back();
                k--;
            }
            stack += d;
        }

        // If k still > 0, remove from the end
        while (k > 0) { stack.pop_back(); k--; }

        // Strip leading zeros
        int start = 0;
        while (start < stack.size() && stack[start] == '0') start++;

        string result = stack.substr(start);
        return result.empty() ? "0" : result;
    }
};
