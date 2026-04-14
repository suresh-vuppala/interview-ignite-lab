#include <stack>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Store min with each element — O(1) per op, O(N) extra
// ============================================================
class Solution1 {
    stack<pair<int,int>> st; // {val, min_at_this_level}
public:
    void push(int val) { int mn=st.empty()?val:min(val,st.top().second); st.push({val,mn}); }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};

// ============================================================
// Solution 2: Two stacks — main + min tracking — O(1) per op
// ============================================================
class Solution2 {
    stack<int> main_, min_;
public:
    void push(int val) { main_.push(val); if(min_.empty()||val<=min_.top())min_.push(val); }
    void pop() { if(main_.top()==min_.top())min_.pop(); main_.pop(); }
    int top() { return main_.top(); }
    int getMin() { return min_.top(); }
};
