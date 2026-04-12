# ============================================================
# Find Nth From End
# ============================================================
class Solution:
    def findNthFromEnd(self, head, n):
        fast = slow = head
        for _ in range(n): fast = fast.next
        while fast: slow, fast = slow.next, fast.next
        return slow
