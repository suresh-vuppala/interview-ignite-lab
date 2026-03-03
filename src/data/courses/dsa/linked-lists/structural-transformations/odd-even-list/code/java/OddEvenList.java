class Node { int data; Node next; Node(int d) { data = d; } }
public class OddEvenList {
    Node oddEven(Node h) { if(h==null) return null; Node o=h,e=h.next,eh=e; while(e!=null&&e.next!=null) { o.next=e.next; o=o.next; e.next=o.next; e=e.next; } o.next=eh; return h; }
    void display(Node h) { while(h!=null) { System.out.print(h.data+" "); h=h.next; } System.out.println(); }
    public static void main(String[] a) { OddEvenList oe=new OddEvenList(); Node h=new Node(1); h.next=new Node(2); h.next.next=new Node(3); h.next.next.next=new Node(4); h.next.next.next.next=new Node(5); oe.display(oe.oddEven(h)); }
}