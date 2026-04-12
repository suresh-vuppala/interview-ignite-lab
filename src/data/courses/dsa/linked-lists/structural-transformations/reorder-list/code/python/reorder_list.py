class Solution:
    def reorderList(self,head):
        if not head or not head.next:return
        slow,fast=head,head
        while fast.next and fast.next.next:slow,fast=slow.next,fast.next.next
        prev,curr=None,slow.next;slow.next=None
        while curr:nxt=curr.next;curr.next=prev;prev=curr;curr=nxt
        l1,l2=head,prev
        while l2:n1,n2=l1.next,l2.next;l1.next=l2;l2.next=n1;l1=n1;l2=n2