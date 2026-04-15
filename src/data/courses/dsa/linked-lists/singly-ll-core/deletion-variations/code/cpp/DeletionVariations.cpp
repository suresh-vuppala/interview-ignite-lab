struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Direct pointer manipulation — O(N)
// ============================================================
class Solution1 {
public:
    ListNode* deleteHead(ListNode* head) { if(!head)return nullptr; ListNode*t=head;head=head->next;delete t;return head; }
    ListNode* deleteTail(ListNode* head) {
        if(!head||!head->next){delete head;return nullptr;}
        ListNode*cur=head;while(cur->next->next)cur=cur->next;delete cur->next;cur->next=nullptr;return head;
    }
    ListNode* deleteAtPos(ListNode* head, int pos) {
        if(pos==0)return deleteHead(head);
        ListNode*cur=head;for(int i=0;i<pos-1&&cur->next;i++)cur=cur->next;
        if(!cur->next)return head;
        ListNode*t=cur->next;cur->next=t->next;delete t;return head;
    }
};

// ============================================================
// Solution 2: Dummy head — uniform handling — O(N)
// ============================================================
class Solution2 {
public:
    ListNode* deleteAtPos(ListNode* head, int pos) {
        ListNode dummy(0); dummy.next=head;
        ListNode* prev=&dummy;
        for(int i=0;i<pos&&prev->next;i++) prev=prev->next;
        if(!prev->next) return dummy.next;
        ListNode* t=prev->next; prev->next=t->next; delete t;
        return dummy.next;
    }
};
