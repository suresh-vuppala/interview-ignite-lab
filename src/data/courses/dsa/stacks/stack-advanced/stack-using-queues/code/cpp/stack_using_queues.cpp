#include <queue>
using namespace std;
// ============================================================
// Solution 1: Two queues — expensive push — O(N) push, O(1) pop
// ============================================================
class Solution1 {
    queue<int> q1, q2;
public:
    void push(int x) { q2.push(x); while(!q1.empty()){q2.push(q1.front());q1.pop();} swap(q1,q2); }
    int pop() { int v=q1.front();q1.pop();return v; }
    int top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

// ============================================================
// Solution 2: Single queue — rotate after push — O(N) push, O(1) pop
// ============================================================
class Solution2 {
    queue<int> q;
public:
    void push(int x) { q.push(x); for(int i=0;i<(int)q.size()-1;i++){q.push(q.front());q.pop();} }
    int pop() { int v=q.front();q.pop();return v; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
