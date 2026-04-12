class Solution:
    def isCircular(self,head):
        if not head:return False
        curr=head.next
        while curr and curr!=head:curr=curr.next
        return curr==head