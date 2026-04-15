#include <vector>
using namespace std;
// ============================================================
// Solution 1: Array-based queue — O(1) enqueue, O(N) dequeue (shift)
// ============================================================
class Solution1 {
    vector<int> data;
public:
    void enqueue(int x) { data.push_back(x); }
    int dequeue() { int v = data[0]; data.erase(data.begin()); return v; } // O(N) shift!
    int front() { return data[0]; }
    bool empty() { return data.empty(); }
};

// ============================================================
// Solution 2: Linked List queue — O(1) enqueue + dequeue
// ============================================================
struct Node { int val; Node* next; Node(int v):val(v),next(nullptr){} };
class Solution2 {
    Node *head = nullptr, *tail = nullptr;
    int sz = 0;
public:
    void enqueue(int x) { Node* n=new Node(x); if(tail)tail->next=n; else head=n; tail=n; sz++; }
    int dequeue() { int v=head->val; Node*t=head; head=head->next; if(!head)tail=nullptr; delete t; sz--; return v; }
    int front() { return head->val; }
    bool empty() { return !head; }
    int size() { return sz; }
};
