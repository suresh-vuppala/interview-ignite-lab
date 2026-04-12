class Solution:
    def reverse(self,head):
        curr=head
        while curr:
            curr.prev,curr.next=curr.next,curr.prev
            head=curr;curr=curr.prev
        return head