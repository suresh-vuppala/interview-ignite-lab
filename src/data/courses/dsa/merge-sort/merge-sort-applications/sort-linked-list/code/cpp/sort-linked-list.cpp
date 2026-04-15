struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Copy to array, sort, write back — O(N log N) Time, O(N) Space
// ============================================================
class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> vals; for(auto c=head;c;c=c->next) vals.push_back(c->val);
        sort(vals.begin(), vals.end());
        auto c=head; for(int v:vals){c->val=v;c=c->next;}
        return head;
    }
};

// ============================================================
// Solution 2: Merge sort on linked list — O(N log N) Time, O(log N) Stack
// ============================================================
class Solution2 {
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode d(0); ListNode*t=&d;
        while(a&&b){if(a->val<=b->val){t->next=a;a=a->next;}else{t->next=b;b=b->next;}t=t->next;}
        t->next=a?a:b; return d.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode*slow=head,*fast=head->next;
        while(fast&&fast->next){slow=slow->next;fast=fast->next->next;}
        ListNode*mid=slow->next; slow->next=nullptr;
        return merge(sortList(head), sortList(mid));
    }
};
