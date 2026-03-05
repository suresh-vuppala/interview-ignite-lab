#include <stack>
#include <string>
using namespace std;

class InfixToPostfix {
public:
    string infixToPostfix(string infix) {
        string result = "";
        stack<char> st;
        
        for (char c : infix) {
            if (isalnum(c)) {
                result += c; // Operand
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop(); // Remove '('
            } else { // Operator
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
    
private:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
};
