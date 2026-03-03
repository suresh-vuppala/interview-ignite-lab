class Node:
    def __init__(self, k, v): self.key=k; self.val=v; self.prev=None; self.next=None
class LRUCache:
    def __init__(self, capacity): self.map={}; self.cap=capacity; self.head=Node(0,0); self.tail=Node(0,0); self.head.next=self.tail; self.tail.prev=self.head
    def remove(self, n): n.prev.next=n.next; n.next.prev=n.prev
    def insert(self, n): n.next=self.head.next; n.prev=self.head; self.head.next.prev=n; self.head.next=n
    def get(self, key):
        if key not in self.map: return -1
        n=self.map[key]; self.remove(n); self.insert(n); return n.val
    def put(self, key, val):
        if key in self.map: self.remove(self.map[key])
        n=Node(key,val); self.map[key]=n; self.insert(n)
        if len(self.map)>self.cap: lru=self.tail.prev; self.remove(lru); del self.map[lru.key]
if __name__=="__main__": c=LRUCache(2); c.put(1,1); c.put(2,2); print(c.get(1)); c.put(3,3); print(c.get(2))