struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Count then traverse — O(N) two-pass
// ============================================================
class Solution1 {
public:
    ListNode* findMiddle(ListNode* head) {
        int len=0; ListNode*cur=head; while(cur){len++;cur=cur->next;}
        cur=head; for(int i=0;i<len/2;i++)cur=cur->next;
        return cur;
    }
};

// ============================================================
// Solution 2: Slow/Fast pointers — O(N) single pass
// ============================================================
class Solution2 {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast&&fast->next){slow=slow->next;fast=fast->next->next;}
        return slow;  // One pass, O(1) space!
    }
};
