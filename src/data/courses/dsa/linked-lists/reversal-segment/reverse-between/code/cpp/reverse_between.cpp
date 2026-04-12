// ============================================================
// Reverse Linked List Between Positions
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        // Step 1: Find the node before the reverse segment
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) prev = prev->next;

        // Step 2: Reverse (right - left + 1) nodes
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;     // Skip nextNode
            nextNode->next = prev->next;     // Move nextNode to front of segment
            prev->next = nextNode;           // Update segment head
        }

        return dummy.next;
    }
};
