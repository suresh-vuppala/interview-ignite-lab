#include <vector>
using namespace std;
// ============================================================
// Solution 1: Linked List stack — O(1) per op, pointer overhead
// ============================================================
struct Node { int val; Node* next; Node(int v,Node*n=nullptr):val(v),next(n){} };
class Solution1 {
    Node* top_ = nullptr; int sz = 0;
public:
    void push(int x) { top_ = new Node(x, top_); sz++; }
    int pop() { int v=top_->val; Node*t=top_; top_=top_->next; delete t; sz--; return v; }
    int top() { return top_->val; }
    bool empty() { return !top_; }
    int size() { return sz; }
};

// ============================================================
// Solution 2: Dynamic array (vector) stack — O(1) amortized, cache-friendly
// ============================================================
class Solution2 {
    vector<int> data;
public:
    void push(int x) { data.push_back(x); }
    int pop() { int v=data.back(); data.pop_back(); return v; }
    int top() { return data.back(); }
    bool empty() { return data.empty(); }
    int size() { return data.size(); }
};
