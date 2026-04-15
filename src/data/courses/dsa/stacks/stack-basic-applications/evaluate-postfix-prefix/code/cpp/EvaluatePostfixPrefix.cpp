#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Convert to inorder tree, evaluate — complex
// ============================================================
class Solution1 {
public:
    // Build expression tree from postfix, then evaluate recursively
    // More complex than direct stack evaluation — see Solution 2
    int evalRPN(vector<string>& tokens) {
        // Simplified: just use stack (same as Solution2 for postfix)
        stack<int> st;
        for(auto& t:tokens){
            if(t=="+"||t=="-"||t=="*"||t=="/"){
                int b=st.top();st.pop();int a=st.top();st.pop();
                if(t=="+")st.push(a+b);else if(t=="-")st.push(a-b);
                else if(t=="*")st.push(a*b);else st.push(a/b);
            } else st.push(stoi(t));
        }
        return st.top();
    }
};

// ============================================================
// Solution 2: Stack — process tokens left to right — O(N)
// ============================================================
class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(auto& t:tokens){
            if(t.size()>1 || isdigit(t[0])) st.push(stol(t));
            else{long b=st.top();st.pop();long a=st.top();st.pop();
                if(t=="+")st.push(a+b);else if(t=="-")st.push(a-b);
                else if(t=="*")st.push(a*b);else st.push(a/b);}
        }
        return st.top();
    }
};
