struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Find tail, insert after tail — O(N)
// ============================================================
class Solution1 {
public:
    ListNode* insertEnd(ListNode* head, int val) {
        ListNode*n=new ListNode(val);
        if(!head){n->next=n;return n;}
        ListNode*cur=head;while(cur->next!=head)cur=cur->next;
        cur->next=n;n->next=head;return head;
    }
};

// ============================================================
// Solution 2: Insert after head, swap values — O(1)!
// ============================================================
class Solution2 {
public:
    ListNode* insertAfterHead(ListNode* head, int val) {
        if(!head){ListNode*n=new ListNode(val);n->next=n;return n;}
        ListNode*n=new ListNode(head->val); // Copy head's value
        n->next=head->next;head->next=n;
        head->val=val; // Overwrite head with new value
        return head;  // O(1) — no traversal needed!
    }
};
