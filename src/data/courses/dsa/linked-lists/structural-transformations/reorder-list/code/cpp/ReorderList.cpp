struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Deque — push all, pop from both ends — O(N) Space
// ============================================================
#include <deque>
class Solution1 {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;for(auto c=head;c;c=c->next)dq.push_back(c);
        ListNode*cur=dq.front();dq.pop_front();bool front=false;
        while(!dq.empty()){if(front){cur->next=dq.front();dq.pop_front();}else{cur->next=dq.back();dq.pop_back();}cur=cur->next;front=!front;}
        cur->next=nullptr;
    }
};

// ============================================================
// Solution 2: Find middle + reverse second half + merge — O(1) Space
// ============================================================
class Solution2 {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)return;
        // Find middle
        ListNode*s=head,*f=head;while(f->next&&f->next->next){s=s->next;f=f->next->next;}
        // Reverse second half
        ListNode*prev=nullptr,*cur=s->next;s->next=nullptr;
        while(cur){auto nxt=cur->next;cur->next=prev;prev=cur;cur=nxt;}
        // Merge alternating
        ListNode*l1=head,*l2=prev;
        while(l2){auto n1=l1->next,n2=l2->next;l1->next=l2;l2->next=n1;l1=n1;l2=n2;}
    }
};
