class Solution{public DNode deleteNode(DNode head,DNode target){
    if(target.prev!=null)target.prev.next=target.next;else head=target.next;
    if(target.next!=null)target.next.prev=target.prev;return head;
}}