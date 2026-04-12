// ============================================================
// Linked List Creation & Traversal
// ============================================================
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    // Create linked list from array
    ListNode* createList(vector<int>& values) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        for (int v : values) {
            tail->next = new ListNode(v);
            tail = tail->next;
        }
        return dummy.next;
    }

    // Traverse and collect values
    vector<int> traverse(ListNode* head) {
        vector<int> result;
        ListNode* curr = head;
        while (curr) {
            result.push_back(curr->val);
            curr = curr->next; // Move to next node
        }
        return result;
    }

    // Get length
    int length(ListNode* head) {
        int count = 0;
        while (head) { count++; head = head->next; }
        return count;
    }
};
