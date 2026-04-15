#include <string>
using namespace std;
// ============================================================
// Solution 1: Stack to track depth, skip depth-0 parens — O(N)
// ============================================================
#include <stack>
class Solution1 {
public:
    string removeOuterParentheses(string s) {
        string res; stack<char> st;
        for(char c:s){
            if(c=='('){if(!st.empty())res+=c;st.push(c);}
            else{st.pop();if(!st.empty())res+=c;}
        }
        return res;
    }
};

// ============================================================
// Solution 2: Counter — no stack needed — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    string removeOuterParentheses(string s) {
        string res; int depth=0;
        for(char c:s){
            if(c=='('){if(depth>0)res+=c;depth++;}
            else{depth--;if(depth>0)res+=c;}
        }
        return res;
    }
};
