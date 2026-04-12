// ============================================================
// Reverse Nodes in k-Group
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            // Check if k nodes exist
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (!kth) return dummy.next; // Less than k remaining
            }

            ListNode* groupNext = kth->next; // Save start of next group
            ListNode* prev = groupNext;       // Will be the tail connection
            ListNode* curr = groupPrev->next; // Start of current group

            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Reconnect
            ListNode* oldHead = groupPrev->next; // Old head = new tail
            groupPrev->next = prev;               // Connect to reversed head
            groupPrev = oldHead;                  // Move groupPrev to new tail
        }
    }
};
