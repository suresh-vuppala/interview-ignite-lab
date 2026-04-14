struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Copy segment to array, reverse, write back — O(N) Space
// ============================================================
#include <vector>
class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vals; auto c=head;int idx=1;
        while(c){if(idx>=left&&idx<=right)vals.push_back(c->val);c=c->next;idx++;}
        c=head;idx=1;int vi=vals.size()-1;
        while(c){if(idx>=left&&idx<=right){c->val=vals[vi--];}c=c->next;idx++;}return head;
    }
};

// ============================================================
// Solution 2: In-place pointer reversal with dummy — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);dummy.next=head;
        ListNode*prev=&dummy;for(int i=1;i<left;i++)prev=prev->next;
        ListNode*cur=prev->next;
        for(int i=0;i<right-left;i++){
            ListNode*nxt=cur->next;cur->next=nxt->next;nxt->next=prev->next;prev->next=nxt;
        }
        return dummy.next;
    }
};
