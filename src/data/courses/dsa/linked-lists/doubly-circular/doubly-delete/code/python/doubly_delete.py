class Solution:
    def deleteNode(self,head,target):
        if target.prev:target.prev.next=target.next
        else:head=target.next
        if target.next:target.next.prev=target.prev
        return head