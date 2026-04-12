# ============================================================
# Deletion Variations
# ============================================================
class Solution:
    def deleteHead(self, head): return head.next if head else None
    def deleteTail(self, head):
        if not head or not head.next: return None
        curr = head
        while curr.next.next: curr = curr.next
        curr.next = None; return head
    def deleteValue(self, head, val):
        dummy = ListNode(0); dummy.next = head; prev = dummy
        while prev.next:
            if prev.next.val == val: prev.next = prev.next.next; break
            prev = prev.next
        return dummy.next
