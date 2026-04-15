struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Collect both into array, sort, build list — O(N log N)
// ============================================================
#include <vector>
#include <algorithm>
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int> vals;
        while(l1){vals.push_back(l1->val);l1=l1->next;}
        while(l2){vals.push_back(l2->val);l2=l2->next;}
        sort(vals.begin(),vals.end());
        ListNode dummy(0);ListNode*tail=&dummy;
        for(int v:vals){tail->next=new ListNode(v);tail=tail->next;}
        return dummy.next;
    }
};

// ============================================================
// Solution 2: Two-pointer merge — O(N+M) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);ListNode*tail=&dummy;
        while(l1&&l2){if(l1->val<=l2->val){tail->next=l1;l1=l1->next;}else{tail->next=l2;l2=l2->next;}tail=tail->next;}
        tail->next=l1?l1:l2;
        return dummy.next;
    }
};
