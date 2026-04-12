# ============================================================
# Reverse Linked List — Recursive
# ============================================================
class Solution:
    def reverseList(self, head):
        if not head or not head.next: return head
        new_head = self.reverseList(head.next)
        head.next.next = head  # Successor points back to me
        head.next = None       # Break forward link
        return new_head
