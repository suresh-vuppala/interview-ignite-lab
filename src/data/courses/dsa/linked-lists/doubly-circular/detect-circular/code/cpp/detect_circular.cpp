struct ListNode{int val;ListNode*next;ListNode(int v):val(v),next(nullptr){}};
class Solution{public:
    bool isCircular(ListNode*head){
        if(!head)return false;
        ListNode*curr=head->next;
        while(curr&&curr!=head)curr=curr->next;
        return curr==head; // If we loop back to head → circular
    }};