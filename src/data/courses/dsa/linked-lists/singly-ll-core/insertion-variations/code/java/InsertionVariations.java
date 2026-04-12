// ============================================================
// Insertion Variations
// ============================================================
class Solution {
    public ListNode insertAtHead(ListNode head, int val) {
        ListNode n = new ListNode(val); n.next = head; return n;
    }
    public ListNode insertAtTail(ListNode head, int val) {
        ListNode n = new ListNode(val);
        if (head == null) return n;
        ListNode c = head; while (c.next != null) c = c.next;
        c.next = n; return head;
    }
    public ListNode insertAt(ListNode head, int pos, int val) {
        ListNode dummy = new ListNode(0); dummy.next = head;
        ListNode prev = dummy;
        for (int i = 0; i < pos && prev.next != null; i++) prev = prev.next;
        ListNode n = new ListNode(val); n.next = prev.next; prev.next = n;
        return dummy.next;
    }
}
