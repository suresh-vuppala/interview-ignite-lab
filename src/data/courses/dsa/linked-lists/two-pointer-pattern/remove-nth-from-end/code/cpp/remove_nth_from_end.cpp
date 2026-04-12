// ============================================================
// Remove Nth Node From End
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Advance fast by n+1 steps
        for (int i = 0; i <= n; i++) fast = fast->next;

        // Advance both until fast reaches end
        while (fast) { slow = slow->next; fast = fast->next; }

        // Skip the target node
        slow->next = slow->next->next;

        return dummy.next;
    }
};
