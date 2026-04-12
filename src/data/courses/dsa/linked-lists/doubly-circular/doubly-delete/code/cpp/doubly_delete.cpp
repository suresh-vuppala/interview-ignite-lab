struct DNode{int val;DNode*prev,*next;DNode(int v):val(v),prev(nullptr),next(nullptr){}};
class Solution{public:
    DNode*deleteNode(DNode*head,DNode*target){
        if(target->prev)target->prev->next=target->next;else head=target->next;
        if(target->next)target->next->prev=target->prev;
        return head;
    }};