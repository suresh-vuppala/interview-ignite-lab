struct DNode { int val; DNode *prev, *next; DNode(int v):val(v),prev(nullptr),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Traverse to position, insert — O(N)
// ============================================================
class Solution1 {
public:
    DNode* insertHead(DNode* head, int val) {
        DNode*n=new DNode(val);n->next=head;if(head)head->prev=n;return n;
    }
    DNode* insertTail(DNode* head, int val) {
        DNode*n=new DNode(val);if(!head)return n;
        DNode*c=head;while(c->next)c=c->next;c->next=n;n->prev=c;return head;
    }
};

// ============================================================
// Solution 2: With tail pointer for O(1) tail insert
// ============================================================
class Solution2 {
    DNode *head=nullptr, *tail=nullptr;
public:
    void insertHead(int val) { DNode*n=new DNode(val);n->next=head;if(head)head->prev=n;head=n;if(!tail)tail=n; }
    void insertTail(int val) { DNode*n=new DNode(val);n->prev=tail;if(tail)tail->next=n;tail=n;if(!head)head=n; }
    DNode* getHead() { return head; }
};
