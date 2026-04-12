# ============================================================
# Merge K Sorted Lists
# ============================================================
import heapq
class Solution:
    def mergeKLists(self, lists):
        heap = []
        for i, l in enumerate(lists):
            if l: heapq.heappush(heap, (l.val, i, l))
        dummy = tail = ListNode(0)
        while heap:
            val, i, node = heapq.heappop(heap)
            tail.next = node; tail = tail.next
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))
        return dummy.next
