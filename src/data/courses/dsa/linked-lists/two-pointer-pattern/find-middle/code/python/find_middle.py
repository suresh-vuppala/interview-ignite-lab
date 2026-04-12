# ============================================================
# Find Middle
# ============================================================
class Solution:
    def findMiddle(self, head):
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        return slow
