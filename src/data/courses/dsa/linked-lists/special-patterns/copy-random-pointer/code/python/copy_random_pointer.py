# ============================================================
# Copy Random Pointer
# ============================================================
class Solution:
    def copyRandomList(self,head):
        if not head:return None
        # Interleave
        curr=head
        while curr:clone=Node(curr.val,curr.next);curr.next=clone;curr=clone.next
        # Set random
        curr=head
        while curr:
            if curr.random:curr.next.random=curr.random.next
            curr=curr.next.next
        # Separate
        clone_head=head.next;curr=head
        while curr:clone=curr.next;curr.next=clone.next;curr=curr.next;
            if curr:clone.next=curr.next
        return clone_head
