struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Create new list with element — O(N) Space
// ============================================================
class Solution1 {
public:
    ListNode* insertAtHead(ListNode* head, int val) { ListNode* n=new ListNode(val); n->next=head; return n; }
    ListNode* insertAtTail(ListNode* head, int val) {
        ListNode* n=new ListNode(val); if(!head) return n;
        ListNode* cur=head; while(cur->next)cur=cur->next; cur->next=n; return head;
    }
    ListNode* insertAtPos(ListNode* head, int val, int pos) {
        if(pos==0) return insertAtHead(head,val);
        ListNode* cur=head; for(int i=0;i<pos-1&&cur;i++) cur=cur->next;
        if(!cur) return head;
        ListNode* n=new ListNode(val); n->next=cur->next; cur->next=n; return head;
    }
};

// ============================================================
// Solution 2: Dummy head simplifies edge cases — O(1) per insert
// ============================================================
class Solution2 {
public:
    ListNode* insertAtPos(ListNode* head, int val, int pos) {
        ListNode dummy(0); dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 0; i < pos && prev->next; i++) prev = prev->next;
        ListNode* n = new ListNode(val); n->next = prev->next; prev->next = n;
        return dummy.next;  // Dummy head handles pos=0 naturally
    }
};
