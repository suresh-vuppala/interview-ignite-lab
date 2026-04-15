struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Merge pairs sequentially — O(N*K)
// ============================================================
class Solution1 {
    ListNode* merge2(ListNode*a,ListNode*b){ListNode d(0);ListNode*t=&d;while(a&&b){if(a->val<=b->val){t->next=a;a=a->next;}else{t->next=b;b=b->next;}t=t->next;}t->next=a?a:b;return d.next;}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* r=nullptr; for(auto l:lists) r=merge2(r,l); return r;
    }
};

// ============================================================
// Solution 2: Min-heap — O(N log K)
// ============================================================
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode*a,ListNode*b){return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        for(auto l:lists) if(l) pq.push(l);
        ListNode d(0);ListNode*t=&d;
        while(!pq.empty()){auto n=pq.top();pq.pop();t->next=n;t=t->next;if(n->next)pq.push(n->next);}
        return d.next;
    }
};
