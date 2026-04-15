struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Array-based — store values, simulate list — O(N) Time+Space
// ============================================================
class Solution1 {
public:
    vector<int> traverse(ListNode* head) {
        vector<int> result;
        while (head) { result.push_back(head->val); head = head->next; }
        return result;  // Can also build list from array
    }
    ListNode* createFromArray(vector<int>& arr) {
        ListNode dummy(0); ListNode* tail = &dummy;
        for (int v : arr) { tail->next = new ListNode(v); tail = tail->next; }
        return dummy.next;
    }
};

// ============================================================
// Solution 2: Direct pointer manipulation — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    void traverse(ListNode* head) { for (ListNode* cur=head; cur; cur=cur->next) /* process cur->val */; }
    ListNode* append(ListNode* head, int val) {
        ListNode* node = new ListNode(val);
        if (!head) return node;
        ListNode* cur = head; while (cur->next) cur = cur->next;
        cur->next = node; return head;
    }
};
