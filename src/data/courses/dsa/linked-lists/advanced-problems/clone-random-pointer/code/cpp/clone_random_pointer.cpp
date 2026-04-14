struct RNode { int val; RNode *next, *random; RNode(int v):val(v),next(nullptr),random(nullptr){} };
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: HashMap — O(N) Time, O(N) Space
// ============================================================
class Solution1 {
public:
    RNode* clone(RNode* head) {
        unordered_map<RNode*,RNode*> m;
        for(auto c=head;c;c=c->next)m[c]=new RNode(c->val);
        for(auto c=head;c;c=c->next){m[c]->next=m[c->next];m[c]->random=m[c->random];}
        return m[head];
    }
};

// ============================================================
// Solution 2: Interleave technique — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    RNode* clone(RNode* head) {
        if(!head)return nullptr;
        for(auto c=head;c;){auto cp=new RNode(c->val);cp->next=c->next;c->next=cp;c=cp->next;}
        for(auto c=head;c;c=c->next->next)if(c->random)c->next->random=c->random->next;
        RNode*nh=head->next;for(auto c=head;c;){auto cp=c->next;c->next=cp->next;cp->next=cp->next?cp->next->next:nullptr;c=c->next;}
        return nh;
    }
};
