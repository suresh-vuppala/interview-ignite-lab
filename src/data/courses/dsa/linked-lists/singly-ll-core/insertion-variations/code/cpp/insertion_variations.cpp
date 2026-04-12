// ============================================================
// Linked List Insertion Variations
// ============================================================
struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };

class Solution {
public:
    // Insert at head — O(1)
    ListNode* insertAtHead(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        return newNode; // New head
    }

    // Insert at tail — O(N)
    ListNode* insertAtTail(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) return newNode;
        ListNode* curr = head;
        while (curr->next) curr = curr->next; // Find tail
        curr->next = newNode;
        return head;
    }

    // Insert at position k (0-indexed) — O(k)
    ListNode* insertAt(ListNode* head, int pos, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 0; i < pos && prev->next; i++) prev = prev->next;
        ListNode* newNode = new ListNode(val);
        newNode->next = prev->next; // Point to successor
        prev->next = newNode;       // Predecessor points to new
        return dummy.next;
    }
};
