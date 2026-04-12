# ============================================================
# LRU Cache
# ============================================================
class Node:
    def __init__(self, key=0, val=0):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:
    def __init__(self, capacity):
        self.cap = capacity
        self.map = {}
        self.head, self.tail = Node(), Node()
        self.head.next, self.tail.prev = self.tail, self.head

    def _add(self, node):
        node.next, node.prev = self.head.next, self.head
        self.head.next.prev = node; self.head.next = node

    def _remove(self, node):
        node.prev.next, node.next.prev = node.next, node.prev

    def get(self, key):
        if key not in self.map: return -1
        node = self.map[key]
        self._remove(node); self._add(node)
        return node.val

    def put(self, key, value):
        if key in self.map:
            self._remove(self.map[key])
        node = Node(key, value)
        self._add(node); self.map[key] = node
        if len(self.map) > self.cap:
            lru = self.tail.prev
            self._remove(lru); del self.map[lru.key]
