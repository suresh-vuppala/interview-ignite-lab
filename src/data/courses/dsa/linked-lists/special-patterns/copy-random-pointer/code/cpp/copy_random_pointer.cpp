struct Node { int val; Node *next, *random; Node(int v):val(v),next(nullptr),random(nullptr){} };
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: HashMap clone — O(N) Time+Space
// ============================================================
class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        for(auto c=head;c;c=c->next)m[c]=new Node(c->val);
        for(auto c=head;c;c=c->next){m[c]->next=m[c->next];m[c]->random=m[c->random];}
        return m[head];
    }
};

// ============================================================
// Solution 2: Interleave — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        // Step 1: Interleave copies
        for(auto c=head;c;){auto copy=new Node(c->val);copy->next=c->next;c->next=copy;c=copy->next;}
        // Step 2: Set random pointers
        for(auto c=head;c;c=c->next->next)if(c->random)c->next->random=c->random->next;
        // Step 3: Separate lists
        Node*newHead=head->next;
        for(auto c=head;c;){auto copy=c->next;c->next=copy->next;copy->next=copy->next?copy->next->next:nullptr;c=c->next;}
        return newHead;
    }
};
