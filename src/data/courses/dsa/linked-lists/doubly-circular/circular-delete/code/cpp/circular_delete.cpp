struct ListNode{int val;ListNode*next;ListNode(int v):val(v),next(nullptr){}};
class Solution{public:
    ListNode*deleteVal(ListNode*head,int val){
        if(!head)return nullptr;
        if(head->next==head&&head->val==val)return nullptr; // Single node
        ListNode*curr=head;
        while(curr->next!=head){
            if(curr->next->val==val){curr->next=curr->next->next;return head;}
            curr=curr->next;
        }
        if(head->val==val){curr->next=head->next;return head->next;} // Delete head
        return head;
    }};