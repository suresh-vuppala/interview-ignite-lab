#include <string>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Counter approach (single type only) — O(N) Time, O(1) Space
// ============================================================
class Solution1 {
public:
    // Only works for single type of parentheses '(' and ')'
    bool isValid(string s) {
        int count = 0;
        for(char c:s){if(c=='(')count++;else if(c==')')count--;if(count<0)return false;}
        return count==0; // Doesn't work for mixed {,[,( types!
    }
};

// ============================================================
// Solution 2: Stack — handles all bracket types — O(N) Time+Space
// ============================================================
class Solution2 {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='[') st.push(c);
            else{
                if(st.empty()) return false;
                char top=st.top(); st.pop();
                if(c==')'&&top!='(') return false;
                if(c=='}'&&top!='{') return false;
                if(c==']'&&top!='[') return false;
            }
        }
        return st.empty();
    }
};
