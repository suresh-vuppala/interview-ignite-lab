#include <stack>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Two stacks — main + max — O(1) push/pop/top/getMax
// ============================================================
class Solution1 {
    stack<int> main_, max_;
public:
    void push(int val) { main_.push(val); if(max_.empty()||val>=max_.top())max_.push(val); }
    void pop() { if(main_.top()==max_.top())max_.pop(); main_.pop(); }
    int top() { return main_.top(); }
    int getMax() { return max_.top(); }
};

// ============================================================
// Solution 2: Stack with pair (val, maxSoFar) — O(1) per op
// ============================================================
class Solution2 {
    stack<pair<int,int>> st;
public:
    void push(int val) { int mx=st.empty()?val:max(val,st.top().second); st.push({val,mx}); }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMax() { return st.top().second; }
};
