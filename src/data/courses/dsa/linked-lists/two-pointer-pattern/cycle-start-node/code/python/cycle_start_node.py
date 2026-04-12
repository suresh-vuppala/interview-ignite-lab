# ============================================================
# Cycle Start Node
# ============================================================
class Solution:
    def detectCycle(self, head):
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                ptr = head
                while ptr != slow: ptr, slow = ptr.next, slow.next
                return ptr
        return None
