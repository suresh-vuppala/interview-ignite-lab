// ============================================================
// Find Nth Node From End
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    ListNode* findNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) fast = fast->next; // n-step gap
        while (fast) { slow = slow->next; fast = fast->next; }
        return slow; // Nth from end
    }
};
