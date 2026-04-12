// ============================================================
// Search and Update
// ============================================================
class Solution {
    public boolean search(ListNode head, int target) {
        while (head != null) { if (head.val == target) return true; head = head.next; }
        return false;
    }
    public ListNode update(ListNode head, int oldVal, int newVal) {
        ListNode c = head;
        while (c != null) { if (c.val == oldVal) { c.val = newVal; break; } c = c.next; }
        return head;
    }
}
