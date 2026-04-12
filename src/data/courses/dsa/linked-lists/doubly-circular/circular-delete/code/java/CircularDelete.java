class Solution{public ListNode deleteVal(ListNode head,int val){
    if(head==null)return null;
    if(head.next==head&&head.val==val)return null;
    ListNode curr=head;
    while(curr.next!=head){if(curr.next.val==val){curr.next=curr.next.next;return head;}curr=curr.next;}
    if(head.val==val){curr.next=head.next;return head.next;}return head;
}}