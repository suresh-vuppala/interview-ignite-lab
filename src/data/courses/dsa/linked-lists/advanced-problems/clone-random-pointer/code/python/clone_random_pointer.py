# ============================================================
# Clone Random Pointer
# ============================================================
class Solution:
    def copyRandomList(self, head):
        if not head: return None
        clone_map = {}
        curr = head
        while curr:
            clone_map[curr] = Node(curr.val)
            curr = curr.next
        curr = head
        while curr:
            clone_map[curr].next = clone_map.get(curr.next)
            clone_map[curr].random = clone_map.get(curr.random)
            curr = curr.next
        return clone_map[head]
