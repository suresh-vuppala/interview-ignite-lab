#include <vector>
using namespace std;
// ============================================================
// Solution 1: Array with count variable — O(1) all ops
// ============================================================
class Solution1 {
    vector<int> data; int front_, count, cap;
public:
    Solution1(int k):data(k),front_(0),count(0),cap(k){}
    bool enQueue(int val){if(count==cap)return false;data[(front_+count)%cap]=val;count++;return true;}
    bool deQueue(){if(count==0)return false;front_=(front_+1)%cap;count--;return true;}
    int Front(){return count==0?-1:data[front_];}
    int Rear(){return count==0?-1:data[(front_+count-1)%cap];}
    bool isEmpty(){return count==0;}
    bool isFull(){return count==cap;}
};

// ============================================================
// Solution 2: Linked list circular — O(1) all ops, dynamic size
// ============================================================
struct QNode{int val;QNode*next;QNode(int v):val(v),next(nullptr){}};
class Solution2 {
    QNode*head=nullptr,*tail=nullptr;int sz=0,cap;
public:
    Solution2(int k):cap(k){}
    bool enQueue(int val){if(sz==cap)return false;QNode*n=new QNode(val);if(!head)head=tail=n;else{tail->next=n;tail=n;}tail->next=head;sz++;return true;}
    bool deQueue(){if(sz==0)return false;if(sz==1){delete head;head=tail=nullptr;}else{QNode*t=head;head=head->next;tail->next=head;delete t;}sz--;return true;}
    int Front(){return sz==0?-1:head->val;}
    int Rear(){return sz==0?-1:tail->val;}
    bool isEmpty(){return sz==0;}
    bool isFull(){return sz==cap;}
};
