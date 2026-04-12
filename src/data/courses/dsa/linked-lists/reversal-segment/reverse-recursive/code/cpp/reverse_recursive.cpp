// ============================================================
// Reverse Linked List — Recursive
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: empty or single node
        if (!head || !head->next) return head;

        // Recurse to the end — newHead = last node
        ListNode* newHead = reverseList(head->next);

        // Reverse: make successor point back to me
        head->next->next = head;
        head->next = nullptr; // Break old forward link

        return newHead; // Propagate last node as new head
    }
};
