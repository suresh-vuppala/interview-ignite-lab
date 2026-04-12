# ============================================================
# Reverse K Group
# ============================================================
class Solution:
    def reverseKGroup(self, head, k):
        dummy = ListNode(0); dummy.next = head
        group_prev = dummy
        while True:
            kth = group_prev
            for _ in range(k):
                kth = kth.next
                if not kth: return dummy.next
            group_next = kth.next
            prev, curr = group_next, group_prev.next
            for _ in range(k):
                nxt = curr.next; curr.next = prev; prev = curr; curr = nxt
            old_head = group_prev.next
            group_prev.next = prev
            group_prev = old_head
