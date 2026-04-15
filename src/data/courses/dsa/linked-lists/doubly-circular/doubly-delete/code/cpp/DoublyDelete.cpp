struct DNode { int val; DNode *prev, *next; DNode(int v):val(v),prev(nullptr),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Find node, rewire prev/next — O(N) search
// ============================================================
class Solution1 {
public:
    DNode* deleteNode(DNode* head, int val) {
        DNode*cur=head;while(cur&&cur->val!=val)cur=cur->next;
        if(!cur)return head;
        if(cur->prev)cur->prev->next=cur->next;else head=cur->next;
        if(cur->next)cur->next->prev=cur->prev;
        delete cur;return head;
    }
};

// ============================================================
// Solution 2: Delete given node pointer directly — O(1)
// ============================================================
class Solution2 {
public:
    DNode* deleteGivenNode(DNode* head, DNode* target) {
        if(!target)return head;
        if(target->prev)target->prev->next=target->next;else head=target->next;
        if(target->next)target->next->prev=target->prev;
        delete target;return head; // O(1) when node pointer is given!
    }
};
