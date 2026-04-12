class Solution:
    def insert(self,head,val):
        node=ListNode(val)
        if not head:node.next=node;return node
        curr=head
        while curr.next!=head:curr=curr.next
        curr.next=node;node.next=head
        return head