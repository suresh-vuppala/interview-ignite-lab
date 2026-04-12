class Solution{public void reorderList(ListNode head){
    if(head==null||head.next==null)return;
    ListNode slow=head,fast=head;
    while(fast.next!=null&&fast.next.next!=null){slow=slow.next;fast=fast.next.next;}
    ListNode prev=null,curr=slow.next;slow.next=null;
    while(curr!=null){ListNode n=curr.next;curr.next=prev;prev=curr;curr=n;}
    ListNode l1=head,l2=prev;
    while(l2!=null){ListNode n1=l1.next,n2=l2.next;l1.next=l2;l2.next=n1;l1=n1;l2=n2;}
}}