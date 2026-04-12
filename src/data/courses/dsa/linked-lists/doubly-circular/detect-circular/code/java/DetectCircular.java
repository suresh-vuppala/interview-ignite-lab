class Solution{public boolean isCircular(ListNode head){
    if(head==null)return false;
    ListNode curr=head.next;
    while(curr!=null&&curr!=head)curr=curr.next;
    return curr==head;
}}