#include <stack>
using namespace std;
// ============================================================
// Solution 1: Transfer to auxiliary stack in sorted order — O(N²)
// ============================================================
class Solution1 {
public:
    void sortStack(stack<int>& input) {
        stack<int> sorted;
        while(!input.empty()){
            int tmp=input.top(); input.pop();
            while(!sorted.empty()&&sorted.top()>tmp){input.push(sorted.top());sorted.pop();}
            sorted.push(tmp);
        }
        input=sorted;
    }
};

// ============================================================
// Solution 2: Recursive — remove top, sort rest, insert in order — O(N²)
// ============================================================
class Solution2 {
    void insertSorted(stack<int>& st, int val) {
        if(st.empty()||val>=st.top()){st.push(val);return;}
        int top=st.top();st.pop();insertSorted(st,val);st.push(top);
    }
public:
    void sortStack(stack<int>& st) {
        if(st.empty())return;
        int top=st.top();st.pop();sortStack(st);insertSorted(st,top);
    }
};
