# ============================================================
# Insertion Variations
# ============================================================
class Solution:
    def insertAtHead(self, head, val):
        node = ListNode(val); node.next = head; return node

    def insertAtTail(self, head, val):
        node = ListNode(val)
        if not head: return node
        curr = head
        while curr.next: curr = curr.next
        curr.next = node; return head

    def insertAt(self, head, pos, val):
        dummy = ListNode(0); dummy.next = head; prev = dummy
        for _ in range(pos):
            if not prev.next: break
            prev = prev.next
        node = ListNode(val); node.next = prev.next; prev.next = node
        return dummy.next
