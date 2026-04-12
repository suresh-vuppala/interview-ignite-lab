// ============================================================
// Linked List Deletion Variations
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* deleteHead(ListNode* head) {
        if (!head) return nullptr;
        return head->next; // New head
    }

    ListNode* deleteTail(ListNode* head) {
        if (!head || !head->next) return nullptr;
        ListNode* curr = head;
        while (curr->next->next) curr = curr->next;
        curr->next = nullptr; // Remove tail
        return head;
    }

    ListNode* deleteValue(ListNode* head, int val) {
        ListNode dummy(0); dummy.next = head;
        ListNode* prev = &dummy;
        while (prev->next) {
            if (prev->next->val == val) {
                prev->next = prev->next->next; // Skip target
                break;
            }
            prev = prev->next;
        }
        return dummy.next;
    }

    ListNode* deleteAt(ListNode* head, int pos) {
        ListNode dummy(0); dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 0; i < pos && prev->next; i++) prev = prev->next;
        if (prev->next) prev->next = prev->next->next;
        return dummy.next;
    }
};
