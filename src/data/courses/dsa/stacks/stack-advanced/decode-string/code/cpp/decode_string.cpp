#include <string>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Recursive parsing — O(N * maxNesting)
// ============================================================
class Solution1 {
    int i=0;
    string decode(string& s) {
        string res;
        while(i<(int)s.size()&&s[i]!=']'){
            if(isdigit(s[i])){
                int num=0;while(isdigit(s[i]))num=num*10+(s[i++]-'0');
                i++; // skip '['
                string inner=decode(s);
                i++; // skip ']'
                while(num--)res+=inner;
            } else res+=s[i++];
        }
        return res;
    }
public:
    string decodeString(string s) { i=0;return decode(s); }
};

// ============================================================
// Solution 2: Stack — push count+string on '[', pop and repeat on ']' — O(N)
// ============================================================
class Solution2 {
public:
    string decodeString(string s) {
        stack<pair<string,int>> st; string cur; int num=0;
        for(char c:s){
            if(isdigit(c)) num=num*10+(c-'0');
            else if(c=='['){st.push({cur,num});cur="";num=0;}
            else if(c==']'){auto [prev,k]=st.top();st.pop();string rep;while(k--)rep+=cur;cur=prev+rep;}
            else cur+=c;
        }
        return cur;
    }
};
