// ============================================================
// Linked List Cycle Detection
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution1 {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        while (head) { if (seen.count(head)) return true; seen.insert(head); head = head->next; }
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true; // Met → cycle!
        }
        return false; // Fast reached end → no cycle
    }
};
