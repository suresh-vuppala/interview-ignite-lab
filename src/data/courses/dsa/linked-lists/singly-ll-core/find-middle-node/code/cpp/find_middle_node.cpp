// ============================================================
// Find Middle Node
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution1 {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0; ListNode* c = head;
        while (c) { n++; c = c->next; }
        c = head; for (int i = 0; i < n/2; i++) c = c->next;
        return c;
    }
};

class Solution2 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 steps
        }
        return slow; // Middle node
    }
};
