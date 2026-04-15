struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Copy K values to array, reverse, write back — O(K) Space
// ============================================================
#include <vector>
class Solution1 {
public:
    ListNode* reverseFirstK(ListNode* head, int k) {
        vector<int> vals; auto c=head; for(int i=0;i<k&&c;i++){vals.push_back(c->val);c=c->next;}
        c=head; for(int i=vals.size()-1;i>=0;i--){c->val=vals[i];c=c->next;} return head;
    }
};

// ============================================================
// Solution 2: In-place pointer reversal — O(K) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* reverseFirstK(ListNode* head, int k) {
        ListNode*prev=nullptr,*cur=head;
        for(int i=0;i<k&&cur;i++){auto nxt=cur->next;cur->next=prev;prev=cur;cur=nxt;}
        head->next=cur; // Connect tail of reversed part to rest
        return prev;
    }
};
