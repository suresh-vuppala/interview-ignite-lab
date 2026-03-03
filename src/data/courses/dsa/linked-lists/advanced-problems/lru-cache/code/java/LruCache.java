import java.util.*;
class Node { int key, val; Node prev, next; Node(int k, int v) { key=k; val=v; }}
public class LruCache {
    Map<Integer,Node> map; Node head, tail; int cap;
    public LruCache(int capacity) { map=new HashMap<>(); cap=capacity; head=new Node(0,0); tail=new Node(0,0); head.next=tail; tail.prev=head; }
    void remove(Node n) { n.prev.next=n.next; n.next.prev=n.prev; }
    void insert(Node n) { n.next=head.next; n.prev=head; head.next.prev=n; head.next=n; }
    public int get(int key) { if(!map.containsKey(key)) return -1; Node n=map.get(key); remove(n); insert(n); return n.val; }
    public void put(int key, int val) { if(map.containsKey(key)) remove(map.get(key)); Node n=new Node(key,val); map.put(key,n); insert(n); if(map.size()>cap) { Node lru=tail.prev; remove(lru); map.remove(lru.key); }}
    public static void main(String[] a) { LruCache c=new LruCache(2); c.put(1,1); c.put(2,2); System.out.println(c.get(1)); c.put(3,3); System.out.println(c.get(2)); }
}