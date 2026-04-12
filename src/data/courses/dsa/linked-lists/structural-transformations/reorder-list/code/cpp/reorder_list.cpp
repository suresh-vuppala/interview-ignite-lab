struct ListNode{int val;ListNode*next;ListNode(int v):val(v),next(nullptr){}};
class Solution{public:
    void reorderList(ListNode*head){
        if(!head||!head->next)return;
        ListNode*slow=head,*fast=head;
        while(fast->next&&fast->next->next){slow=slow->next;fast=fast->next->next;}
        ListNode*prev=nullptr,*curr=slow->next;slow->next=nullptr;
        while(curr){ListNode*n=curr->next;curr->next=prev;prev=curr;curr=n;}
        ListNode*l1=head,*l2=prev;
        while(l2){ListNode*n1=l1->next,*n2=l2->next;l1->next=l2;l2->next=n1;l1=n1;l2=n2;}
    }};