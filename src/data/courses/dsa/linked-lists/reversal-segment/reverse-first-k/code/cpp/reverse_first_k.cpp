// ============================================================
// Reverse First K Nodes
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* reverseFirstK(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* origHead = head; // Will become tail of reversed part

        for (int i = 0; i < k && curr; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        origHead->next = curr; // Connect to remaining list
        return prev; // New head
    }
};
