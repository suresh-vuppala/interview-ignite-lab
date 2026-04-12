// ============================================================
// Copy Random Pointer
// ============================================================
class Solution{public Node copyRandomList(Node head){
    if(head==null)return null;
    Node curr=head;
    while(curr!=null){Node c=new Node(curr.val);c.next=curr.next;curr.next=c;curr=c.next;}
    curr=head;while(curr!=null){if(curr.random!=null)curr.next.random=curr.random.next;curr=curr.next.next;}
    Node clone=head.next;curr=head;
    while(curr!=null){Node c=curr.next;curr.next=c.next;curr=curr.next;if(curr!=null)c.next=curr.next;}
    return clone;
}}
