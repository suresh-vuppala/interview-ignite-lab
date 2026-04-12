# ============================================================
# Linked List Creation & Traversal
# ============================================================
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def createList(self, values):
        dummy = ListNode(0)
        tail = dummy
        for v in values:
            tail.next = ListNode(v)
            tail = tail.next
        return dummy.next

    def traverse(self, head):
        result = []
        while head:
            result.append(head.val)
            head = head.next
        return result
