// ============================================================
// Implement Stack Using Queues
// ============================================================

#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        // Rotate: move all old elements behind the new one
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() { int top = q.front(); q.pop(); return top; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
