// ============================================================
// Palindrome Linked List
// ============================================================
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        ListNode slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) { slow = slow.next; fast = fast.next.next; }
        ListNode rev = reverse(slow.next);
        ListNode p1 = head, p2 = rev;
        while (p2 != null) { if (p1.val != p2.val) return false; p1 = p1.next; p2 = p2.next; }
        return true;
    }
    ListNode reverse(ListNode h) { ListNode p = null, c = h; while (c != null) { ListNode n = c.next; c.next = p; p = c; c = n; } return p; }
}
