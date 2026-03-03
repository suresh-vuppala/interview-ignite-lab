import java.util.*;
class Node { int data; Node next; Node(int d) { data = d; } }
public class MergeKSorted {
    Node mergeK(Node[] lists) { PriorityQueue<Node> pq=new PriorityQueue<>((a,b)->a.data-b.data); for(Node n:lists) if(n!=null) pq.offer(n); Node d=new Node(0),c=d; while(!pq.isEmpty()) { Node n=pq.poll(); c.next=n; c=c.next; if(n.next!=null) pq.offer(n.next); } return d.next; }
    void display(Node h) { while(h!=null) { System.out.print(h.data+" "); h=h.next; } System.out.println(); }
    public static void main(String[] a) { MergeKSorted m=new MergeKSorted(); Node l1=new Node(1); l1.next=new Node(4); Node l2=new Node(2); l2.next=new Node(3); m.display(m.mergeK(new Node[]{l1,l2})); }
}