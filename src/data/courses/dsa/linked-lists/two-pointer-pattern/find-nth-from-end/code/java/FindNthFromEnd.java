// ============================================================
// Find Nth From End
// ============================================================
class Solution {
    public ListNode findNthFromEnd(ListNode head, int n) {
        ListNode fast = head, slow = head;
        for (int i = 0; i < n; i++) fast = fast.next;
        while (fast != null) { slow = slow.next; fast = fast.next; }
        return slow;
    }
}
