struct ListNode{int val;ListNode*next;ListNode(int v):val(v),next(nullptr){}};
class Solution{public:
    ListNode*insert(ListNode*head,int val){
        ListNode*node=new ListNode(val);
        if(!head){node->next=node;return node;} // Single node circular
        ListNode*curr=head;
        while(curr->next!=head)curr=curr->next;
        curr->next=node;node->next=head; // Insert before head (at tail)
        return head;
    }};