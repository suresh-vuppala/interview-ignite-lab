#include <string>
#include <stack>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Two-pointer swap — O(N) Time, O(1) Space
// ============================================================
class Solution1 {
public:
    string reverseString(string s) {
        int l=0, r=s.size()-1;
        while(l<r) swap(s[l++],s[r--]);
        return s;
    }
};

// ============================================================
// Solution 2: Stack — push all, pop all — O(N) Time+Space
// ============================================================
class Solution2 {
public:
    string reverseString(string s) {
        stack<char> st;
        for(char c:s) st.push(c);
        string res;
        while(!st.empty()){res+=st.top();st.pop();}
        return res;
    }
};
