# ============================================================
# Palindrome Linked List
# ============================================================
class Solution:
    def isPalindrome(self, head) -> bool:
        # Find middle
        slow = fast = head
        while fast.next and fast.next.next: slow, fast = slow.next, fast.next.next
        # Reverse second half
        prev, curr = None, slow.next
        while curr: nxt = curr.next; curr.next = prev; prev = curr; curr = nxt
        # Compare
        p1, p2 = head, prev
        while p2:
            if p1.val != p2.val: return False
            p1, p2 = p1.next, p2.next
        return True
