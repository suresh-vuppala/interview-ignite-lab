class Solution:
    def deleteVal(self,head,val):
        if not head:return None
        if head.next==head and head.val==val:return None
        curr=head
        while curr.next!=head:
            if curr.next.val==val:curr.next=curr.next.next;return head
            curr=curr.next
        if head.val==val:curr.next=head.next;return head.next
        return head