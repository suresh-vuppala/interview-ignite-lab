class Solution{public DNode reverse(DNode head){
    DNode curr=head;
    while(curr!=null){DNode t=curr.prev;curr.prev=curr.next;curr.next=t;head=curr;curr=curr.prev;}
    return head;
}}