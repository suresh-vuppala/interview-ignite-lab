// ============================================================
// Deletion Variations
// ============================================================
class Solution {
    public ListNode deleteHead(ListNode head) { return head != null ? head.next : null; }
    public ListNode deleteTail(ListNode head) {
        if (head==null||head.next==null) return null;
        ListNode c = head; while (c.next.next!=null) c=c.next; c.next=null; return head;
    }
    public ListNode deleteValue(ListNode head, int val) {
        ListNode dummy = new ListNode(0); dummy.next = head; ListNode prev = dummy;
        while (prev.next!=null) { if (prev.next.val==val) { prev.next=prev.next.next; break; } prev=prev.next; }
        return dummy.next;
    }
}
