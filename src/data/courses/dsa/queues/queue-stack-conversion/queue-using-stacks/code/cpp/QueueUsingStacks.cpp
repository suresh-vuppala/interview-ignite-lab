#include <stack>
using namespace std;
// ============================================================
// Solution 1: Two stacks — O(N) dequeue (transfer each time)
// ============================================================
class Solution1 {
    stack<int> in, out;
public:
    void enqueue(int x) { in.push(x); }
    int dequeue() {
        // Transfer ALL elements every dequeue — O(N)
        while(!in.empty()){out.push(in.top());in.pop();}
        int v=out.top();out.pop();
        while(!out.empty()){in.push(out.top());out.pop();}
        return v;
    }
    int front() {
        while(!in.empty()){out.push(in.top());in.pop();}
        int v=out.top();
        while(!out.empty()){in.push(out.top());out.pop();}
        return v;
    }
};

// ============================================================
// Solution 2: Two stacks — amortized O(1) dequeue (lazy transfer)
// ============================================================
class Solution2 {
    stack<int> in, out;
public:
    void enqueue(int x) { in.push(x); }
    int dequeue() {
        if(out.empty()) while(!in.empty()){out.push(in.top());in.pop();} // Transfer only when needed
        int v=out.top();out.pop();return v;
    }
    int front() {
        if(out.empty()) while(!in.empty()){out.push(in.top());in.pop();}
        return out.top();
    }
    bool empty() { return in.empty()&&out.empty(); }
};
