# ============================================================
# Sort List (Merge Sort)
# ============================================================
class Solution:
    def sortList(self, head):
        if not head or not head.next: return head
        slow, fast = head, head.next
        while fast and fast.next: slow, fast = slow.next, fast.next.next
        mid = slow.next; slow.next = None
        return self.merge(self.sortList(head), self.sortList(mid))

    def merge(self, l1, l2):
        dummy = tail = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val: tail.next = l1; l1 = l1.next
            else: tail.next = l2; l2 = l2.next
            tail = tail.next
        tail.next = l1 or l2
        return dummy.next
