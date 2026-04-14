struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Copy to array, build reversed list — O(N) Space
// ============================================================
#include <vector>
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> vals; for(auto c=head;c;c=c->next)vals.push_back(c->val);
        ListNode*cur=head; for(int i=vals.size()-1;i>=0;i--){cur->val=vals[i];cur=cur->next;}
        return head;
    }
};

// ============================================================
// Solution 2: Three-pointer in-place — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr, *cur=head;
        while(cur){ListNode*nxt=cur->next;cur->next=prev;prev=cur;cur=nxt;}
        return prev;
    }
};
