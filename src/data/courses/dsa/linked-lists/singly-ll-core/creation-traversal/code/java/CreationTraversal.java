// ============================================================
// Linked List Creation & Traversal
// ============================================================
import java.util.*;

class ListNode { int val; ListNode next; ListNode(int v) { val = v; } }

class Solution {
    public ListNode createList(int[] values) {
        ListNode dummy = new ListNode(0), tail = dummy;
        for (int v : values) { tail.next = new ListNode(v); tail = tail.next; }
        return dummy.next;
    }

    public List<Integer> traverse(ListNode head) {
        List<Integer> result = new ArrayList<>();
        while (head != null) { result.add(head.val); head = head.next; }
        return result;
    }
}
