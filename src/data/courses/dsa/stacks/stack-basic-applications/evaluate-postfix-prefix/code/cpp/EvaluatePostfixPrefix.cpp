#include <stack>
#include <string>
#include <vector>
using namespace std;

class EvaluatePostfixPrefix {
public:
    int evalPostfix(vector<string>& tokens) {
        stack<int> st;
        
        for (string& token : tokens) {
            if (isOperator(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(applyOp(a, b, token));
            } else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
    
    int evalPrefix(vector<string>& tokens) {
        stack<int> st;
        
        // Process from right to left
        for (int i = tokens.size() - 1; i >= 0; i--) {
            string token = tokens[i];
            if (isOperator(token)) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(applyOp(a, b, token));
            } else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
    
private:
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    
    int applyOp(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        return 0;
    }
};
