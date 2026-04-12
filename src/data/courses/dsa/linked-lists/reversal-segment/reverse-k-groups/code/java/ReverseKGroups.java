// ============================================================
// Reverse K Group
// ============================================================
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0); dummy.next = head;
        ListNode groupPrev = dummy;
        while (true) {
            ListNode kth = groupPrev;
            for (int i = 0; i < k; i++) { kth = kth.next; if (kth == null) return dummy.next; }
            ListNode groupNext = kth.next, prev = groupNext, curr = groupPrev.next;
            for (int i = 0; i < k; i++) { ListNode next = curr.next; curr.next = prev; prev = curr; curr = next; }
            ListNode oldHead = groupPrev.next;
            groupPrev.next = prev; groupPrev = oldHead;
        }
    }
}
