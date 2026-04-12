struct DNode{int val;DNode*prev,*next;DNode(int v):val(v),prev(nullptr),next(nullptr){}};
class Solution{public:
    DNode*insertHead(DNode*head,int val){DNode*n=new DNode(val);n->next=head;if(head)head->prev=n;return n;}
    DNode*insertTail(DNode*head,int val){DNode*n=new DNode(val);if(!head)return n;DNode*c=head;while(c->next)c=c->next;c->next=n;n->prev=c;return head;}
    DNode*insertAfter(DNode*node,int val){DNode*n=new DNode(val);n->next=node->next;n->prev=node;if(node->next)node->next->prev=n;node->next=n;return n;}
};