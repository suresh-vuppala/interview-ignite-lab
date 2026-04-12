// ============================================================
// Palindrome Linked List
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next; fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow->next);

        // Step 3: Compare halves
        ListNode* p1 = head, *p2 = secondHalf;
        while (p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next; p2 = p2->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head;
        while (curr) { ListNode* n = curr->next; curr->next = prev; prev = curr; curr = n; }
        return prev;
    }
};
