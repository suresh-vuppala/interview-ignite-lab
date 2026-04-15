#include <string>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Stack — track unmatched indices — O(N) Time+Space
// ============================================================
class Solution1 {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c:s){if(c=='('||c=='{')st.push(c);else if(!st.empty()&&((c==')'&&st.top()=='(')||(c=='}'&&st.top()=='{')))st.pop();else st.push(c);}
        return st.size(); // Unmatched count = additions needed
    }
};

// ============================================================
// Solution 2: Two counters — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int minAddToMakeValid(string s) {
        int open=0, close=0;
        for(char c:s){if(c=='(')open++;else{if(open>0)open--;else close++;}}
        return open+close; // open unmatched '(' + close unmatched ')'
    }
};
