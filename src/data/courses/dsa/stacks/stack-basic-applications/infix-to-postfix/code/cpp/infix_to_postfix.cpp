#include <string>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Parenthesize everything, extract — complex, O(N)
// ============================================================
class Solution1 {
    int prec(char c){if(c=='+'||c=='-')return 1;if(c=='*'||c=='/')return 2;if(c=='^')return 3;return 0;}
public:
    string infixToPostfix(string s) {
        string res; stack<char> st;
        for(char c:s){
            if(isalnum(c)) res+=c;
            else if(c=='(') st.push(c);
            else if(c==')'){while(st.top()!='('){res+=st.top();st.pop();}st.pop();}
            else{while(!st.empty()&&prec(st.top())>=prec(c)){res+=st.top();st.pop();}st.push(c);}
        }
        while(!st.empty()){res+=st.top();st.pop();}
        return res;
    }
};

// ============================================================
// Solution 2: Shunting-Yard with right-associativity — O(N)
// ============================================================
class Solution2 {
    int prec(char c){if(c=='+'||c=='-')return 1;if(c=='*'||c=='/')return 2;if(c=='^')return 3;return 0;}
    bool isRightAssoc(char c){return c=='^';}
public:
    string infixToPostfix(string s) {
        string res; stack<char> st;
        for(char c:s){
            if(isalnum(c)) res+=c;
            else if(c=='(') st.push(c);
            else if(c==')'){while(st.top()!='('){res+=st.top();st.pop();}st.pop();}
            else{
                while(!st.empty()&&st.top()!='('&&
                    (prec(st.top())>prec(c)||(prec(st.top())==prec(c)&&!isRightAssoc(c))))
                    {res+=st.top();st.pop();}
                st.push(c);
            }
        }
        while(!st.empty()){res+=st.top();st.pop();}
        return res;
    }
};
