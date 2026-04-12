struct DNode{int val;DNode*prev,*next;DNode(int v):val(v),prev(nullptr),next(nullptr){}};
class Solution{public:
    DNode*reverse(DNode*head){
        DNode*curr=head;
        while(curr){
            DNode*temp=curr->prev;curr->prev=curr->next;curr->next=temp;
            head=curr;curr=curr->prev; // Move to next (which is now prev)
        }
        return head;
    }};