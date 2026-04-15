struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Two new lists, concatenate — O(N)
// ============================================================
class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessD(0),geqD(0);ListNode*lt=&lessD,*gt=&geqD;
        while(head){if(head->val<x){lt->next=head;lt=lt->next;}else{gt->next=head;gt=gt->next;}head=head->next;}
        gt->next=nullptr;lt->next=geqD.next;
        return lessD.next;
    }
};

// ============================================================
// Solution 2: Same approach — two dummy heads is already optimal O(N)
// ============================================================
class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0),after(0);ListNode*b=&before,*a=&after;
        for(auto cur=head;cur;cur=cur->next){
            if(cur->val<x){b->next=cur;b=b->next;}else{a->next=cur;a=a->next;}
        }
        a->next=nullptr;b->next=after.next;return before.next;
    }
};
