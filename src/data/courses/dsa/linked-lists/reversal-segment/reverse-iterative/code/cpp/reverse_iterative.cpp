// ============================================================
// Reverse Linked List — Iterative
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next; // Save next
            curr->next = prev;           // Reverse pointer
            prev = curr;                 // Advance prev
            curr = next;                 // Advance curr
        }

        return prev; // New head
    }
};
