# ============================================================
# Search and Update
# ============================================================
class Solution:
    def search(self, head, target):
        while head:
            if head.val == target: return True
            head = head.next
        return False

    def update(self, head, old_val, new_val):
        curr = head
        while curr:
            if curr.val == old_val: curr.val = new_val; break
            curr = curr.next
        return head
