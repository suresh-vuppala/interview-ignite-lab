struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Collect K nodes to array, reverse, reconnect — O(N) Space
// ============================================================
class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Count length
        int len=0;for(auto c=head;c;c=c->next)len++;
        ListNode dummy(0);dummy.next=head;ListNode*prev=&dummy;
        while(len>=k){
            ListNode*cur=prev->next;
            for(int i=1;i<k;i++){ListNode*nxt=cur->next;cur->next=nxt->next;nxt->next=prev->next;prev->next=nxt;}
            prev=cur;len-=k;
        }
        return dummy.next;
    }
};

// ============================================================
// Solution 2: Recursive — reverse K, recurse on rest — O(N) Time, O(N/K) Stack
// ============================================================
class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*cur=head;int count=0;
        while(cur&&count<k){cur=cur->next;count++;}
        if(count<k) return head; // Not enough nodes
        ListNode*prev=nullptr;cur=head;
        for(int i=0;i<k;i++){auto nxt=cur->next;cur->next=prev;prev=cur;cur=nxt;}
        head->next=reverseKGroup(cur,k); // Recurse on remaining
        return prev;
    }
};
