struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Count length, find target — O(N) two-pass
// ============================================================
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;for(auto c=head;c;c=c->next)len++;
        if(n==len)return head->next;
        auto c=head;for(int i=0;i<len-n-1;i++)c=c->next;
        c->next=c->next->next; return head;
    }
};

// ============================================================
// Solution 2: Two pointers + dummy — O(N) one pass
// ============================================================
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0); dummy.next=head;
        ListNode *fast=&dummy,*slow=&dummy;
        for(int i=0;i<=n;i++)fast=fast->next;
        while(fast){slow=slow->next;fast=fast->next;}
        slow->next=slow->next->next;
        return dummy.next;
    }
};
