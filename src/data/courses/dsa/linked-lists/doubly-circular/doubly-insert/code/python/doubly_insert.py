class Solution:
    def insertHead(self,head,val):n=DNode(val);n.next=head;
        if head:head.prev=n
        return n