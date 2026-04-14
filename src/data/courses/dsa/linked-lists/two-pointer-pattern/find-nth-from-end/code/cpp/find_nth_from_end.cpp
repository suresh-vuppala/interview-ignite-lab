struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Count length, then traverse to (len-N) — O(N) two-pass
// ============================================================
class Solution1 {
public:
    ListNode* nthFromEnd(ListNode* head, int n) {
        int len=0; for(auto c=head;c;c=c->next)len++;
        auto c=head; for(int i=0;i<len-n;i++)c=c->next; return c;
    }
};

// ============================================================
// Solution 2: Two pointers with N gap — O(N) one pass
// ============================================================
class Solution2 {
public:
    ListNode* nthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow=head;
        for(int i=0;i<n;i++)fast=fast->next; // Create N gap
        while(fast){slow=slow->next;fast=fast->next;}
        return slow;
    }
};
