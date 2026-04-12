# ============================================================
# Flatten Multilevel DLL
# ============================================================
class Solution:
    def flatten(self,head):
        curr=head
        while curr:
            if curr.child:
                child=curr.child;tail=child
                while tail.next:tail=tail.next
                tail.next=curr.next
                if curr.next:curr.next.prev=tail
                curr.next=child;child.prev=curr;curr.child=None
            curr=curr.next
        return head
