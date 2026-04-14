struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Count + traverse — O(N) two-pass
// ============================================================
class Solution1 {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0; for(auto c=head;c;c=c->next)n++;
        auto c=head; for(int i=0;i<n/2;i++)c=c->next; return c;
    }
};

// ============================================================
// Solution 2: Slow/Fast — O(N) one pass, O(1) space
// ============================================================
class Solution2 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *s=head,*f=head;
        while(f&&f->next){s=s->next;f=f->next->next;}
        return s;
    }
};
