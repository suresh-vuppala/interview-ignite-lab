# ============================================================
# Reverse First K Nodes
# ============================================================
class Solution:
    def reverseFirstK(self, head, k):
        if not head or k <= 1: return head
        prev, curr, orig = None, head, head
        for _ in range(k):
            if not curr: break
            nxt = curr.next; curr.next = prev; prev = curr; curr = nxt
        orig.next = curr  # Connect to remaining
        return prev
