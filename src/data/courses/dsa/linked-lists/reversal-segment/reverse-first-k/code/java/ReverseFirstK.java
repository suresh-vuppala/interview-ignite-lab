// ============================================================
// Reverse First K Nodes
// ============================================================
class Solution {
    public ListNode reverseFirstK(ListNode head, int k) {
        if (head == null || k <= 1) return head;
        ListNode prev = null, curr = head, orig = head;
        for (int i = 0; i < k && curr != null; i++) {
            ListNode next = curr.next; curr.next = prev; prev = curr; curr = next;
        }
        orig.next = curr; return prev;
    }
}
