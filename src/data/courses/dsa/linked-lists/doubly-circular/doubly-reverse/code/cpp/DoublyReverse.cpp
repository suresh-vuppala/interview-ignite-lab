struct DNode { int val; DNode *prev, *next; DNode(int v):val(v),prev(nullptr),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Collect to array, rebuild reversed — O(N) Space
// ============================================================
#include <vector>
class Solution1 {
public:
    DNode* reverse(DNode* head) {
        vector<int> vals;for(auto c=head;c;c=c->next)vals.push_back(c->val);
        auto c=head;for(int i=vals.size()-1;i>=0;i--){c->val=vals[i];c=c->next;}return head;
    }
};

// ============================================================
// Solution 2: Swap prev/next pointers — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    DNode* reverse(DNode* head) {
        DNode*cur=head;while(cur){
            DNode*tmp=cur->prev;cur->prev=cur->next;cur->next=tmp;
            if(!cur->prev)head=cur; // New head is last node processed
            cur=cur->prev; // Move forward (prev is now next)
        }
        return head;
    }
};
