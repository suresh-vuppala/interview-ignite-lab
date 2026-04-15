#include <vector>
using namespace std;
// ============================================================
// Solution 1: Doubly Linked List — O(1) all ops
// ============================================================
struct DNode{int val;DNode*prev,*next;DNode(int v):val(v),prev(nullptr),next(nullptr){}};
class Solution1 {
    DNode*head=nullptr,*tail=nullptr;int sz=0;
public:
    void pushFront(int val){DNode*n=new DNode(val);n->next=head;if(head)head->prev=n;head=n;if(!tail)tail=n;sz++;}
    void pushBack(int val){DNode*n=new DNode(val);n->prev=tail;if(tail)tail->next=n;tail=n;if(!head)head=n;sz++;}
    int popFront(){int v=head->val;DNode*t=head;head=head->next;if(head)head->prev=nullptr;else tail=nullptr;delete t;sz--;return v;}
    int popBack(){int v=tail->val;DNode*t=tail;tail=tail->prev;if(tail)tail->next=nullptr;else head=nullptr;delete t;sz--;return v;}
    int front(){return head->val;} int back(){return tail->val;}
    bool empty(){return sz==0;} int size(){return sz;}
};

// ============================================================
// Solution 2: Circular array deque — O(1) amortized
// ============================================================
class Solution2 {
    vector<int> data;int front_,back_,sz,cap;
public:
    Solution2(int k=1000):data(k),front_(k/2),back_(k/2-1),sz(0),cap(k){}
    void pushFront(int val){front_=(front_-1+cap)%cap;data[front_]=val;sz++;}
    void pushBack(int val){back_=(back_+1)%cap;data[back_]=val;sz++;}
    int popFront(){int v=data[front_];front_=(front_+1)%cap;sz--;return v;}
    int popBack(){int v=data[back_];back_=(back_-1+cap)%cap;sz--;return v;}
    int front(){return data[front_];} int back(){return data[back_];}
    bool empty(){return sz==0;} int size(){return sz;}
};
