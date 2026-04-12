// ============================================================
// Search and Update in Linked List
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    bool search(ListNode* head, int target) {
        while (head) {
            if (head->val == target) return true;
            head = head->next;
        }
        return false;
    }

    ListNode* update(ListNode* head, int oldVal, int newVal) {
        ListNode* curr = head;
        while (curr) {
            if (curr->val == oldVal) { curr->val = newVal; break; }
            curr = curr->next;
        }
        return head;
    }
};
