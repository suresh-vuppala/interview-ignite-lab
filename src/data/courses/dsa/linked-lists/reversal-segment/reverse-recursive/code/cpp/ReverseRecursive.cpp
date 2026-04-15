struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Iterative three-pointer — O(N) Time, O(1) Space
// ============================================================
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr,*cur=head;
        while(cur){auto nxt=cur->next;cur->next=prev;prev=cur;cur=nxt;}return prev;
    }
};

// ============================================================
// Solution 2: Recursive — O(N) Time, O(N) Stack
// ============================================================
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head; head->next = nullptr;
        return newHead;
    }
};
