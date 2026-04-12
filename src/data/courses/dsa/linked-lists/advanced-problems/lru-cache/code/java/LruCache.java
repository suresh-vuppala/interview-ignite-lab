// ============================================================
// LRU Cache
// ============================================================
import java.util.*;
class LRUCache {
    class Node { int key, val; Node prev, next;
        Node(int k, int v) { key=k; val=v; } }
    int capacity; Map<Integer,Node> map = new HashMap<>();
    Node head = new Node(0,0), tail = new Node(0,0);
    public LRUCache(int cap) { capacity = cap; head.next = tail; tail.prev = head; }
    void add(Node n) { n.next=head.next; n.prev=head; head.next.prev=n; head.next=n; }
    void remove(Node n) { n.prev.next=n.next; n.next.prev=n.prev; }
    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        Node n = map.get(key); remove(n); add(n); return n.val;
    }
    public void put(int key, int val) {
        if (map.containsKey(key)) { Node n=map.get(key); n.val=val; remove(n); add(n); }
        else { Node n=new Node(key,val); map.put(key,n); add(n);
            if (map.size()>capacity) { Node lru=tail.prev; remove(lru); map.remove(lru.key); } }
    }
}
