# ============================================================
# Reverse Linked List — Iterative
# ============================================================
class Solution:
    def reverseList(self, head):
        prev, curr = None, head
        while curr:
            nxt = curr.next    # Save next
            curr.next = prev   # Reverse
            prev = curr        # Advance prev
            curr = nxt         # Advance curr
        return prev
