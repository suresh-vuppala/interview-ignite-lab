# ============================================================
# Remove Nth From End
# ============================================================
class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0); dummy.next = head
        fast = slow = dummy
        for _ in range(n + 1): fast = fast.next
        while fast: slow, fast = slow.next, fast.next
        slow.next = slow.next.next
        return dummy.next
