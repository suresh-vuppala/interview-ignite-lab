// ============================================================
// Flatten Multilevel DLL
// ============================================================
class Solution{public Node flatten(Node head){
    Node curr=head;
    while(curr!=null){
        if(curr.child!=null){
            Node child=curr.child,tail=child;
            while(tail.next!=null)tail=tail.next;
            tail.next=curr.next;if(curr.next!=null)curr.next.prev=tail;
            curr.next=child;child.prev=curr;curr.child=null;
        }
        curr=curr.next;
    }
    return head;
}}
